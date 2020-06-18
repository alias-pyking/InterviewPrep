#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int n){
	for (int i = 1; i < n; i++){
		int element = arr[i], j = i - 1;
		while(j >= 0 and arr[j] > element){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = element;
	}
	return;
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	insertion_sort(arr, n);
	for (int i = 0; i < n; i++){
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}