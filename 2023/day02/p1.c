#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT "input.txt"
#define TEST "test.txt"

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

typedef struct {
    int red;
    int blue; 
    int green; 

    int valid;
} Game;

int main(int argc, char* argv[]) {
    FILE *fptr;
    char *contents[100], buffer[200];
    int num_games = 0,
        id_sum = 0;

    // open file
    fptr = fopen(INPUT, "r");

    // check if file was opened
    if (fptr == NULL) {
        printf("Couldn't open file!");
        return 1;
    }

    // get contents of file
    while (fgets(buffer, sizeof(buffer), fptr)) {
        // allocate memory for the string
        contents[num_games] = (char*)malloc(sizeof(buffer));
        strcpy(contents[num_games], buffer);

        num_games++;
    }

    // close file
    fclose(fptr);

    /* 
     * Loop through the list of games
     *
     * Find number of r,g,b cubes
     * Check if number of cubes exceeds restraints
     * Sum up the possible game ids
     *
     * Print sum of ids 
     */

    Game game;
    char digits[2], color[6];
    int pos, idx;

    for (int i = 0; i < num_games; i++){
        idx = 0;
        while(contents[i][idx] != ':') {
            idx++;
        }

        game.red = game.blue = game.green = 0;
        game.valid = 1;

        while (strlen(contents[i]) + 1 > idx) {

            // If current char is a digit, add it to the digits array
            if (isdigit(contents[i][idx])) {
                pos = strlen(digits);
                digits[pos] = contents[i][idx];
                
            // If current char is a letter, add it to the color array
            } else if (isalpha(contents[i][idx])) {
                pos = strlen(color);
                color[pos] = contents[i][idx];

            // Means we got a cube, need the number and color
            } else if (contents[i][idx] == ',') {
                if (strcmp(color, "red") == 0) {
                    game.red += atoi(digits);
                } else if (strcmp(color, "green") == 0) {
                    game.green += atoi(digits);
                } else if (strcmp(color, "blue") == 0) {
                    game.blue += atoi(digits);
                }

                memset(digits, '\0', sizeof(digits));
                memset(color, '\0', sizeof(color));

            } else if (contents[i][idx] == ';' || idx == strlen(contents[i])) {
                if (strcmp(color, "red") == 0) {
                    game.red += atoi(digits);
                } else if (strcmp(color, "green") == 0) {
                    game.green += atoi(digits);
                } else if (strcmp(color, "blue") == 0) {
                    game.blue += atoi(digits);
                }

                memset(digits, '\0', sizeof(digits));
                memset(color, '\0', sizeof(color));

                if (game.red > MAX_RED || game.blue > MAX_BLUE || game.green > MAX_GREEN) {
                    game.valid = 0;
                }

                game.red = game.blue = game.green = 0;
            }

            idx++;
        }

        if (game.valid == 1) {
            id_sum += i + 1;
        }

    }

    printf("%d\n", id_sum);

    return 0;
}
