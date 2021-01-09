#include <bits/stdc++.h>
#include "sockslib.h"

using namespace std;

#define pb push_back

int n;

int mark[2010];

vector <int> vec;

int solve(int l, int r, int choose){

    int mid = (l+r) / 2, resBefore, resAfter;

    if(l>=r){
        return l;
    }

    vector <int> queryL, queryR;

    for(int i = l; i <= mid; i++){
        queryL.push_back(vec[i]);
    }
    resBefore = ask(queryL);
    queryL.push_back(choose);
    resAfter = ask(queryL);
    
    if(resAfter > resBefore){
        /// pair is in another half
        return solve(mid+1, r, choose);
    }
    else{
        return solve(l, mid, choose);
    }
}

int main() {

    n = num();

    vec.resize(2*n);

    for(int i = 1; i <= 2*n; i++){
        vec[i-1] = i;
    }

    int choose, res, l, r;

    while(!vec.empty()){
        choose = vec[0];
        vec.erase(vec.begin());   
        
        l = 0, r = vec.size() - 1;
        
        res = solve(l, r, choose);
        match(choose, vec[res]);
        vec.erase(vec.begin() + res);
    }
    return 0;
}
