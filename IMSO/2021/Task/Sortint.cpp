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

	vector<int> vec(n);

	for(int i = 0; i < n; i++){
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	for(int x: vec){
		cout << x << "\n";
	}

    return 0;
}