// google interview qs
// given an array where numbers between 1 and the length of that array can exist
// find the first repeating number of the array, if not found return -1
// time - O(n), space - O(1)

#include <bits/stdc++.h>
using namespace std;

int firstDuplicate(int n, int* arr){
    for (int i=0; i<n; i++){
        if (arr[abs(arr[i])-1] < 0) return abs(arr[i]);
        arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) cin>>arr[i];
    cout<<firstDuplicate(n, arr)<<endl;
}
