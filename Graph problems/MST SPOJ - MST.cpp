#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> Parent, ParentSZ;

int Find(int node) { return (Parent[node] == node) ? node : Parent[node] = Find(Parent[node]); }

void Union(int nodeA, int nodeB) // approximatly O(1)
{
	nodeA = Find(nodeA), nodeB = Find(nodeB);
	if (nodeA != nodeB && ParentSZ[nodeB] > ParentSZ[nodeA]) swap(nodeB, nodeA);
	Parent[nodeA] = nodeB;
}
vector<pair<int, pair<int, int>>> vc;
long long Kruskal()
{
	long long cost = 0;
	sort(vc.begin(), vc.end());
	for (auto& it : vc)
		if (Find(it.second.first) != Find(it.second.second)) 
			cost += it.first, Union(it.second.first, it.second.second);
	return cost;
}
int main()
{
	FastIO;
	int n, m, u, v, cost; cin >> n >> m; Parent.resize(n + 1), ParentSZ.resize(n + 1);
	iota(Parent.begin(), Parent.end(), 0);
	while (m-- && cin >> u >> v >> cost) vc.push_back({ cost,{u,v} });
	cout << Kruskal();
}
