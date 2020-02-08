//given two strings, have to determine if one is permutation of the other

#include <bits/stdc++.h>
using namespace std;

// O(n) solution
bool checkPermutation(string s, string t){
    if (s.length() != t.length())   return false;
    int arr[128] = {0};
    for (int i=0; i<s.length(); i++)    arr[(int)s[i]]++;
    for (int i=0; i<t.length(); i++){
        if (arr[(int)t[i]]==0)  return false;
        arr[(int)t[i]]--;
    }
    return true;
}

// O(nlog(n)) solution
// bool checkPermutation(string s, string t){
//     if (s.length() != t.length()) return false;
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     return s == t;
// }

int main(){
    string s, t;
    cin>>s>>t;
    cout<< (checkPermutation(s, t) ? "YES" : "NO") << endl;
}
