// given two strings, check if at most one insertion, deletion or replacement will make the strings equal

#include <bits/stdc++.h>
using namespace std;

string oneEditAway(string s, string t){
	int lenS = s.length(), lenT = t.length();
	if (abs(lenS - lenT) > 1)	return "NO";
	string s1, s2;
	if (lenS <= lenT)	s1 = s, s2 = t;
	else s1 = t, s2 = s;
	int l1 = 0, l2 = 0;
	bool edited = false;
	while (l1 < s1.length() && l2 < s2.length()){
		if (s1[l1] != s2[l2]){
			if (edited) return "NO";
			else edited = true;
			if (s1.length() < s2.length())	l2++;
			else l1++, l2++;
		} else l1++, l2++;
	}
	return "YES";
}

int main(){
    string s, t;
    getline(cin, s);
	getline(cin, t);
	cout<<oneEditAway(s, t)<<endl;
}
