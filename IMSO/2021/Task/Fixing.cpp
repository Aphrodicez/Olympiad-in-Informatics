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

vector <int> vec;

int main(){
	setIO();

	int n, m, k, last = 0, num, sum = 0;

	cin >> n >> m >> k;


	for(int i = 0; i < m; i++){
		cin >> num;
		if(num-last-1 > 0 && i != 0){
			vec.push_back(num-last-1);
		}
		last = num;
	}

	sort(vec.begin(), vec.end(), greater<int>());

	k--;

	for(int x: vec){
		if(k > 0){
			k--;
			continue;
		}
		sum += x;
	}

	cout << sum;

    return 0;
}