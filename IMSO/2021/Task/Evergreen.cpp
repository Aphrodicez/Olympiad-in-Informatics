#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

// st = firstDay of removal
// rem = current day of removal
// Amount to remove
// Even = rem * (rem + 1)
// Odd = rem * rem

ll b[1010];

vector <ll> a;

ll calDis(ll now, ll dis){
    ll st = (dis / 2) + 1;
    ll rem = max(now - st + 1, 0ll);
    return rem;
}

int main(){

    ll n, k, dis, st, rem;

    cin >> n >> k;
    
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(b, b+n);

    b[n] = -1;

    for(ll j = 0, i = 0; j < n; j++){
        if(b[j]!=b[j+1]){
            a.push_back(b[j]);
        }
    }

    n = a.size();

    ll l = 0, r = 1e9; // k <= 1e17

    while(l < r){
        
        ll sum = 0, ch = 0, mid;
        
        mid = l + (r-l) / 2;
        
        sum += (mid+1) * (mid+1);
        
        if(sum >= k){
            ch = 1;
        }

        for(ll i = 1; i < n; i++){
            dis = a[i] - a[i-1] - 1;
            rem = calDis(mid, dis);
            if(dis%2==0){
                sum -= rem*(rem+1);
            }
            else{
                sum -= rem*rem;
            }
            sum += (mid+1) * (mid+1);
            if(sum >= k){
                ch = 1;
                break;
            }
        }
        if(ch){ 
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }

    cout << l;

    return 0;
}