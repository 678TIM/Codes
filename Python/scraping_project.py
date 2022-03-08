import requests
from bs4 import BeautifulSoup
import csv
from time import sleep
from random import choice

all_quotes = []
base_url = "https://quotes.toscrape.com"
url = "/page/1"

while url:
    response = requests.get(base_url + url)
    soup = BeautifulSoup(response.text, "html.parser")
    quotes = soup.find_all(class_ = "quote")

    print("Now Scraping: " + base_url + url + "...")
    for quote in quotes:
        text = quote.find(class_ = "text").get_text()
        author = quote.find(class_ = "author").get_text()
        all_quotes.append({
            "text": text,
            "author": author,
            "bio-link": quote.find("a")["href"]
            })
    next_button = soup.find(class_ = "next")
    url = next_button.find("a")["href"] if next_button else None
    # sleep(2)

# MAIN PROGRAM
play_again = "y"
while play_again == "y" or play_again == "yes":
    num_guesses = 4
    guess = ""
    to_guess = choice(all_quotes)
    print("Here's a quote: ")
    print(to_guess["text"])
    # print(to_guess["author"])
    while guess.upper() != to_guess["author"].upper() and num_guesses > 0:
        guess = input("Who said this quote? {} guesses remaining. ".format(num_guesses))
        if guess == to_guess["author"]:
            break
        num_guesses -= 1
        if num_guesses == 3:
            res = requests.get(base_url + to_guess["bio-link"])
            soup = BeautifulSoup(res.text, "html.parser")
            birth_date = soup.find(class_ = "author-born-date").get_text()
            birthplace = soup.find(class_ = "author-born-location").get_text()
            print("Hint #1: The author was born on {} {}.".format(birth_date, birthplace))
        elif num_guesses == 2:
            print("Hint #2: The author's first name starts with {}".format(to_guess["author"][0]))
        elif num_guesses == 1:
            LN = to_guess["author"].split()
            LN = LN[-1][0]
            print("Hint #3: The author's last name starts with {}".format(LN))

    if num_guesses > 0:
        print("YOU WIN! :D")
    else:
        print("BETTER LUCK NEXT TIME! :( The author is {}".format(to_guess["author"]))
    
    play_again = input("Do you wanna guess another quote? (y/n) ").lower()

    while play_again not in ["y", "yes", "n", "no"]:
        play_again = input("Do you wanna guess another quote? (y/n) ").lower()
        
    if play_again in ("no", "n"):
        print("See you next time! :D")
    else:
        print("ANOTHA ONE! XD")