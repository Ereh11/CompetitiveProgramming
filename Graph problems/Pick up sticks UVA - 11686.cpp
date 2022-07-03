#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e6 + 1;
vector<int>vis, edge[N], ans;
bool iscyclic = 0;
void DFS(int node)
{
	vis[node] = 1;
	for (auto& child : edge[node])
	{
		if (!vis[child] && !iscyclic) DFS(child);
		else if (vis[child] == 1) { iscyclic = 1; return; }
	}
	vis[node] = 2, ans.push_back(node);
}
void CL(int n)
{
	vis.clear(), ans.clear(), iscyclic = 0;
	for (int i = 1; i <= n; i++) edge[i].clear();
}
int main()
{
	FastIO;
	int n, m, x, y;
	while (cin >> n >> m, n || m)
	{
		vis.resize(n + 1);
		while (m-- && cin >> x >> y) edge[x].push_back(y);
		for (int i = 1; i <= n && !iscyclic; i++) if (!vis[i]) DFS(i);
		if (!iscyclic)
			for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << "\n";
		else cout << "IMPOSSIBLE\n";
		CL(n);
	}
}