//assignment
#include <stdio.h>
#include <string.h>
#define sizeofstudents 10

struct Stud {
    char name[20];
    int roll_no;
    float CGPA;
} Students[sizeofstudents], StudentsBubble[sizeofstudents], StudentsQuick[sizeofstudents], StudentsMerge[sizeofstudents];

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

void merge(struct Stud arr[], int left, int mid, int right, int* mergeCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Stud L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].roll_no <= R[j].roll_no) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        (*mergeCount)++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*mergeCount)++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*mergeCount)++;
    }
}

void mergeSort(struct Stud arr[], int left, int right, int* mergeCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, mergeCount);
        mergeSort(arr, mid + 1, right, mergeCount);

        merge(arr, left, mid, right, mergeCount);
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
    int inputsize = 0, bubbleCount = 0, quickCount = 0, mergeCount = 0;
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
    copyArray(StudentsMerge, Students, inputsize);

    // Sorting using bubble sort
    bubbleSort(StudentsBubble, inputsize, &bubbleCount);
    printf("\nStudents sorted by roll number using bubble sort:\n");
    for (int i = 0; i < inputsize; i++) {
        printf("Name: %s, Roll No: %d, CGPA: %.2f\n", StudentsBubble[i].name, StudentsBubble[i].roll_no, StudentsBubble[i].CGPA);
    }
    printf("Bubble sort swap count: %d\n", bubbleCount);

    // Sorting using quick sort
    quickSort(StudentsQuick, 0, inputsize - 1, &quickCount);
    printf("\nStudents sorted by roll number using quick sort:\n");
    for (int i = 0; i < inputsize; i++) {
        printf("Name: %s, Roll No: %d, CGPA: %.2f\n", StudentsQuick[i].name, StudentsQuick[i].roll_no, StudentsQuick[i].CGPA);
    }
    printf("Quick sort swap count: %d\n", quickCount);

    // Sorting using merge sort
    mergeSort(StudentsMerge, 0, inputsize - 1, &mergeCount);
    printf("\nStudents sorted by roll number using merge sort:\n");
    for (int i = 0; i < inputsize; i++) {
        printf("Name: %s, Roll No: %d, CGPA: %.2f\n", StudentsMerge[i].name, StudentsMerge[i].roll_no, StudentsMerge[i].CGPA);
    }
    printf("Merge sort merge count: %d\n", mergeCount);

    return 0;
}
