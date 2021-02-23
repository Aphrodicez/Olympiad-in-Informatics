/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Bitmask
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int a[20], b[20];

int main(){
	setIO();
	int n, i, abit, bbit, all, cnta, cntb, suma, sumb, sum, ans = 1e9;

	cin >> n;

	all = (1 << n) - 1;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	for(int k = 0; k <= all; k++){
		abit = k;
		bbit = abit ^ all;
		sum = suma = sumb = 0;
		cnta = 0;
		for(int i = 0; i < n; i++){
			if(abit & (1<<i)){
				suma += a[i];
				cnta++;
			}
		}
		sum += suma * (100-cnta);
		cntb = 0;
		for(int j = 0; j < n; j++){
			if(bbit & (1<<j)){
				sumb += b[j];
				cntb++;
			}
		}
		sum += sumb * (100-cntb);
		ans = min(ans, sum);
	}

	string s = to_string(ans);

	for(i = 0; i < s.size()-2; i++){
		cout << s[i];
	}
	cout << '.';
	for(; i < s.size(); i++){
		cout << s[i];
	}

    return 0;
}
