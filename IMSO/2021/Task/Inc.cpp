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

int a[1010];

vector <int> vec[1010], ans;

int main(){
	setIO();

	int n, num, sz = 0, idx, last, now;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		idx = lower_bound(a, a+sz, num) - a;
		if(idx==sz)
			sz++;
		a[idx] = num;
		vec[idx].push_back(num);
	}

	for(int i = sz - 1; i >= 0; i--){
		if(i==sz-1){
			ans.push_back(a[i]);
			last = a[i];
			continue;
		}
		for(int j = vec[i].size() - 1; j >= 0; j--){
			if(vec[i][j] >= last){
				break;
			}
			else{
				now = vec[i][j];
			}
		}
		last = now;
		ans.push_back(last);
	}
	cout << sz << "\n";
	for(int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i] << " ";
	}
    return 0;
}