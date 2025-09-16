#include <iostream>
#include <vector>
using namespace std ;
int main() {
    int m , n ;
    cout<<"Enter the size of array1(m) and array2(n) "<<endl ;
    cin>>m>>n ;
    int arr1[m] , arr2[n];
    cout<"Enter all the elements of array 1" << endl ;
    for(int k = 0 ; k < m ; k++) cin>>arr1[k];
    cout<<"Enter all the elements of array 2" << endl ;
    for(int k = 0 ; k < n ; k++) cin>>arr2[k];
    vector<int> arr3 ;
    int i = 0 ;
    int j = 0 ;
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
