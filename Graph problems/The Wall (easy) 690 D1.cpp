#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int Dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int Dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int n, m, cntB = 0;
vector<vector<char>>v;
bool vis[101][101];
bool check(int r, int c) { return(r >= 0 && r < n&& c >= 0 && c < m && !vis[r][c] && v[r][c]=='B'); }
void BFS(pair<int, int> p)
{
	queue<pair<int, int>>qu; 
	qu.push(p);
	cntB++, vis[p.first][p.second] = 1;
	while (!qu.empty())
	{
		pair<int, int> ft = qu.front(); qu.pop();
		for (int i = 0; i < 8; i++)
		{
			int x = ft.first + Dx[i], y = ft.second + Dy[i];
			if (check(x, y)) qu.push({ x,y }), vis[x][y] = 1;
		}
	}
}
int main()
{
	FastIO;
	cin >> n >> m; v.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> v[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (check(i, j)) BFS({ i,j });
	cout << cntB;
}