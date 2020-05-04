#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Graph{
	int V;
	list<int> *adjList;
	public:

	Graph(int V)
	{
		this->V = V;
		adjList = new list<int>[V];
	}
	void addEdge(int u, int v, bool bidir = true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		} 
	}
	void printAdjList(){
		for (int i = 0; i < V; i++){
			cout << i << " :";
			for(int node:adjList[i]){
				cout << node << " ";
			}
			cout << "\n";
		}
	}
	void dfs(int src){
		bool visited[V];
		visited[src] = true;
		dfs(src, visited);
		cout << "\n";
	}
	void dfs(int src, bool *visited){
		cout << src << " ";
		for(int child:adjList[src]){
			if(!visited[child]){
				visited[child] = true;
				dfs(child,visited);
			}
		}
	}
	void topological_sort_util(int u, stack<int> res, bool *visited){
		visited[u] = true;
		for (auto v:adjList[u]){
			if(visited[v]){
				continue;
			}
			topological_sort_util(v, res, visited);
		}
		res.push(u);
	}
	stack<int> topological_sort(){
		bool visited[V];
		stack<int> res;
		for (int u = 0; u < V; u++){
			if(visited[u]){
				continue;
			}
			topological_sort_util(u, res, visited);
		}
		return res;
	}
	vector<int> bfs(int src, int dest){
		queue<int> q;
		bool *visited = new bool[V]{0};
		int *distance = new int[V + 1]{0};
		int parent[V + 1];
		memset(parent, -1, sizeof parent);
		q.push(src);
		visited[src] = true;
		vector<int> result;
		while (!q.empty()){
			int node = q.front();
			result.push_back(node);
			q.pop();
			for(int neighbour:adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
					distance[neighbour] = distance[node] + 1;
					parent[neighbour] = node;
				}
			}
		}
		cout << distance[dest] << "\n";
		int temp = dest;
		while(temp != -1){
			cout << temp << " ";
			temp = parent[temp];
		}
		cout << "\n";
		return result;
	}




};
int main(){
	Graph g(50);
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;
	for (int u = 0; u <= 36; u++){
		// Throw a dice from 1 to 6;
		for (int dice = 1; dice <= 6; dice++){
			int v = u + dice + board[u + dice];
			g.addEdge(u, v, false);
		}
	}
	g.bfs(0, 36);
	g.dfs(0);
}