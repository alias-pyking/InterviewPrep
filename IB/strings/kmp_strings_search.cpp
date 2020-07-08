#include <bits/stdc++.h>
using namespace std;

// search substrign in text
pair<int,int> kmp_search(string text, string substring){
	int n = text.length(), m = substring.length();
	vector<int> pattern(m,0);
	int i = 1, j = 0;
	while(i < m){
		if(substring[i] == substring[j]){
			pattern[i] = j + 1;
			i++, j++;
		} else {
			if(j - 1 >= 0) j = pattern[j - 1];
			else j = 0;
			if(substring[j] == substring[i]){
				pattern[j] = j + 1;
				i++, j++;
			} else {
				pattern[i] = 0;
				i++;
			}
		}
	}
	i = 0, j = 0;
	while(i < n and j < m){
		if(text[i] == substring[j]){
			i++, j++;
			if(j == m) return {i - j, i};
		}
		else {
			if(j  - 1 >= 0) j = pattern[j - 1];
			else i++;
		}
	}
	return {-1, -1};
}

int main(){
	int t, q;
	string text = "HelloIamshubhamandIamsks";
	string substring = "Iamsks";
	auto p = kmp_search(text, substring);
	cout << text.substr(p.first,p.second + 1) << '\n';
}