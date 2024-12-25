#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function for Question 2
void evaluateFunction(int n) {
    double result = (n * n * n) / 1000.0 - 100 * (n * n) - 100 * n + 3;
    cout << "Q2 - Function Value for n=" << n << ": " << result << endl;
}

// Function for Question 3
void insertionSortRecursive(vector<int>& arr, int n) {
    if (n <= 1)
        return;

    insertionSortRecursive(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void testInsertionSort() {
    vector<int> arr = { 12, 11, 13, 5, 6 };
    insertionSortRecursive(arr, arr.size());

    cout << "Q3 - Sorted Array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

// Function for Question 4
int recurrenceT1(int n) {
    if (n == 1)
        return 1;
    return recurrenceT1(n / 2) + n;
}

void testRecurrenceT1() {
    int n = 16;
    cout << "Q4 - Value of T(" << n << ") is: " << recurrenceT1(n) << endl;
}

// Function for Question 5
long long recurrenceT2(int n) {
    if (n == 1)
        return 1;
    return 7 * recurrenceT2(n / 2) + n * n;
}

void testRecurrenceT2() {
    int n = 16;
    cout << "Q5 - Value of T(" << n << ") is: " << recurrenceT2(n) << endl;
}

// Function for Question 6
long long recurrenceT3(int n) {
    if (n == 1)
        return 1;
    return 8 * recurrenceT3(n / 2) + n * n;
}

void testRecurrenceT3() {
    int n = 16;
    cout << "Q6 - Value of T(" << n << ") is: " << recurrenceT3(n) << endl;
}

// Main function
int main() {
    // Question 2
    evaluateFunction(10);
    evaluateFunction(100);

    // Question 3
    testInsertionSort();

    // Question 4
    testRecurrenceT1();

    // Question 5
    testRecurrenceT2();

    // Question 6
    testRecurrenceT3();

    return 0;
}
