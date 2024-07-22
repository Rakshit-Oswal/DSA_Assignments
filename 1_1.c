//implement quick and bubble sort on a struct Student with roll_no as key
#include <stdio.h>
#include <string.h>
#define sizeofstudents 10

struct Stud {
    char name[20];
    int roll_no;
    float CGPA;
} Students[sizeofstudents], StudentsBubble[sizeofstudents], StudentsQuick[sizeofstudents];

void swap(struct Stud* a, struct Stud* b, int* swapCount) {
    struct Stud temp = *a;
    *a = *b;
    *b = temp;
    (*swapCount)++;
}

void bubbleSort(struct Stud arr[], int size, int* swapCount) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                swap(&arr[j], &arr[j + 1], swapCount);
            }
        }
    }
}

int partition(struct Stud arr[], int low, int high, int* swapCount) {
    int pivot = arr[high].roll_no;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].roll_no < pivot) {
            i++;
            swap(&arr[i], &arr[j], swapCount);
        }
    }
    swap(&arr[i + 1], &arr[high], swapCount);
    return (i + 1);
}

void quickSort(struct Stud arr[], int low, int high, int* swapCount) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high, swapCount);
        quickSort(arr, low, partitionIndex - 1, swapCount);
        quickSort(arr, partitionIndex + 1, high, swapCount);
    }
}

void copyArray(struct Stud dest[], struct Stud src[], int size) {
    for (int i = 0; i < size; i++) {
        strcpy(dest[i].name, src[i].name);
        dest[i].roll_no = src[i].roll_no;
        dest[i].CGPA = src[i].CGPA;
    }
}

int main() {
    int inputsize = 0, bubbleCount = 0, quickCount = 0;
    printf("Enter number of students (max size of 10): ");
    scanf("%d", &inputsize);

    for (int i = 0; i < inputsize; i++) {
        printf("Enter name of student: ");
        scanf("%s", Students[i].name);
        printf("Roll No: ");
        scanf("%d", &Students[i].roll_no);
        printf("CGPA: ");
        scanf("%f", &Students[i].CGPA);
    }

    // Create copies of the original array for each sorting function
    copyArray(StudentsBubble, Students, inputsize);
    copyArray(StudentsQuick, Students, inputsize);

    // Sorting using bubble sort
    bubbleSort(StudentsBubble, inputsize, &bubbleCount);
    printf("\nStudents sorted by roll number using bubble sort:\n");
    for (int i = 0; i < inputsize; i++) {
        printf("Name: %s, Roll No: %d, CGPA: %.2f\n", StudentsBubble[i].name, StudentsBubble[i].roll_no, StudentsBubble[i].CGPA);
    }
    printf("Bubble sort swap count: %d", bubbleCount);

    // Sorting using quick sort
    quickSort(StudentsQuick, 0, inputsize - 1, &quickCount);
    printf("\nStudents sorted by roll number using quick sort:\n");
    for (int i = 0; i < inputsize; i++) {
        printf("Name: %s, Roll No: %d, CGPA: %.2f\n", StudentsQuick[i].name, StudentsQuick[i].roll_no, StudentsQuick[i].CGPA);
    }
    printf("Quick sort swap count: %d", quickCount);

    return 0;
}

