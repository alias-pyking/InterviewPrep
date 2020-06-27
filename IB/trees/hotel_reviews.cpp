#include<bits/stdc++.h>
using namespace std;
vector<string> split(string str, char delimeter){
	vector<string> result;
	stringstream check(str);
	string token;
	while(getline(check,token,delimeter)){
		result.push_back(token);
	}
	return result;
}
bool compare(const pair<int,int> &first,const pair<int,int> &second){
	if(first.first != second.first){
		return first.first > second.first;
	}
	else return first.second < second.second;
}
vector<int> solve(string A, vector<string> &B){
	vector<string> _good_words = split(A, '_');
	unordered_set<string> good_words;
	for (auto word: _good_words) good_words.insert(word);
	vector<pair<int, int>> goodness;
	int n = B.size();
	for (int i = 0; i < n; i++){
		vector<string> review_words = split(B[i], '_');
		int c = 0;
		for(auto word: review_words){
			
			if(good_words.find(word) != good_words.end()){
				c++;
			}
		}
		goodness.push_back({c, i});
		
	}
	sort(goodness.begin(),goodness.end(),compare);
	vector<int> result;
	for(auto r: goodness){
		result.push_back(r.second);
	}
	return result;
}

int main(){

}