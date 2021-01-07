/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Binary Search Tree
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

struct node{
	int val;
	node *left;
	node *right;
};

node* createNode(int val){
	node *tmp = new node;
	tmp -> val = val;
	tmp -> left = NULL;
	tmp -> right = NULL;
	return tmp;
}

void Insert(node *now, int val){
	if(val < now->val){
		if(now->left==NULL){
			node *tmp = createNode(val);
			now->left = tmp;
		}
		else{
			Insert(now->left, val);
		}
	}
	else{
		if(now->right==NULL){
			node *tmp = createNode(val);
			now->right = tmp;
		}
		else{
			Insert(now->right, val);
		}
	}
}

bool check(node *now, int val){
	if(val==now->val){
		return true;
	}
	else if(val < now->val){
		if(now->left==NULL){
			return false;
		}
		else{
			return check(now->left, val);
		}
	}
	else{
		if(now->right==NULL){
			return false;
		}
		else{
			return check(now->right, val);
		}
	}
}

int a[200010];

node *root;

void divide(int l, int r){
	if(l==r){
		Insert(root, a[l]);
		return;
	}
	if(l+1==r){
		Insert(root, a[l]);
		Insert(root, a[r]);
		return;
	}
	int mid = (l+r) / 2;
	Insert(root, a[mid]);
	divide(l, mid-1);
	divide(mid+1, r);
}

int main(){
	setIO();

	int n, m, num;

	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);

	int l = 1, r = n;
	int mid = (l+r) / 2;

	root = createNode(a[mid]);
	divide(l, mid-1);
	divide(mid+1, r);

	for(int i = 0; i < m; i++){
		cin >> num;
		if(check(root, num))
			cout << "y\n";
		else
			cout << "n\n";
	}
    return 0;
}