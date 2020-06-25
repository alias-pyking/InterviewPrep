#include<bits/stdc++.h>
using namespace std;
vector<int> find_substring(string s, vector<string> &words){
	int n = s.length(), word_size = words[0].size(), m = words.size();
	map<string, int> keywords_count, temp_count;
	for(auto word: words){
		keywords_count[word]++;
	}
	vector<int> result;
	for (int i = 0; i <= n - m*word_size; i++){
		temp_count.clear();
		int k;
		for ( k = 0; k < m; k++){
			string substr = s.substr(i + k * word_size, word_size);
			if(keywords_count.find(substr) != keywords_count.end()){
				temp_count[substr]++;
				if(temp_count[substr] > keywords_count[substr]){
					break;
				}
			} else{
				break;
			}
		}
		if(k == m) {
			result.push_back(i);
		}
	}
	return result;
}	

int main(){

}