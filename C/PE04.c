#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* A Star Wars name has 2 components: the first name and the last name. 
    To generate the first name, you are to combine the first three letters 
    of the first name of the person with the last two letters of his last name.
    To generate the last name, you get the first three letters of 
    the hometown, and append to it the whole middle name of the user. */

int main() {
    char first_name[101];
    char middle_name[101];
    char surname[101];
    char hometown[101];
    scanf("%[^\n]%*c", first_name);
    scanf("%[^\n]%*c", middle_name);
    scanf("%[^\n]%*c", surname);
    scanf("%[^\n]%*c", hometown);

    /* FILTER first_name */
    char strip_FN[101] = "";
    int up = 1;
    int j = 0;
    for (int i=0; i < strlen(first_name); i++) {
        if (isalpha(first_name[i])) {
            if (up) {
                char upped = toupper(first_name[i]);
                strip_FN[j] = upped;
                up = 0;
            } else {
                char lowered = tolower(first_name[i]);
                strip_FN[j] = lowered;
            }
            j++;
        }
    }
    /* lengthen to 3/chop first name if needed */
    char final_FN[101] = "";
    if (strlen(strip_FN) == 1) {
        final_FN[0] = toupper(strip_FN[0]);
        final_FN[1] = tolower(strip_FN[0]); // TRIPLES the last character
        final_FN[2] = tolower(strip_FN[0]);
    } else if (strlen(strip_FN) == 2) {
        final_FN[0] = toupper(strip_FN[0]);
        final_FN[1] = tolower(strip_FN[1]); // DOUBLES the last character
        final_FN[2] = tolower(strip_FN[1]);
    } else { // only get the first 3 characters
        for (int i = 0; i < 3; i++) {
            final_FN[i] = strip_FN[i];
        }
    }
    
    /* FIRST NAME DONE. PROCESS LAST NAME! */
    char strip_LN[101] = "";
    for (int i=0; i < strlen(surname); i++) {
        if (isalpha(surname[i])) {
            char small = tolower(surname[i]);
            strip_LN[i] = small;
        }
    }
    char final_LN[101] = ""; 
    if (strlen(strip_LN) < 2) { // append itself again(?)
        final_LN[0] = strip_LN[0];
    } else { // get the last 2 letters
        final_LN[0] = strip_LN[strlen(strip_LN)-2];
        final_LN[1] = strip_LN[strlen(strip_LN)-1];
    }

    /* LAST NAME DONE. PROCESS HOMETOWN! (same as firstname tbh) */
    /* FILTER hometown */
    char strip_home[101] = "";
    up = 1;
    j = 0;
    for (int i=0; i < strlen(hometown); i++) {
        if (isalpha(hometown[i])) {
            if (up) {
                char upped = toupper(hometown[i]);
                strip_home[j] = upped;
                up = 0;
            } else {
                char lowered = tolower(hometown[i]);
                strip_home[j] = lowered;
            }
            j++;
        }
    }
    /* lengthen/chop hometown if needed */
    char final_home[101] = "";
    if (strlen(strip_home) == 1) {
        final_home[0] = toupper(strip_home[0]);
        final_home[1] = tolower(strip_home[0]); // TRIPLES the last character
        final_home[2] = tolower(strip_home[0]);
    } else if (strlen(strip_home) == 2) {
        final_home[0] = toupper(strip_home[0]);
        final_home[1] = tolower(strip_home[1]); // DOUBLES the last character
        final_home[2] = tolower(strip_home[1]);
    } else { // only get the first 3 characters
        for (int i = 0; i < 3; i++) {
            final_home[i] = strip_home[i];
        }
    }
    /* HOMETOWN DONE. PROCESS MIDDLENAME! */
    char final_MN[101] = "";
    j = 0;
    for (int i=0; i < strlen(middle_name); i++) {
        if (isalpha(middle_name[i])) {
            char small = tolower(middle_name[i]);
            final_MN[j] = small;
            j++;
        }
    }
    
    printf("%s%s %s%s", final_FN, final_LN, final_home, final_MN);

    return 0;

}