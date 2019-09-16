#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n, a, pos=1, neg=0, curr=1;
	cin>>n;
	for(int i=0 ;i<n ;i++){
		cin>>a;
		curr *= a>0?1:-1;
		if(curr==1) pos++;
		else    neg++;
	}
	cout<<pos*neg<< " "<<n*(n+1)/2 - pos*neg<<endl;
}
