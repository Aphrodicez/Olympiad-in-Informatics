/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: 
	Status	: Untested
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int a[200010], query[200010];

map <int, int> compress;

int main(){
	int l, n;
	cin >> l >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		query[i] = a[i];
	}
	sort(query + 1, query + n + 1);
	for(int i = 1; i <= n; i++){
		compress[query[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		upd()
	}
    return 0;
}