#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int Dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int Dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int n, m;
vector<string> grid;
vector<vector<bool>> vis;
bool check(int r, int c) { return (r >= 0 && r < n&& c >= 0 && c < m && grid[r][c] == '1' && !vis[r][c]); }
int BFS(int i, int j)
{
	int ball = 0;
	queue<pair<int, int>> qu; qu.push({ i,j }), vis[i][j] = 1;
	while (!qu.empty())
	{
		pair<int, int> ft = qu.front();
		qu.pop(), ball++;
		for (int i = 0; i < 8; i++) 
		{
			int x = ft.first + Dx[i], y = ft.second + Dy[i];
			if (check(x, y)) qu.push({x,y}), vis[x][y] = 1;
		}
	}
	return ball;
}
int main()
{
	FastIO;
	int t; cin >> t;
	cin.ignore();
	cin.ignore();
	while (t--)
	{
		string s;
		while (getline(cin, s) && s != "") grid.push_back(s);
		n = grid.size(), m = grid[0].size();
		vis.resize(n, vector<bool>(m));
		int mx = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) if (check(i, j)) mx = max(mx, BFS(i, j));
		cout << mx << "\n" << ((t) ? "\n" : "");
		vis.clear(), grid.clear();
	}
}