#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int solve_part1(char *input[], int num_lines) {
    int sum = 0, 
        num_left, num_right;

    for (int i = 0; i < num_lines; i++) {
        num_left = num_right = -1;
        for (int j = 0; j < strlen(input[i]); j++) {
            if (isdigit(input[i][j])) {
                if (num_left == -1) {
                    num_left = input[i][j] - '0';
                    num_right =  input[i][j] - '0';
                } else {
                    num_right =  input[i][j] - '0';
                }
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

    fptr = fopen("test2.txt", "r");

    if (fptr == NULL) {
        printf("Couldn't open file!");
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), fptr)) {
        input[num_lines] = (char*)malloc(sizeof(char)*sizeof(buffer));
        strcpy(input[num_lines], buffer);

        num_lines++;
    }

    printf("%d\n", solve_part1(input, num_lines));

    return 0;
}
