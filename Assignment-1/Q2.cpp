#include <iostream>
using namespace std;

int b[100];

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= ub) {
            b[k] = a[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for (int x = lb; x <= ub; x++) {
        a[x] = b[x];
    }
}

void mergesort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n1 = 6;

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = 7;

    mergesort(arr, 0, n1 - 1);
    mergesort(arr2, 0, n2 - 1);

    cout << "Sorted first array: ";
    printArray(arr, n1);

    cout << "Sorted second array: ";
    printArray(arr2, n2);

    return 0;
}
