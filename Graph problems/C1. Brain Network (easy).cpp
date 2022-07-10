#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N= 1001;
vector<int> vis, edge[N]; int Cntcompnent = 0;
void DFS(int node)
{
	vis[node] = 1;
	for (auto& child : edge[node])
		if (!vis[child]) DFS(child);
}
int main()
{
	FastIO;
	int n, m; cin >> n >> m;  vis.resize(n + 1);
	for (int i = 0, u, v; i < m && cin >> u >> v; i++) edge[u].push_back(v), edge[v].push_back(u);
	for (int i = 1; i <= n && Cntcompnent <= 1; i++)
		if (!vis[i]) DFS(i), Cntcompnent++;
	cout << ((m == n - 1 && Cntcompnent == 1) ? "yes" : "no");
}