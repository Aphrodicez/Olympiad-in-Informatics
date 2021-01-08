/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Sliding Window
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

deque <int> deq;

int main(){
	setIO();

	int n, k, num, ans = -2e9, sum = 0;

	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> num;
		deq.push_back(num);
		sum += num;
		if(deq.size() > k){
			sum -= deq.front();
			deq.pop_front();
		}
		if(deq.size()==k){
			ans = max(ans, sum);
		}
	}

	cout << ans;

    return 0;
}