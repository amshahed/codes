// given a string, check if it is a permutation of a palindrome
// case insensitive, disregard all non alphabetic characters (change code according to requirement)

#include <bits/stdc++.h>
using namespace std;

bool checkPalindromicPermutation(string s){
    int arr[26] = {0};
    bool hasOddCount = false;
    for (int i=0; i<s.length(); i++){
        if (s[i]>='A' && s[i]<='Z')     arr[s[i]-'A']++;
        else if (s[i]>='a' && s[i]<='z')    arr[s[i]-'a']++;
    }
    for (int i=0; i<26; i++)
        if (arr[i]%2){
            if (hasOddCount)    return false;
            else                hasOddCount = true;
        }
    return true;
}

int main(){
    string s;
    getline(cin, s);
    cout<< (checkPalindromicPermutation(s) ? "YES" : "NO")<<endl;
}
