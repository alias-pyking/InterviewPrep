#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for (i = 0; i < n; i++)

const int N = 250024;
int l[N],h[N];
int res = 0;
stack<int> st;	

int main(){
	int n, m, a, b, k, r;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> l[i];
		cin >> h[i];
		if(st.empty()){
			res++;
			st.push(h[i]);
		} else {
			while(st.top() > h[i]){
				st.pop();
				if(st.empty())
					break;
			}
			if(st.empty()){
				res++;
				st.push(h[i]);
			} else {
				if(st.top() == h[i])
					continue;
				else {
					res++;
					st.push(h[i]);
				}
			}
		}

	}
	cout << res << "\n";
}
