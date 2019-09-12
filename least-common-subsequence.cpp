#include<bits/stdc++.h>
using namespace std;

void lcs(char* X, char* Y, int m, int n){
    int l[m+1][n+1];
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            if (!i || !j)   l[i][j] = 0;
            else if (X[i]==Y[j])    l[i][j]=1+l[i-1][j-1];
            else l[i][j] = max(l[i-1][j], l[i][j-1]);
        }
    }

    int i=m, j=n; string s = "";
    while(i && j){
        if (l[i][j]==l[i-1][j-1]+1) { i--;j--; s = X[i]+s; }
        else if (l[i-1][j]>l[i][j-1])   i--;
        else j--;
    }
    cout<<s;
}

int main(){
    char X[] = "AGGTAB", Y[] = "GXTXAYB";
    int m = strlen(X), n = strlen(Y);
    lcs(X, Y, m, n);
}
