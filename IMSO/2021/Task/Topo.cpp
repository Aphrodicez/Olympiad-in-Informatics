/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Topological Sort
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int deg[100010];

vector<int> g[100010], ans;

queue <int> qu;

int main(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		deg[v]++;
		g[u].push_back(v);
	}
	for(int i = 1; i <= n; i++){
		if(deg[i]==0){
			qu.push(i);
		}
	}
	while(!qu.empty()){
		u = qu.front();
		qu.pop();
		ans.push_back(u);
		for(auto x: g[u]){
			deg[x]--;
			if(deg[x]==0)
				qu.push(x);
		}
	}
	if(ans.size() != n){
		cout << "no";
	}
	else{
		for(int x: ans){
			cout << x << " ";
		}
	}
    return 0;
}