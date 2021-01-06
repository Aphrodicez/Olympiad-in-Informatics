#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int a[10010];

int main(){
    setIO();

    int r, l, n, now, ans = 0;
    
    cin >> r >> l >> n;
    
    r += l;
    for(int i = 0; i < n; i++){
        cin >> now;
        if(now < l || now > r)
            continue;
        a[now]++;
        ans = max(ans, a[now]);
    }

    cout << ans;
    return 0;
}