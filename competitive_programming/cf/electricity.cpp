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
#include <assert.h>
using namespace std;
#define ll long long

bool is_thirtone(int month){
	int months[] = {1,3,5,7,8,10,12};
	for(int i=0; i < 7; i++){
		if (month == months[i]){
			return true;
		}
	}
	return false;
}

int main(){
    int n;
    cin >> n;
	int a[n][4];
	for (int i = 0;i < n; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
	}
	int days = 0, consumption = 0;
	for (int i = 1;i < n; i++){
		int day = a[i][0];
		int month = a[i][1];
		int year = a[i][2];
		int c = a[i][3];
		int prev_day = a[i - 1][0];
		int prev_month = a[i - 1][1];
		int prev_year = a[i - 1][2];
		int prev_c = a[i - 1][3];
		if(prev_month == 2 and prev_year % 4 == 0 and prev_year % 100 != 0){
			if(prev_day == 29 and day == 1 and month == 3 and year == prev_year){
				days++;
				consumption += c - prev_c;
			} else if(prev_day == day - 1 and month == prev_month and year == prev_year){
				days++;
				consumption += c - prev_c;
			}
		} else if(prev_month == 2){
			if(prev_day == 28 and day == 1 and month == 3 and year == prev_year){
				days++;
				consumption += c - prev_c;
			} else if(prev_day == day - 1 and month == prev_month and year == prev_year){
				days++;
				consumption += c - prev_c;
			}
		} else{
			if(prev_month == 12 and prev_day == 31 and day == 1 and year == prev_year + 1){
				days++;
				consumption += c - prev_c;
			} else if(is_thirtone(prev_month)){
				if(prev_month == month and year == prev_year and prev_day== day - 1){
					days++;
					consumption += c - prev_c;
				} else if(prev_month == month - 1 and year == prev_year and prev_day == 31 and day  == 1){
					days++;
					consumption += c - prev_c;
				}
			} else{
				if(prev_month == month and year == prev_year and prev_day + 1== day){
					days++;
					consumption += c - prev_c;
				} else if(prev_month + 1 == month and year == prev_year and prev_day == 30 and day == 1){
					days++;
					consumption += c - prev_c;
				}
			}
		}

	}
	cout << days << " " << consumption << "\n";
}