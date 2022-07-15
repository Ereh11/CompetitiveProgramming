#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

const long long MOD = 1e9 + 7;
long long FastPow(long long a, long long b)
{
	if (!b)
		return 1;
	long long p = FastPow(a % MOD, b >> 1);
	if (b & 1)
		return (p % MOD * p % MOD * a % MOD);
	else
		return (p % MOD * p % MOD);
}

vector<int> Parent, ParentSZ;

int Find(int node) { return (Parent[node] == node) ? node : Parent[node] = Find(Parent[node]); }

void Union(int nodeA, int nodeB) // approximatly O(1)
{
	nodeA = Find(nodeA), nodeB = Find(nodeB);
	if (nodeA != nodeB && ParentSZ[nodeB] > ParentSZ[nodeA]) swap(nodeB, nodeA);
	Parent[nodeB] = nodeA, ParentSZ[nodeA] += ParentSZ[nodeB];
}

int main()
{
	FastIO;
	long long n, k; cin >> n >> k; 
	long long ans= FastPow(n, k);
	unordered_set<int> ust;
	
	Parent.resize(n + 1), ParentSZ.resize(n + 1, 1);
	iota(Parent.begin(), Parent.end(), 0);

	for(int i= 1, u, v, type; i < n &&cin>> u >> v >> type ; i++) 
	     if(!type) Union(u, v);
	
	for(int i= 1 ; i<= n ; i++) ust.insert(Find(i));
	
	for(auto &it: ust) ans= (( ans - FastPow((long long)ParentSZ[it], k)) + MOD ) % MOD;
	cout<< ans;
}
