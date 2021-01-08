/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Permutation
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int n, k, l, cnt;

int mark[12], ans[12];

void permu(int state){
	if(state==k){
		cnt++;
		if(cnt==l){
			for(int i = 0; i < k; i++){
				cout << ans[i] << " ";
			}
			exit(0);
		}
	}
	for(int i = 1; i <= n; i++){
		if(mark[i])
			continue;
		mark[i] = 1;
		ans[state] = i;
		permu(state+1);
		mark[i] = 0;
	}
}

int main(){
	setIO();

	cin >> n >> k >> l;

	permu(0);

    return 0;
}