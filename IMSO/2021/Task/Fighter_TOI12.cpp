/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Brute Force
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

	int even = 0, odd = 0, evenLife, oddLife, n, num;
	bool ch = true;

	cin >> n;

	evenLife = oddLife = n;

	for(int i = 0; i < 2*n; i++){
		cin >> num;
		if(num%2){
			odd++;
			even = 0;
			if(odd >= 3){
				evenLife -= 3;
			}
			else{
				evenLife -= 1;
			}
		}
		else{
			even++;
			odd = 0;
			if(even >= 3){
				oddLife -= 3;
			}
			else{
				oddLife -= 1;
			}
		}
		if(ch && (evenLife <= 0 || oddLife <= 0)){
			if(evenLife <= 0){
				cout << 1 << "\n" << num;
			}
			else{
				cout << 0 << "\n" << num;
			}
			ch = false;
		}
	}
    return 0;
}