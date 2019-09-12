#include<bits/stdc++.h>
using namespace std;
typedef long long int L;
L phi[2000000+10],mark[2000000+10];

void euler(L n){
    for(L i=1;i<=n;i++)
        phi[i]=i;
    phi[1]=mark[1]=1;
    for(L i=2;i<=n;i+=2){
        if(i!=2)
            mark[i]=1;
        phi[i]=phi[i]/2;
    }
    for(L i=3;i<=n;i+=2){
        if(!mark[i]){
            phi[i]-=1;
            for(L j=2*i;j<=n;j+=i){
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

int main(){
    euler(1000000+10);
    L n;
    cin>>n;
    cout<<phi[n];
}
