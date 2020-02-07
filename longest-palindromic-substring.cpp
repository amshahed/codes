// google interview qs
// given a string, find the longest palindromic substring
// time - O(n^2), space - O(1)

#include <bits/stdc++.h>
using namespace std;

int expandFromMiddle(string s, int left, int right){
    if (s.empty() || left>right) return -1;
    while (left>=0 && right<s.length() && s[left]==s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindromicSubstring(string s){
    if (s.empty())  return "";
    int start = 0, len = 0;
    for (int i=0; i<s.length()-1; i++){
        int n1 = expandFromMiddle(s, i, i);
        int n2 = expandFromMiddle(s, i, i+1);
        int n = max(n1, n2);
        if (n > len){
            start = i - (n-1)/2;
            len = n;
        }
    }
    return s.substr(start, len);
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindromicSubstring(s)<<endl;
}
