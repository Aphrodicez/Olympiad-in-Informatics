/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Stack
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

string s;

stack <char> st;

int main(){
	setIO();

	int ans = 0;

	cin >> s;

	for(int i = 0; i < s.size(); i++){
		if(s[i]==')'){
			if(st.empty())
				ans++;
			else 
				st.pop();
		}
		else{
			st.push(s[i]);
		}
	}

	while(!st.empty()){
		ans++;
		st.pop();
	}

	cout << ans;

    return 0;
}