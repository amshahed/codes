#include <bits/stdc++.h>
using namespace std;

int bigmod(int a, int p, int m){
    if (p==0)
        return 1%m;
    if (p%2==0)
        int half=bigmod(a,p/2,m);
    else
        return (a*bigmod(a,p-1,m))%m;
}

int main(){
    int n,p,m;
    cin>>n>>p>>m;
    cout<< bigmod(n,p,m);
}
