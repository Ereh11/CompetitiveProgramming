#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 101;
int cntnode = 0, cntCycle = 0;
vector<int> edge[N], vis;
void DFS(int node)
{
	vis[node] = 1, cntnode++;
	for (auto& child : edge[node]) 
	{
		if (!vis[child]) DFS(child);
		else if(vis[child] == 2) cntCycle++;
	}
	vis[node] = 2;
}
int main()
{
	FastIO;
	int n, m; cin >> n >> m; vis.resize(n + 1);
	for (int i = 0, u, v; i<m && cin >> u >> v; i++) edge[v].push_back(u), edge[u].push_back(v);
	DFS(1);
	cout << ((cntnode == n && cntCycle == 1) ? "FHTAGN!" : "NO");
}