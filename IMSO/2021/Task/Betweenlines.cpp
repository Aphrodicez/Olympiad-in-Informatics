#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int main(){
    setIO();
    int n, last, now, win = 1, unx = 1, mac = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> now;
        if(now==10){
            if(last==13)
                win++;
            unx++;
        }
        if(now==13)
            mac++;
        last = now;
    }
    cout << win << " " << unx << " " << mac << " ";
    return 0;
}