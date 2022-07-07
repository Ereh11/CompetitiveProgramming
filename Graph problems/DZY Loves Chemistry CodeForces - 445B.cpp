#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 51;
vector<int> vis, edge[N]; long long cnt = 0;
void DFS(int node)
{
	vis[node] = 1;
	for (auto& child : edge[node])
		if (!vis[child]) cnt++, DFS(child);
}
int main()
{
	FastIO;
	int n, m; cin >> n >> m; vis.resize(n + 1);
	for (int i = 0, x, y; i < m; i++) 
		cin >> x >> y, edge[x].push_back(y), edge[y].push_back(x);
	for (int i = 1; i <= n && m; i++)  DFS(i);
	cout << (1LL << cnt);
}