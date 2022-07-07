#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e4 + 1;
vector<int> edge[N];
vector<bool> vis;
bool DFS(int node, int parent)
{
	vis[node] = 1;
	for (auto& child : edge[node]) {
		if (vis[child] && node != parent)  return true;
		else if (!vis[child]) DFS(child, node);
	}
	return false;
}
int main()
{
	FastIO;
	int n, m, st; cin >> n >> m; vis.resize(n + 1);
	for (int i = 0, x, y; i < m; i++) 
		cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x), st = x;
	cout << ((!DFS(st, -1) && m == n - 1) ? "YES" : "NO");
}