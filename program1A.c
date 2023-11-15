#include <stdio.h>

#define MAX_SIZE 100

// Function prototypes
void insertElement(int array[], int *n, int elem, int pos);
void deleteElement(int array[], int *n, int pos);
void displayArray(int array[], int n);

int main() {
    int array[MAX_SIZE];
    int n = 0; // Number of elements in the array
    int choice, elem, pos;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array Elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert an element
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insertElement(array, &n, elem, pos);
                break;

            case 2:
                // Delete an element
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteElement(array, &n, pos);
                break;

            case 3:
                // Display array elements
                displayArray(array, n);
                break;

            case 4:
                // Exit the program
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to insert an element at a given position
void insertElement(int array[], int *n, int elem, int pos) {
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position. Insertion failed.\n");
        return;
    }

    for (int i = *n; i >= pos; i--) {
        array[i] = array[i - 1];
    }

    array[pos - 1] = elem;
    (*n)++;

    printf("Element inserted successfully.\n");
}

// Function to delete an element at a given position
void deleteElement(int array[], int *n, int pos) {
    if (pos < 1 || pos > *n) {
        printf("Invalid position. Deletion failed.\n");
        return;
    }

    for (int i = pos - 1; i < *n - 1; i++) {
        array[i] = array[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully.\n");
}

// Function to display array elements
void displayArray(int array[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
