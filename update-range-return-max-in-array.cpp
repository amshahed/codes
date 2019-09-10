#include <bits/stdc++.h>
#define SZ 10000002
using namespace std;

long int arr[SZ];

int main(){
    long int n, m, a, b, k, x=0, mx=0;
    cin>>n>>m;
    while(m--){
        cin>>a>>b>>k;
        arr[a] += k;
        if (b+1 <= n)    arr[b+1] -= k;
    }
    for (int i=0; i<=n; i++){
        x += arr[i];
        if (mx<x)   mx=x;
    }
    cout<<mx;
    return 0;
}
