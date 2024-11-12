#include <stdio.h>
#include <stdlib.h>

#define STUDENTS 3  
#define EXAMS 4    


int minimum(const int grades[][EXAMS], int pupils, int tests);
int maximum(const int grades[][EXAMS], int pupils, int tests);
double average(const int setOfGrades[], int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);

int main(void) {
    int student;

    const int studentGrades[STUDENTS][EXAMS] = {
        {77, 68, 86, 73},
        {96, 87, 89, 78},
        {70, 90, 86, 81}
    };

    printf("The array is:\n\n");
    printf("                   [0] [1] [2] [3]\n\n");
    printArray(studentGrades, STUDENTS, EXAMS);  

    printf("\nLowest grade: %d\n", minimum(studentGrades, STUDENTS, EXAMS));
    printf("Highest grade: %d\n", maximum(studentGrades, STUDENTS, EXAMS));

    for (student = 0; student < STUDENTS; student++) {
        printf("The average grade for student %d is %.2f\n",
            student, average(studentGrades[student], EXAMS));
    }

    system("pause");  
    return 0;         
}

// ¨ç¼Æ©w¸q
int minimum(const int grades[][EXAMS], int pupils, int tests) {
    int lowGrade = grades[0][0];  

    for (int i = 0; i < pupils; i++) {
        for (int j = 0; j < tests; j++) {
            if (grades[i][j] < lowGrade) {
                lowGrade = grades[i][j]; 
            }
        }
    }

    return lowGrade;
}

int maximum(const int grades[][EXAMS], int pupils, int tests) {
    int highGrade = grades[0][0];  

    for (int i = 0; i < pupils; i++) {
        for (int j = 0; j < tests; j++) {
            if (grades[i][j] > highGrade) {
                highGrade = grades[i][j]; 
            }
        }
    }

    return highGrade;
}

double average(const int setOfGrades[], int tests) {
    int total = 0;

    for (int i = 0; i < tests; i++) {
        total += setOfGrades[i];  
    }

    return (double)total / tests;  
}

void printArray(const int grades[][EXAMS], int pupils, int tests) {
    for (int i = 0; i < pupils; i++) {
        printf("student Grades [%d]  ", i);
        for (int j = 0; j < tests; j++) {
            printf("%d  ", grades[i][j]); 
        }
        printf("\n");
    }
}
