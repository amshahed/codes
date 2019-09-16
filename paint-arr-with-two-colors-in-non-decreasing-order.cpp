#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s, a;
    int t, n;
    scanf("%d", &t);
    while(t--){
        int cnt = 0, j=0;
        cin>>n>>s;
        vector<char> ans(n, '0');
        a = s; sort(a.begin(), a.end());
        for (int i=0; i<n; i++){
            if (s[i]<=a[j]){
                ans[i]='1';
                j++; cnt++;
            }
        }
        if (cnt!=n){
            for (int i=0; i<n; i++){
                if (ans[i]=='0'){
                    if (s[i]<=a[j]){
                        ans[i]='2';
                        j++; cnt++;
                    }
                }
            }
        }
        if (cnt!=n) cout<<"-"<<endl;
        else {
            string str(ans.begin(), ans.end());
            cout<<str<<endl;
        }
    }
}
