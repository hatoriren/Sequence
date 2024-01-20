#include <iostream>
using namespace std;

int calculateLIS(int* arr, int length) {
    int maxLength = 1;
    int* lis = new int[length];

    for (int i = 0; i < length; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                maxLength = max(maxLength, lis[i]);
            }
        }
    }
    delete[] lis;
    return maxLength;
}

int main() {
    int tests;
    cin >> tests;
    int** sequences = new int* [tests];
    int* lengths = new int[tests];
    int* results = new int[tests];

    for (int t = 0; t < tests; t++) {
        cin >> lengths[t];
        sequences[t] = new int[lengths[t]];
        for (int i = 0; i < lengths[t]; i++) {
            cin >> sequences[t][i];
        }
    }

    for (int t = 0; t < tests; t++) {
        results[t] = calculateLIS(sequences[t], lengths[t]);
    }

    cout << endl;

    for (int t = 0; t < tests; t++) {
        cout << results[t] << endl;
    }

   
    
    for (int t = 0; t < tests; t++) {
        delete[] sequences[t];
    }
    delete[] sequences;
    delete[] lengths;
    delete[] results;

    return 0;
}
