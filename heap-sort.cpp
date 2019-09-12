#include <bits/stdc++.h>
using namespace std;

int arr[] = { 2, 3, 9, 1, 0, 5, 3, 11, 43, 11 };

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int n, int i){
    int largest = i;
    int l = i*2+1, r = i*2+2;
    if (l<n && arr[l]>arr[largest])
        largest=l;
    if (r<n && arr[r]>arr[largest])
        largest=r;
    if (largest!=i){
        swap(&arr[i], &arr[largest]);
        heapify(n, largest);
    }
}

void heapSort(int n){
    for (int i=n/2-1; i>=0; i--)
        heapify(n, i);
    for (int i=n-1; i>0; i--){
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
}

int main(){
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(n);
    for (int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}
