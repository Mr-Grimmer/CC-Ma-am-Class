#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void vertical_swap(int arr[SIZE][SIZE]);
void horizontal_swap(int arr[SIZE][SIZE]);
void random_swap(int arr[SIZE][SIZE]);
void print_array(int arr[SIZE][SIZE]);

int main() {
    int arr[SIZE][SIZE];
    int choice;
    int value = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = value++;
        }
    }
    void (*funtions[])(int[SIZE][SIZE]) = {vertical_swap, horizontal_swap, random_swap};

    do {
        printf("\n8x8 Array:\n");
        print_array(arr);

        printf("\nMenu:\n");
        printf("1. Vertical Swap (Row 1 ⬄ Row 8, etc.)\n");
        printf("2. Horizontal Swap (Column 1 ⬄ Column 4, etc.)\n");
        printf("3. Random Swap (All elements randomly shuffled)\n");
        printf("4. Stop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            funtions[choice - 1](arr);
        } else if (choice != 4) {
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    printf("Program terminated.\n");
    return 0;
}
void vertical_swap(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[SIZE - 1 - i][j];
            arr[SIZE - 1 - i][j] = temp;
        }
    }
    printf("\nVertical swap completed.\n");
}

void horizontal_swap(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[i][SIZE - 1 - j];
            arr[i][SIZE - 1 - j] = temp;
        }
    }
    printf("\nHorizontal swap completed.\n");
}

void random_swap(int arr[SIZE][SIZE]) {
    int total_swaps = SIZE * SIZE;
    for (int i = 0; i < total_swaps; i++) {
        int row1 = rand() % SIZE;
        int col1 = rand() % SIZE;
        int row2 = rand() % SIZE;
        int col2 = rand() % SIZE;
        int temp = arr[row1][col1];
        arr[row1][col1] = arr[row2][col2];
        arr[row2][col2] = temp;
    }
    printf("\nRandom swap completed.\n");
}

void print_array(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}
