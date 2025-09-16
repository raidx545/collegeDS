#include <iostream>
#include <vector>
using namespace std ;
bool isPresent(int a , int arr[] , int size){
    for(int i = 0 ; i < size ; i++){
        if(arr[i]==a) return true ;
        if(arr[i]>a) return false ;
    }
    return false ;
}
int main() {
    int m , n ;
    cout<<"Enter the size of array1(m) and array2(n) "<<endl ;
    cin>>m>>n ;
    int arr1[m] , arr2[n];
    cout<<"Enter all the elements of array 1" << endl ;
    for(int k = 0 ; k < m ; k++) cin>>arr1[k];
    cout<<"Enter all the elements of array 2" << endl ;
    for(int k = 0 ; k < n ; k++) cin>>arr2[k];
    vector<int> arr3 ;
    int i = 0 , j =  0 ;
    while(i<m && j<n){
        if(arr1[i]==arr2[j]){
            arr3.push_back(arr1[i]);
            i++;
            j++;                                                 // using two pointers
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
    }

    //for unique numbers
    for(int k = 0 ; k < m ; k++ ){ 
        if(isPresent(arr1[k] , arr2,n)) {                       //using a bool function
            arr3.push_back(arr1[k]);
        }
    }

    
    for(int x : arr3)cout<<x<<" " ;
    return 0;
}
