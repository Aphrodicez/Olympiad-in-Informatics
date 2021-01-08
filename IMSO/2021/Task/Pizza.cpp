/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Binary Search
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

	int n, p;

	cin >> n >> p;

	vector<int> a(n);
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int l = 1, r = 2e9, mid;

	while(l < r){
		mid = (l+r) / 2;
		int sum = 0;
		bool ch = false;
		for(int i = 0; i < n; i++){
			sum += mid / a[i] + 1;
			if(sum >= p){
				ch = true;
				break;
			}
		}

		if(ch)
			r = mid;
		else
			l = mid + 1;
	}

	cout << l;

    return 0;
}