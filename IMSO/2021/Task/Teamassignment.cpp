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

int a[100010];

int main(){
	setIO();
	cout << "HAHA\n";
	int n, l, u, lower, upper, tmp, ans = -1;
	cin >> n >> l >> u;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1, greater <int>());
	for(int i = 1; i <= n; i++){
		tmp = a[i];
		lower = upper = n / i;
		if(n%i!=0)
			upper++;
		if(lower < l || upper > u)
			tmp = -1;
		cout << tmp << "\n";
		ans = max(ans, tmp);
	}
	cout << ans;
    return 0;
}