#include "mushrooms.h"
#include <bits/stdc++.h>
 
using namespace std;
 
/// 0 = Type A, 1 = Type B

vector <int> vec[2]; 
 
int count_mushrooms(int n) 
{
	if(n<3){
		return 2-use_machine({0, 1});
	}
	else{
		vec[0].push_back(0);
		vec[use_machine({0, 1})].push_back(1);
		vec[use_machine({0, 2})].push_back(2);
		int cnta = vec[0].size();
		for(int i = 3; i < n; ){
			int use;/// use A or B

			if(vec[0].size() >= vec[1].size())
				use = 0;
			else 
				use = 1;

			vector <int> query;

			int l;

			if(vec[use].size() > 85) 
				l = n; /// GATHER MORE MUSHROOMS
			else 
				l = min(n, i + 2);

			for(auto it = vec[use].begin(); i < l && it!=vec[use].end(); i++, it++){
				query.push_back(*it);
				query.push_back(i);
			}

			int ans = use_machine(query);

			if(query.size()==4){
				if(ans>1) 
					vec[!use].push_back(query[1]);
				else
					vec[use].push_back(query[1]);
			}
			if(ans%2==0)
				vec[use].push_back(i-1); // last one is same
			else
				vec[!use].push_back(i-1); // last one is NOT same
			if(use==0) 
				cnta += (query.size() - ans) / 2;
			else 
				cnta += (ans + 1) / 2;
		}
		return cnta;
	}
}