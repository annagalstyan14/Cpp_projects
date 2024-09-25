#include <iostream>
using namespace std;

void merge(int A[], int begin, int middle, int end) {
    int s1 = middle - begin + 1;
    int s2 = end - middle;

    int B[s1], E[s2];

    for (int n = 0; n < s1; n++) {
        B[n] = A[begin + n];
    }

    for (int m = 0; m < s2; m++) {
        E[m] = A[middle + 1 + m];
    }

    int i = 0, j = 0, k = begin;

    while (i < s1 && j < s2) {
        if (B[i] <= E[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = E[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        A[k] = B[i];
        i++;
        k++;
    }

    while (j < s2) {
        A[k] = E[j];
        j++;
        k++;
    }
}

void MergeSort(int A[], int begin, int end) {
    if (begin < end) {
        int middle = begin + (end - begin) / 2;
        MergeSort(A, begin, middle);
        MergeSort(A, middle + 1, end);
        merge(A, begin, middle, end);
    }
}

int BinarySearch(int A[], int begin, int end, int find) {
    while (begin <= end) {
        int middle = begin + (end - begin) / 2;

        if (A[middle] == find)
            return middle;
        if (A[middle] > find)
            end = middle - 1;
        else
            begin = middle + 1;
    }
    return -1;
}

int main() {
    int p;

    cout << "Enter the size of the array: ";
    cin >> p;

    int A[p];

    cout << "Enter " << p << " elements of the array: ";
    for (int i = 0; i < p; i++) {
        cin >> A[i];
    }

    MergeSort(A, 0, p - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < p; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    int find;
    cout << "Enter the element to search: ";
    cin >> find;

    int index = BinarySearch(A, 0, p - 1, find);

    if (index != -1)
        cout << "Element " << find << " found at index " << index << endl;
    else
        cout << "Element " << find << " not found in array" << endl;

    return 0;
}
