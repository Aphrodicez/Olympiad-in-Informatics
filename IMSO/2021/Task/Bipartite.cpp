/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Bipartite Graph Check
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

vector <int> g[100010];

int mark[100010], res;

int check(int u, int color){
	if(mark[u]){
		if(mark[u]==color)
			return 1;
		else
			return 0;
	}
	mark[u] = color;
	for(int x: g[u]){
		if(check(x, 3 - color) == 0)
			return 0;
	}
	return 1;
}

int main(){
	setIO();

	int q, n, m, u, v;
	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(check(1, 1))
			cout << "yes\n";
		else 
			cout << "no\n";
		for(int i = 1; i <= n; i++){
			g[i].clear();
		}
		memset(mark, 0, sizeof mark);
	}
    return 0;
}