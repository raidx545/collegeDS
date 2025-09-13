#include <iostream>
#include <vector>
using namespace std;

int secondLargest(vector<int>& arr) {
    if (arr.size() < 2) return -1{

    int largest = INT_MIN, second = INT_MIN;

    for (int num : arr) {
        if (num > largest) {
            second = largest;
            largest = num;
        } else if (num > second && num < largest) {
            second = num;
        }
    }

    return (second == INT_MIN) ? -1 : second;
}

int main() {
    vector<int> arr = {10, 20, 4, 45, 99, 99, 23};
    int result = secondLargest(arr);

    if (result == -1)
        cout << "No second largest element\n";
    else
        cout << "Second Largest: " << result << endl;

    return 0;
}
