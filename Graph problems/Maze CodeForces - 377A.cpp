#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, m, k, comp = 0; pair<int, int> st;
vector<vector<char>> grid;
bool vis[501][501];
bool check(int r, int c) { return(r >= 0 && r < n&& c >= 0 && c < m && !vis[r][c] && grid[r][c] == '.'); }
void BFS()
{
	queue<pair<int, int>> qu; pair<int, int> ft;
	qu.push(st); vis[st.first][st.second] = 1;
	grid[st.first][st.second] = '*', comp--;
	while (!qu.empty())
	{
		ft = qu.front(); qu.pop();
		for (int i = 0; i < 4 && comp; i++)
		{
			int x = ft.first + dx[i], y = ft.second + dy[i];
			if (check(x, y))
				comp--, grid[x][y] = '*', qu.push({ x,y }), vis[x][y] = 1;
		}
	}
}
int main()
{
	FastIO;
	cin >> n >> m >> k; grid.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> grid[i][j], ((grid[i][j] == '.') ? st = { i,j }, comp++ : 0);

	comp -= k;
	BFS();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
		{
			if (grid[i][j] == '#') cout << '#';
			else cout << ((grid[i][j] == '*') ? '.' : 'X');
		}
		cout << ((i != n - 1) ? "\n" : "");
	}
}