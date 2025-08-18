#include <stdio.h>
int rows;

int main(void) {
    // Prompt user for number of rows
    do {
        printf("Enter a number between 1 and 8: ");
        scanf("%d", &rows);
    } while (rows < 1 || rows > 8);
    // Print the pyramid
    for (int i = 0; i < rows; i++){
        // Print spaces for the left side of the pyramid
        for (int s = 0; s < rows - i - 1; s++){
            printf(" ");
        }
        // Print hashes for the left side of the pyramid
        for (int j = 0; j <= i; j++){
            printf("#");
        }
        // Print spaces between the two sides of the pyramid
        printf("  ");

        // Print hashes for the right side of the pyramid
        for (int j = 0; j <= i; j++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}