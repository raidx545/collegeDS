#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> merged;
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }

    while (i < n) merged.push_back(arr1[i++]);
    while (j < m) merged.push_back(arr2[j++]);

    return merged;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8, 9};

    vector<int> result = mergeSortedArrays(arr1, arr2);

    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
