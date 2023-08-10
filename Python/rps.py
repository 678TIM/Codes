import tkinter as tk
from tkinter import simpledialog, messagebox

def play_game():
    p1_score = 0
    p2_score = 0
    
    player_1 = simpledialog.askstring("Player 1", "Please enter your name:")
    p1_moves = simpledialog.askstring("Player 1", f"Hello, {player_1}! Please enter at least 10 moves (R,P,S):").upper()
    while len(p1_moves) < 10:
        p1_moves = simpledialog.askstring("Player 1", f"Hello, {player_1}! Please enter at least 10 moves (R,P,S):").upper()
    
    player_2 = simpledialog.askstring("Player 2", "Please enter your name:")
    p2_moves = simpledialog.askstring("Player 2", f"Hello, {player_2}! Please enter at least 10 moves (R,P,S):").upper()
    while len(p2_moves) < 10:
        p2_moves = simpledialog.askstring("Player 2", f"Hello, {player_2}! Please enter at least 10 moves (R,P,S):").upper()
    
    max_rounds = min(len(p1_moves), len(p2_moves))
    
    result_text_widget.config(state=tk.NORMAL)  # Enable editing the widget
    result_text_widget.delete('1.0', tk.END)    # Clear existing content
    result_text_widget.insert(tk.END, f"The player with the most points after {max_rounds} rounds wins!\n\n")
    
    for i in range(max_rounds):
        round_result = f"ROUND {i+1} RESULTS\n"
        round_result += f"{player_1}: {p1_moves[i]}\n"
        round_result += f"{player_2}: {p2_moves[i]}\n"
        
        if (p1_moves[i] == "R" and p2_moves[i] == "S") or (p1_moves[i] == "S" and p2_moves[i] == "P") or (p1_moves[i] == "P" and p2_moves[i] == "R"):
            p1_score += 1
        elif (p2_moves[i] == "R" and p1_moves[i] == "S") or (p2_moves[i] == "S" and p1_moves[i] == "P") or (p2_moves[i] == "P" and p1_moves[i] == "R"):
            p2_score += 1
        
        round_result += f"SCORE: {player_1} {p1_score} - {p2_score} {player_2}\n"
        round_result += "-" * (len(player_1) + len(player_2) * 2) + "\n"
        
        result_text_widget.insert(tk.END, round_result)
    
    if p1_score > p2_score:
        result_text_widget.insert(tk.END, f"\n{player_1} is the winner!\n")
    elif p1_score < p2_score:
        result_text_widget.insert(tk.END, f"\n{player_2} is the winner!\n")
    else:
        result_text_widget.insert(tk.END, "\nIt's a tie!\n")
    
    result_text_widget.config(state=tk.DISABLED)  # Disable editing the widget

# Create the main window
root = tk.Tk()
root.title("Rock-Paper-Scissors Game")

# Create and place widgets
play_button = tk.Button(root, text="Play Game", command=play_game)
play_button.pack(pady=10)

result_text_widget = tk.Text(root, wrap=tk.WORD, state=tk.DISABLED)  # Initially disable editing
result_text_widget.pack()

root.mainloop()
