// given a string, return compressed string if compressed length is smaller
// input: aaabcccc, output: a3b1c4

#include <bits/stdc++.h>
using namespace std;

string compressString(string s){
	if (s.length() < 2)	return s;
	int cons = 0, len = s.length();
	string compressed = "";
	for (int i=0; i<len-1; i++){
		if (s[i]==s[i+1])	cons++;
		else {
			compressed += s[i] + to_string(++cons);
			cons = 0;
		}
	}
	if (s[len-1]==s[len-2])	compressed += s[len-1] + to_string(++cons);
	else compressed += s[len-1] + to_string(1);
	return compressed.length() < s.length() ? compressed : s;
}

int main(){
    string s;
    getline(cin, s);
	cout<<compressString(s)<<endl;
}
