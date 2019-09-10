#include <bits/stdc++.h>
using namespace std;

long countTriplets(vector<long> arr, long r) {
    map<long, long> map1, map2;
    long eita, agerta, cnt=0;
    for (int i=0; i<arr.size(); i++){
        eita = arr[i];
        agerta = eita/r;
        if (eita%r==0 && map2[agerta]>0)
            cnt += map2[agerta];
        if (eita%r==0 && map1[agerta]>0){
            map2[eita]+=map1[agerta];
        }
        map1[eita]++;
    }
    return cnt;
}

int main(){
    vector<long> arr;
    long n, r, a;
    cin>>n>>r;
    for (int i=0; i<n; i++){
        cin>>a;
        arr.push_back(a);
    }
    cout<<countTriplets(arr, r);
}
