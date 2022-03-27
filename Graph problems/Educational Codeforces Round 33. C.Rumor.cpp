#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int  N = 1e5 + 1;
vector<bool> vis; vector<int> v[N]; vector<ll> val; ll mn = LONG_MAX;
void DFS(int node)
{
	mn = min(mn, val[node]);
	vis[node] = 1;
	for (auto child : v[node])
		if (!vis[child]) DFS(child);
}
int main()
{
	int n, m, x, y; cin >> n >> m; vis.resize(n + 1), val.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> x, val[i] = x;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y), v[y].push_back(x);
	}
	ll cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			DFS(i), cnt += mn, mn = LONG_MAX;
	cout << cnt;
}