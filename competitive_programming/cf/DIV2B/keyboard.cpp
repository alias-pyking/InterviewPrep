#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k, q;
bool can[26];
char text[1000000];
vector<pair<int, int>> poskey[26], shifts;
string keyboard[100];
int distance(int x, int y, int a, int b){
	return (x - a)*(x-a) + (y - b)*(y-b);
}

bool check(int x, int y){
	int size = shifts.size();
	for (int i = 0; i < size; i++){
		int dis = distance(x, y, shifts[i].first, shifts[i].second);
		if(dis <= k*k){
			return true;
		}
	}
	return false;	
}
int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++){
		cin >> keyboard[i];
	}
	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if(keyboard[i][j] == 'S'){
				shifts.push_back(make_pair(i, j));
			} else{
				poskey[keyboard[i][j] - 'a'].push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < poskey[i].size() and !can[i]; j++){
			can[i] = can[i] | check(poskey[i][j].first, poskey[i][j].second);
		}
	}
	int res = 0;
	scanf("%d%s", &q, text);
	for (int i = 0; i < q; i++){
		if(islower(text[i])){
			if(poskey[text[i] - 'a'].empty()){
				res = -1;
				break;
			}
		} else{
			text[i] = tolower(text[i]);
			if(shifts.empty() or poskey[text[i]-'a'].empty()){
				res = -1;
				break;
			}
			if(!can[text[i] - 'a']){
				res++;
			}
		}
	}
	cout <<res << "\n";
}