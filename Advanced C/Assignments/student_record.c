#include <stdio.h>

/*

Name: N. Venkatesan
Date: 
Description: 
Sample Input:
Sample output: 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 10

typedef struct {
    int roll_no;
    char name[MAX_NAME_LENGTH];
    int marks[MAX_SUBJECTS];
    char subject_names[MAX_SUBJECTS][MAX_NAME_LENGTH];
    int num_subjects;
    float average;
    char grade;
} Student;

char calculate_grade(float average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void display_student_details(Student student) {
    printf("%-10d%-15s", student.roll_no, student.name);
    for (int i = 0; i < student.num_subjects; i++) {
        printf("%-15d", student.marks[i]);
    }
    printf("%-15.2f%-5c\n", student.average, student.grade);
}

void display_all_students(Student *students, int num_students) {
    printf("Roll No.   Name           ");
    for (int i = 0; i < students[0].num_subjects; i++) {
        printf("%-15s", students[0].subject_names[i]);
    }
    printf("Average       Grade\n");
    for (int i = 0; i < num_students; i++) {
        display_student_details(students[i]);
    }
}

void display_particular_student(Student *students, int num_students) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the student : ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            display_student_details(students[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int num_students;
    printf("Enter no. of students: ");
    scanf("%d", &num_students);

    int num_subjects;
    printf("Enter no. of subjects: ");
    scanf("%d", &num_subjects);

    char subject_names[MAX_SUBJECTS][MAX_NAME_LENGTH];
    for (int i = 0; i < num_subjects; i++) {
        printf("Enter the name of subject %d: ", i+1);
        scanf("%s", subject_names[i]);
    }

    Student students[num_students];
    for (int i = 0; i < num_students; i++) {
        printf("----------Enter the student details-------------\n");
        printf("Enter the student Roll no. : ");
        scanf("%d", &students[i].roll_no);
        printf("Enter the student %d name : ", i+1);
        scanf("%s", students[i].name);
        students[i].num_subjects = num_subjects;
        for (int j = 0; j < num_subjects; j++) {
            printf("Enter %s mark : ", subject_names[j]);
            scanf("%d", &students[i].marks[j]);
            strcpy(students[i].subject_names[j], subject_names[j]);
        }
        float total = 0;
        for (int j = 0; j < num_subjects; j++) {
            total += students[i].marks[j];
        }
        students[i].average = total / num_subjects;
        students[i].grade = calculate_grade(students[i].average);
    }

    int choice;
    char continue_choice='y';
    do {
        printf("\n----Display Menu----\n");
        printf("1. All student details\n");
        printf("2. Particular student details\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_all_students(students, num_students);
                break;
            case 2:
                printf("\n----Menu for Particular student----\n");
                printf("1. Name.\n");
                printf("2. Roll no.\n");
                printf("Enter your choice : ");
                int sub_choice;
                scanf("%d", &sub_choice);
                switch (sub_choice) {
                    case 1:
                        display_particular_student(students, num_students);
                        break;
                    case 2:
                        // code for displaying particular student by roll no.
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("Do you want to continue to display(Y/y) : ");
        //char continue_choice;
        scanf(" %c", &continue_choice);
    } while (continue_choice == 'y' || continue_choice == 'Y');

    return 0;
}

