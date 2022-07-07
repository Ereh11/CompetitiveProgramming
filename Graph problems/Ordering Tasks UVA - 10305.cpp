#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 101;
vector<int> edge[N];
vector<bool> vis;
void DFS(int node)
{
	vis[node] = 1;
	for (auto& child : edge[node])
		if (!vis[child]) DFS(child);
	cout << node << " ";
}
void CL(int n)
{
	vis.clear();
	for (int i = 1; i <= n; i++) edge[i].clear();
}
int main()
{
	FastIO;
	int n, m;
	while (cin >> n >> m , n || m)
	{
		vis.resize(n + 1);
		for (int i = 1, x, y; i <= m && cin >> x >> y; i++) edge[y].push_back(x);
		for (int i = 1; i <= n; i++) if (!vis[i]) DFS(i);
		cout << "\n";
		CL(n);
	}
}