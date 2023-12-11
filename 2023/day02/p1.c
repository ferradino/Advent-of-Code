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
} Game;

int main(int argc, char* argv[]) {
    FILE *fptr;
    char *contents[5], buffer[200];
    int num_games = 0,
        id_sum = 0;

    // open file
    fptr = fopen(TEST, "r");

    // check if file was opened
    if (fptr == NULL) {
        printf("Couldn't open file!");
        return 1;
    }

    // get contents of file
    while (fgets(buffer, sizeof(buffer), fptr)) {
        // allocate memory for the string
        contents[num_games] = (char*)malloc(sizeof(char)*sizeof(buffer));
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

    for (int i = 0; i < num_games; i++){
        for (int j = 9; j < strlen(contents[i]); j++) {
            
        }
    }

    return 0;
}
