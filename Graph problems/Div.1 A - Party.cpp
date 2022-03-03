#include <bits/stdc++.h>
using namespace std;
const int  N = 2 * 1e3 + 1;
vector<int> d[N];
int mx = 0; bool vis[N];
void DFS(int node, int path) {
	vis[node] = 1;
	for (auto it : d[node])
		if (!vis[it]) DFS(it, 1 + path);
	mx = max(mx, path);
}
int main()
{
	int n, y; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >>y;
		d[max(y, 0)].push_back(i + 1);
	}
	for (int i = 0; i <= n; i++)
		if (!vis[i])DFS(i, 0);
	cout << mx;
}