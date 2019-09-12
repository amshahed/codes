#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int arr[] = { 2, 3, 9, 1, 0, 5, 3, 11, 43, 11 };

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int p, int r){
    int x = arr[r], i = p-1;
    for (int j=p; j<r; j++){
        if (arr[j]<=x)
            swap(&arr[++i], &arr[j]);
    }
    swap(&arr[++i], &arr[r]);
    return i;
}

void quickSort(int p, int r){
    if (p<r){
        int q = partition(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);
    }
}

int main(){
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(0, n-1);
    for (int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
