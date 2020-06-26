#include<bits/stdc++.h>
using namespace std;
class LRUCache{
	public:
		LRUCache(int);
		int get(int);
		void set(int, int);
};
int _size;
list<int> lru;
unordered_map<int,pair<int, list<int>::iterator>> cache;
LRUCache::LRUCache(int capacity) {
	_size = capacity;
	cache.clear();
	lru.clear();
}

int LRUCache::get(int key) {
	auto item = cache.find(key);
	if(item == cache.end()) return -1;
	lru.erase(item->second.second);
	lru.push_front(key);
	cache[key].second = lru.begin();
	return cache[key].first;
}

void LRUCache::set(int key, int value) {
	auto item = cache.find(key);
	if(item != cache.end()){
		lru.erase(item->second.second);
		lru.push_front(key);
		cache[key].second = lru.begin();
		cache[key].first = value;
		return;
	}
	if(cache.size() == _size){
		cache.erase(lru.back());
		lru.pop_back();
	}
	lru.push_front(key);
	cache.insert({key,{value,lru.begin()}});
	return;
}

int main(){

}