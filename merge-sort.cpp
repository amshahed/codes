#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int arr[] = { 2, 3, 9, 1, 0, 5, 3, 11, 43, 11, 9 };

void merge(int arr[], int p, int q, int r){
    int n1 = q-p+1, n2 = r-q;
    int left[n1+1], right[n2+1];
    for (int i=0; i<n1; i++)    left[i]=arr[p+i];
    for (int i=0; i<n2; i++)    right[i]=arr[q+1+i];
    left[n1] = right[n2] = INF;
    for (int i=0, j=0, k=p; k<=r; k++){
        if (left[i]<right[j])   { arr[k]=left[i]; i++; }
        else { arr[k]=right[j]; j++; }
    }
}

void mergeSort(int arr[], int p, int r){
    if (p<r){
        int q = (p+r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for (int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
