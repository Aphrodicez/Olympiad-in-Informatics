/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Dijkstra K state
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

#define pb push_back

struct A{
	int u, w, state;
	bool operator < (const A& o) const{
		return w > o.w;
	}
};

priority_queue <A> he;
vector <A> g[50010];

A now;

int a[50010];

int dis[40][50010];

int main(){
	setIO();

	int n, m, l, st, en, u, v, w;
	cin >> n >> m >> l;
	cin >> st >> en;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 0; j <= l; j++){
			dis[j][i] = 1e9;
		}
	}
	while (m--){
		cin >> u >> v >> w;
		g[u].pb({v, w});
	}

	he.push({st, 0, 0});

	dis[0][st] = 0;

	while(!he.empty()){
		now = he.top();
		he.pop();
		if(now.state==l && now.u==en){
			cout << dis[now.state][en];
			return 0;
		}
		for(auto x: g[now.u]){
			if(a[x.u]==now.state+1){			
				if(dis[now.state+1][x.u] <= dis[now.state][now.u] + x.w)
					continue;
				dis[now.state+1][x.u] = dis[now.state][now.u] + x.w;
				he.push({x.u, dis[now.state+1][x.u], now.state+1});
			}
			else {
				if(dis[now.state][x.u] <= dis[now.state][now.u] + x.w)
					continue;
				dis[now.state][x.u] = dis[now.state][now.u] + x.w;
				he.push({x.u, dis[now.state][x.u], now.state});
			}
		}
	}
	
    return 0;
}