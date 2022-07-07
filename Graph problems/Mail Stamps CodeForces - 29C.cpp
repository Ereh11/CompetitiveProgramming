#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
unordered_map<int, vector<int>>mp;
unordered_map<int, bool> vis;
vector<int> res;
void DFS(int node)
{
	vis[node] = 1, res.push_back(node);
	for (auto& child : mp[node])
		if (!vis[child]) DFS(child);
}
int main()
{
	FastIO;
	int n, x, y; cin >> n;
	while (n-- && cin >> x >> y)
		mp[x].push_back(y), mp[y].push_back(x);
	for (auto& it : mp) 
		if (it.second.size() == 1) { x = it.first; break; }
	DFS(x);
	for (auto& it : res) cout << it << " ";
}