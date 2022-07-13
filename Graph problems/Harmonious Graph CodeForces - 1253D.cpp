#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> Parent;

int Find(int node) { return (Parent[node] == node) ? node : Parent[node] = Find(Parent[node]); }

void Union(int nodeA, int nodeB) // approximatly O(1)
{
	nodeA = Find(nodeA), nodeB = Find(nodeB);
	if (nodeA != nodeB && nodeB > nodeA) swap(nodeB, nodeA);
	Parent[nodeA] = nodeB;
}
vector<pair<int, int>> vv, v;
void JoinValues()
{
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size()-1; i++)
	{
		if (vv[i + 1].first <= vv[i].second) {
			vv[i + 1].first = min(vv[i + 1].first, vv[i].first), vv[i + 1].second = max(vv[i + 1].second, vv[i].second);
			vv[i].first = 0;
		}
	}
	for (int i = 0; i < vv.size(); i++)
		if (vv[i].first) v.push_back({ vv[i].first, vv[i].second });
}
int main()
{
	FastIO;
	int n, m, ans = 0; cin >> n >> m; Parent.resize(n + 1);
	
	iota(Parent.begin(), Parent.end(), 0);
	for (int i = 0, u, v; i<m && cin >> u >> v; i++) {
		Union(u, v);
		if (u > v) swap(u, v);
		vv.push_back({ u,v });
	}
	JoinValues();

	for (int indx = 0; indx < v.size(); indx++)
		for (int j = v[indx].first; j < v[indx].second; j++)
			if (Find(j) != Find(j + 1)) Union(j, j + 1), ans++;
	
	cout << ans;

}