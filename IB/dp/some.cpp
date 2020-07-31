#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout <<" Hello there enter the size of array :\n" ;

	cin >> n;
	int arr[n];
	cout << "Enter the elements of array\n";
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i< n; i++){
		cout << arr[i] << ' ';
	}
	return 0;
}
