#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char* convert(char* s, int numRows) {
    char zigZag[strlen(s)][numRows];
    int i = 0; // To control the indexing of the string
    int staggerDistance = numRows - 2;
    int staggerPosition = staggerDistance;
    bool staggerState = false;

    for (int x = 0; x < strlen(s); x++) { // To control the x direction of the 2D array
        if (i == strlen(s)) break; // The moment we hit the end of the string, break out

        else { // Figure out how we will enter the stagger (i.e. make staggerActive = true)
            for (int y = 0; y < numRows; y++) { // To control the y direction of the 2D array
                if (staggerState && y == staggerPosition) { // If stagger is active, and we are in the right stagger position to add in the character, then add it in increment to the next character
                    zigZag[x][y] = s[i];
                    i++; // Character from original string added in. Move on to next
                    staggerPosition--;
                } else if (staggerState && y != staggerPosition) { // If stagger is active, but we are not at the position to add in, just fill in that space of the 2D array with NULL
                    zigZag[x][y] = '\0';
                } else { // If stagger is not active, proceed normal way of filling 2D array
                    zigZag[x][y] = s[i];
                    i++;
                }
            }
            if (staggerState == false) staggerState = true; 
            if (staggerPosition == 0) {
                staggerState = false;
                staggerPosition = staggerDistance;
            }
        }
    }

    return zigZag;
}

int main() {
    int numRows = 4;
    char s[] = "PAHNAPLSIIGYIR";

    printf("%s\n", convert(s, numRows));

    return 0;
}