#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

int a[1010], mark[1010];

deque <int> deq;

int main(){
    setIO();
    
    int n, m, mxCapa, nowCapa = 0, now, fro;
    
    cin >> n >> m >> mxCapa;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> now;
        if(mark[now]){
            deq.push_back(now);
            mark[now]++;
            continue;
        }
        else{
            while(!deq.empty() && nowCapa + a[now] > mxCapa){
                fro = deq.front();
                deq.pop_front();
                mark[fro]--;
                if(!mark[fro]){
                    nowCapa -= a[fro];
                }
            }
            deq.push_back(now);
            mark[now]++;
            nowCapa += a[now];
        }
    }
    
    cout << mxCapa - nowCapa;
    return 0;
}