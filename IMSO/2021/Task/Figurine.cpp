#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

ll a[150010];

int main(){
    setIO();

    ll n, amt, i, ans = 0, cnt = 0;
    
    cin >> n;
    
    amt = n/5;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater<ll>());

    for(i = 1; i <= 2*amt; i+=2){
        ans += a[i];
    }

    for(; i <= n; i++){
        ans += a[i];
    }

    cout << ans;
    return 0;
}