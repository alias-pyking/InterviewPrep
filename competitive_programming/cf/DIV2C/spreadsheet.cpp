#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpl;
typedef vector<pair<double, double>> vpd;

#define maxvec(vec) *max_element(vec.begin(), vec.end())
#define minvec(vec) *min_element(vec.begin(), vec.end())
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, n) for (int i = 1; i <= n; i++)
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define print(var) cout << var << "\n";
#define print_itrn(seq, n) fo(i, n) print(seq[i])
#define print_itr(seq, n) fo(i, n) cout << seq[i] << " ";
#define OJ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
const int N = 1e5 + 24;
const int mod = 1e9 + 7;
#define mark -2e9
#define MAXN 1010
int sheet[MAXN][MAXN];
int nrows, ncols;
string str;
string formula[MAXN][MAXN];
int dfs(int r, int c){
	if(sheet[r][c] != mark)
		return sheet[r][c];
	if(sheet[r][c] == mark){
		int m_row, m_col;
		char temp[MAXN];
		string str = formula[r][c];
		sheet[r][c] = 0;
		for (int i = 1, pos = 0; i <= str.size() + 1; i++){
			if(str[i] == '+' or i == str.size()){
				temp[pos] = '\0';
				m_row = 0, m_col = 0;
				int k;
				// converting the column name to a number
				for (k = 0; k < strlen(temp) and !isdigit(temp[k]); k++){
					m_col = m_col * 26 + temp[k] - 'A' + 1;
				}
				// converting the row to a number
				for (; k < strlen(temp); k++){
					m_row = m_row * 10 + temp[k] - '0';
				}
				pos = 0;
				sheet[r][c] += dfs(m_row, m_col);
			} else {
				temp[pos++] = str[i];
			}
		}
		return sheet[r][c];
	}
}
int main(){
	int t, q;
	cin >> t;
	while(t--){
		scanf("%d %d", &ncols, &nrows);
		memset(sheet, 0, sizeof(sheet));
		int val;
		for (int i = 1; i <= nrows; i++){
			for (int j = 1; j <= ncols; j++){
				cin >> str;
				if(str[0] == '='){
					sheet[i][j] = mark;
					formula[i][j] = str;
				} else {
					val = stoi(str);
					sheet[i][j] = val;
				}
			}
		}
		for (int i = 1; i <= nrows; i++){
			for (int j = 1; j <= ncols; j++){
				if(sheet[i][j] == mark){
					dfs(i, j);
				}
			}
		}
		for (int i = 1; i <= nrows; i++){
			printf("%d", sheet[i][1]);
			for (int j = 2; j <= ncols; j++){
				printf(" %d", sheet[i][j]);
			}
			printf("\n");
		}
	}
}

