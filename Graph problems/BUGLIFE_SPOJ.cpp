#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+1;
vector<bool> vis;
vector<int> edge[N], color;
bool ans = 0;
void CL() { 
	ans = 0; 
	for (auto& it : edge) it.clear();
}
void DFS(int node)
{
	vis[node] = 1;
	for (auto& child : edge[node]) {
		if (!vis[child]) {
			color[child] = 3 - color[node];
			DFS(child);
		}
		else if(vis[child] && color[child] == color[node]) { ans = 1; return; }
	}
}
int main()
{
	FIO;
    int t; cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, m; cin >> n >> m;
		vis.resize(n + 1), color.resize(n + 1);
		for (int i = 0, u, v; i < m; i++) cin >> u >> v, edge[u].push_back(v), edge[v].push_back(u);
		for (int i = 1; i <= n; i++) if (!vis[i]) color[i] = 1, DFS(i);
		cout << "Scenario #" << i << ":" << "\n" << ((ans) ? "Suspicious bugs found!" : "No suspicious bugs found!") << "\n";
		CL(); vis.clear(), color.clear();
	}
}