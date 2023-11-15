#include <stdio.h>

#define MAX_STUDENTS 5
#define NUM_SUBJECTS 3

// Structure definition for Student
struct Student {
    int rollNo;
    char name[50];
    int semester;
    int marks[NUM_SUBJECTS];
};

// Function prototypes
void enterDetails(struct Student *students, int numStudents);
void displayDetails(const struct Student *students, int numStudents);
void calculateTotals(const struct Student *students, int numStudents);

int main() {
    struct Student students[MAX_STUDENTS];

    // Enter details for 5 students
    enterDetails(students, MAX_STUDENTS);

    // Display details for 5 students
    displayDetails(students, MAX_STUDENTS);

    // Calculate and display student-wise and subject-wise total marks
    calculateTotals(students, MAX_STUDENTS);

    return 0;
}

// Function to enter details for 5 students using a pointer to structure
void enterDetails(struct Student *students, int numStudents) {
    printf("Enter details for 5 students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &(students[i].rollNo));
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Semester: ");
        scanf("%d", &(students[i].semester));

        printf("Enter marks for 3 subjects:\n");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &(students[i].marks[j]));
        }
    }
}

// Function to display details for 5 students using a pointer to structure
void displayDetails(const struct Student *students, int numStudents) {
    printf("\nStudent details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Semester: %d\n", students[i].semester);

        printf("Marks in 3 subjects: ");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\n");
    }
}

// Function to calculate and display student-wise and subject-wise total marks
void calculateTotals(const struct Student *students, int numStudents) {
    printf("\nStudent-wise and Subject-wise Total Marks:\n");
    for (int i = 0; i < numStudents; i++) {
        int studentTotal = 0;
        printf("\nStudent %d - %s:\n", i + 1, students[i].name);

        // Calculate and display subject-wise total marks for each student
        printf("Subject-wise Total Marks: ");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            int subjectTotal = 0;
            for (int k = 0; k < numStudents; k++) {
                subjectTotal += students[k].marks[j];
            }
            printf("Subject %d: %d  ", j + 1, subjectTotal);
        }

        // Calculate and display student-wise total marks
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            studentTotal += students[i].marks[j];
        }
        printf("\nTotal Marks for Student %d: %d\n", i + 1, studentTotal);
    }
}

