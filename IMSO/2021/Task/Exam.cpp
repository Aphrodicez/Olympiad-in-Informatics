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

unordered_map <int, vector<int>> mp;

int a[50010], last[50010];

vector <int> del;

int main(){
	setIO();

	int n, q, l, r, lb, ub;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]].push_back(i);
	}
	for(auto &it : mp){
		if(it.second.size() < 2)
			del.push_back(it.first);
	}

	for(int &x: del){
		mp.erase(x);
	}
	cin >> q;
	while(q--){
		int sum = 0;
		cin >> l >> r;
		for(auto &it: mp){
			vector <int> vec = it.second;
			lb = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
			ub = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
			sum += (ub - lb >= 2) ? 1 : 0;
		}
		cout << sum << "\n";
	}

    return 0;
}