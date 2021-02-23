/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Longest Increasing Subsequence
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int a[100010];

int main(){
	setIO();

	int n, num, sz = 0, idx;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> num;
		idx = lower_bound(a, a + sz, num) - a;
		if(idx==sz)
			sz++;
		a[idx] = num;
	}

	cout << sz;

    return 0;
}