#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Function for Question A (Substitution/Iterative Method)
long long recurrenceA(int n) {
    if (n == 1)
        return 1;
    return 7 * recurrenceA(n / 2) + n * n;
}

void testRecurrenceA() {
    int n = 16;
    cout << "Q(A) - Value of T(" << n << ") is: " << recurrenceA(n) << endl;
}

// Function for Question B (Merging m Sorted Lists)
void mergeSortedLists(vector<vector<int>>& lists, vector<int>& result) {
    result.clear();
    vector<int> indices(lists.size(), 0);

    while (true) {
        int minVal = INT_MAX, minIndex = -1;
        for (int i = 0; i < lists.size(); ++i) {
            if (indices[i] < lists[i].size() && lists[i][indices[i]] < minVal) {
                minVal = lists[i][indices[i]];
                minIndex = i;
            }
        }

        if (minIndex == -1) break;

        result.push_back(minVal);
        indices[minIndex]++;
    }
}

void testMergeSortedLists() {
    vector<vector<int>> lists = { {1, 4, 7}, {2, 5, 8}, {3, 6, 9} };
    vector<int> result;
    mergeSortedLists(lists, result);

    cout << "Q(B) - Merged List: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

// Function for Question C (Huffman Algorithm Time Complexity)
void analyzeHuffman() {
    cout << "Q(C) - Huffman Algorithm Time Complexity: O(n log n)" << endl;
}

// Function for Question D (Weight of MST)
void computeMSTWeight(int n) {
    cout << "Q(D) - Weight of MST for " << n << " vertices: " << (n - 1) << endl;
}

// Function for Question E (O(k log k) Algorithm for Minimum Pair Sum)
void findMinPairSum(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int minSum = INT_MAX, x = 0, y = 0;

    for (int i = 0; i < arr.size() - 1; ++i) {
        int sum = abs(arr[i] + arr[i + 1]);
        if (sum < minSum) {
            minSum = sum;
            x = arr[i];
            y = arr[i + 1];
        }
    }

    cout << "Q(E) - Minimum Pair: (" << x << ", " << y << "), Sum: " << minSum << endl;
}

// Function for Question F (In-Degree and Out-Degree of Graph Nodes)
void computeDegrees(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<int> inDegree(n, 0), outDegree(n, 0);

    for (int i = 0; i < n; ++i) {
        outDegree[i] = adjList[i].size();
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    cout << "Q(F) - In-Degrees: ";
    for (int deg : inDegree) {
        cout << deg << " ";
    }
    cout << "\nQ(F) - Out-Degrees: ";
    for (int deg : outDegree) {
        cout << deg << " ";
    }
    cout << endl;
}

// Main function
int main() {
    // Question A
    testRecurrenceA();

    // Question B
    testMergeSortedLists();

    // Question C
    analyzeHuffman();

    // Question D
    computeMSTWeight(5); // Example: Graph with 5 vertices

    // Question E
    vector<int> arr = { 3, -1, -4, 2, 7 };
    findMinPairSum(arr);

    // Question F
    vector<vector<int>> adjList = { {1, 2}, {2, 3}, {3}, {}, {0, 1} };
    computeDegrees(adjList);

    return 0;
}
