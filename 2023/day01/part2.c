#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TEST "test2.txt"
#define INPUT "input2.txt"

char *numbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

int is_word_num(char *line, int curr_idx, int last_num_idx) {
    int length = ((curr_idx) - last_num_idx) + 1;
    char *string = malloc(sizeof(char) * (length));

    strncpy(string, line+last_num_idx, length);
    string[length] = '\0';

    for (int i = 0; i < 9; i++) {
        if (strstr(string, numbers[i]) != NULL) {
            free(string);
            return i+1;
        }
    }

    free(string);
    return 0;
}

int solve_part2(char *input[], int num_lines) {
    int sum = 0, last_num = 0,
        num_left, num_right, word_num;

    for (int i = 0; i < num_lines; i++) {
        num_left = num_right = -1;
        last_num = 0;
        for (int j = 0; j < strlen(input[i]); j++) {
            if (isalpha(input[i][j])) {
                word_num = is_word_num(input[i], j, last_num); 
                if (word_num != 0) {
                    if (num_left == -1) {
                        num_left = word_num;
                        num_right = word_num;
                    } else {
                        num_right = word_num;
                    }
                    last_num = j;
                }
            } else if (isdigit(input[i][j])) {
                if (num_left == -1) {
                    num_left =  input[i][j] - '0';
                    num_right =  input[i][j] - '0';
                } else {
                    num_right =  input[i][j] - '0';
                }
                last_num = j+1;
            }
        }
        sum += num_left * 10 + num_right;
    }

    return sum;
}

int main(int argc, char *argv[]) {
    FILE *fptr;
    char *input[1000], buffer[64];
    int num_lines = 0;

    fptr = fopen(INPUT, "r");

    if (fptr == NULL) {
        printf("Couldn't open file!");
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), fptr)) {
        input[num_lines] = (char*)malloc(sizeof(char)*sizeof(buffer));
        strcpy(input[num_lines], buffer);

        num_lines++;
    }

    printf("%d\n", solve_part2(input, num_lines));

    return 0;
}
