#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int anagram(char word1[101], char word2[101]) {
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int word1count[26] = {0};
    int word2count[26] = {0};
    for (int i=0; i < 26; i++) {
        for (int j=0; j < strlen(word1); j++) {
            if (word1[j] == letters[i]) {
                word1count[i]++; 
            }
        }
        for (int j=0; j < strlen(word2); j++) {
            if (word2[j] == letters[i]) {
                word2count[i]++;
            }
        }
    }
    int equal = 1;
    for (int x=0; x < 26; x++) {
        if (word1count[x] != word2count[x]) {
            equal = 0;
            break;
        }
    }
    return equal;
}

int main() {
    char word1[101];
    char word2[101];
    scanf("%[^\n]%*c", word1);
    scanf("%[^\n]%*c", word2);
    for (int i = 0; i < strlen(word1); i++) {
        word1[i] = tolower(word1[i]); // tolower() takes a character not a string
    }
    for (int i = 0; i < strlen(word2); i++) {
        word2[i] = tolower(word2[i]);
    }
    int result;
    result = anagram(word1, word2);
    if (result) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}