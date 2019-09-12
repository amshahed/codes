#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int n, int k){
    int begin = 0, end = n-1, idx = -1;
    while(begin<=end){
        int mid = (begin+end)>>1;
        if (arr[mid]==k){
            idx = mid;
            break;
        }
        if (k<arr[mid]) end = mid-1;
        else begin = mid+1;
    }
    return idx;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<binarySearch(arr, 9, 2)<<endl;
    cout<<binarySearch(arr, 9, 9)<<endl;
    cout<<binarySearch(arr, 9, 11)<<endl;
}
