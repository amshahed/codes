// given a N*N matrix, have to rotate it 90 degrees

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n][n];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin>>arr[i][j];
	for (int i=0; i<n/2; i++){
		int last = n - i - 1;
		for (int j=i; j<last; j++){
			int offset = j - i;
			int top = arr[i][j];
			arr[i][j] = arr[last-offset][i];
			arr[last-offset][i] = arr[last][last-offset];
			arr[last][last-offset] = arr[j][last];
			arr[j][last] = top;
		}
	}
	cout<<"------"<<endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}
