#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = arr[0];
    int currSum = arr[0];

    for (int i = 1; i < n; i++) {
        if (currSum < 0)
            currSum = arr[i];
        else
            currSum = currSum + arr[i];

        if (currSum > maxSum)
            maxSum = currSum;
    }

    cout << "Maximum subarray sum is: " << maxSum << endl;

    return 0;
}
