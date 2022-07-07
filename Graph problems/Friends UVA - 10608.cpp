#include <bits/stdc++.h>
#define FastIO {ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);}
using namespace std;
const int N=3e4+1;
vector<bool> vis, v[N]; 
int n, m, cnt = 0;
void DFS(int node)
{
	vis[node] = 1, cnt++;
	for (auto child : v[node])
		if (!vis[child]) DFS(child);
}
void CL() {
	vis.clear();
	for (int i = 1; i <= n; i++) v[i].clear();
}
int main()
{
	FastIO;
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m; vis.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			v[x].push_back(y), v[y].push_back(x);
		}
		int mx = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) DFS(i), mx = max(cnt, mx), cnt = 0;
		cout << mx << "\n";
		CL();
	}
}

