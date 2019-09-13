#include <bits/stdc++.h>
#define mx 100002
using namespace std;

int cnt[mx];

vector<int> countingSort(vector<int> a){
    int n = a.size();
    vector<int> sorted(n, 0);
    for (int i=0; i<n; i++) cnt[a[i]]++;
    for (int i=1; i<mx; i++)    cnt[i]+=cnt[i-1];
    for (int i=0; i<n; i++){
        sorted[cnt[a[i]]-1] = a[i];
        cnt[a[i]]--;
    }
    return sorted;
}

int main(){
    int n, b;
    vector<int> a;
    cin>>n;
    for (int i=0; i<n; i++) { cin>>b; a.push_back(b); }
    a = countingSort(a);
    for (int i=0; i<n; i++) cout<<a[i]<<" ";
}
