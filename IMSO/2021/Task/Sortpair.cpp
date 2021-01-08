/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Sorting
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int main(){
	setIO();

	int n;

	cin >> n;

	vector <pair<int, int>> vec(n);

	for(int i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
	}

	sort(vec.begin(), vec.end());

	for(pair<int, int> x: vec){
		cout << x.first << " " << x.second << "\n";
	}

    return 0;
}