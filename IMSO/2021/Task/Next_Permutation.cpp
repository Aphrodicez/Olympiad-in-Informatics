/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Permutation
	Status	: Untested
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int n, thisPermu[1010], newPermu[1010], mark[1010];

void nextPermu(){
	int l, r, nextElem;
	for(int i = n-1; i >= 0; i--){
		if(thisPermu[i] > thisPermu[i-1]){
			l = i - 1;
			break;
		}
	}
	for(int i = 0; i < l; i++){
		mark[thisPermu[i]] = 1;
	}
	for(int i = thisPermu[l] + 1; i <= n; i++){
		if(mark[i]==0){
			nextElem = i;
			break;
		}
	}
	for(int i = l + 1; i < n; i++){
		if(thisPermu[i]==nextElem){
			r = i;
			break;
		}
	}
	swap(thisPermu[l], thisPermu[r]);
	mark[thisPermu[l]] = 1;
	
	int i;
	
	for(i = 0; i <= l; i++){
		newPermu[i] = thisPermu[i];
	}
	for(int j = 1; j <= n; j++){
		if(!mark[j]){
			newPermu[i] = j;
			i++;
		}
	}
	return;
}

int main(){
	setIO();

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> thisPermu[i];
	}

	nextPermu();

	for(int i = 0; i < n; i++){
		cout << newPermu[i] << "\n";
	}


    return 0;
}