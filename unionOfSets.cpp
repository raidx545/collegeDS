// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std ;
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    int arr1[] = {2,3,5,6,9,10};
    int m = 6 ;
    int n = 4 ;
    int arr2[] = {4,6,9,10};
    vector<int> arr3 ;
    int i = 0 ;
    int j = 0 ;
    int k = 0;
    while(i<m && j < n){
        if(arr1[i]<arr2[j]){
            arr3.push_back(arr1[i++]);
        }
        else if(arr1[i]>arr2[j]){
            arr3.push_back(arr2[j++]);
        }
        else{
            arr3.push_back(arr2[j++]);
            i++;
        }
    }
    while(i<m) arr3.push_back(arr1[i++]);
    while(j<n) arr3.push_back(arr2[j++]);
    cout<<endl;
    for(int x : arr3)cout<<x<<" " ;
    return 0;
}