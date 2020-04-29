#include<iostream>
#include<list>
#include<unordered_map>
#include<string>
using namespace std;

template<typename T>

class Graph{
	unordered_map<T, list<T>> adjList;
	public:
	void addEdge(T u, T v, bool bidir = true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	void printAdjList(){
		for(auto row : adjList){
			T key = row.first;
			cout << key << "->";
			for(T element: row.second){
				cout << element << " ";
			}
			cout << "\n";
		}
	}

};

int main(){
	Graph<string> g;
	g.addEdge("Dehli", "Amritsar");
	g.addEdge("Amritsar", "Jaipur");
	g.addEdge("Dehli", "Siachen");
	g.addEdge("Dehli", "Banglore");
	g.addEdge("Dehli", "Agra");
	g.addEdge("Banglore", "Jaipur");
	g.printAdjList();
}