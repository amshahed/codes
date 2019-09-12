#include <bits/stdc++.h>
#define L long long int
using namespace std;

vector <L> prime;
char state[1000000010];

void primeSieve(L n){
    L i,sqrtn=sqrt(n)+1;
    state[0]=state[1]=1;
    state[2]=0;
    for (i=4; i<=n; i+=2)
        state[i]=1;
    prime.push_back(2);
    for (i=3; i<=sqrtn; i+=2){
        if (state[i]==0){
            for (L j=i*i; j<=n; j+=2*i)
                state[j]=1;
        }
    }
    for (i=3; i<=n; i+=2){
        if (state[i]==0)
            prime.push_back(i);
    }
}

int nod(int n){
    int res=1, p,i,sqrtn=sqrt(n);
    for (i=0; prime[i]<=sqrtn; i++){
        if (n%prime[i]==0){
            p=0;
            while (n%prime[i]==0){
                p++;
                n/=prime[i];
            }
            sqrtn=sqrt(n);
            res*=p+1;
        }
    }
    if (n>1)
        res*=2;
    return res;
}

int main(){
    L n;
    primeSieve(1000);
    cin>>n;
    cout<<nod(n);
}
