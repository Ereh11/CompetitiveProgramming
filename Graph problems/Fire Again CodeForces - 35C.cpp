#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int vis[2001][2001];
int n, m;
bool check(int r, int c) {
	return (r >= 1 && r <= n && c >= 1 && c <= m);
}
void BFS()
{
	int k, x, y, mx = 0; cin >> k;
	queue<pair<int, int>> qu; 
	pair<int, int> ft, ans;
	while (k-- && cin >> x >> y) qu.push({ x,y }), vis[x][y] = 1;
	while (!qu.empty())
	{
		ft = qu.front(); qu.pop();
		if (vis[ft.first][ft.second] > mx) ans = ft, mx = vis[ft.first][ft.second];
		for (int i = 0; i < 4; i++) {
			x = dx[i] + ft.first, y = dy[i] + ft.second;
			if (check(x, y) && !vis[x][y]) qu.push({ x,y }), vis[x][y] = vis[ft.first][ft.second] + 1;
		}
	}
	cout << ans.first << " " << ans.second;
}
int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	FastIO;
	cin >> n >> m; BFS();
}