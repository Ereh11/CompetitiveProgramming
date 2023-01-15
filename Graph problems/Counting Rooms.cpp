#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
//const int N = 1e4 + 2;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool vis[1000][1000];
int n, m;
bool valid(int r, int c) { return (r < n && ~r && c < m && ~c); }
void BFS(int r, int c, vector<vector<char>>& v)
{
    queue<pair<int, int>> qu; qu.push({ r, c }), vis[r][c] = 1;
    while (!qu.empty())
    {
        pair<int, int> ft = qu.front(); qu.pop();
       
        for (int i = 0; i < 4; i++)
        {
            int x = ft.first + dx[i], y = ft.second + dy[i];
            if (valid(x, y) && v[x][y] == '.' && !vis[x][y]) 
                v[x][y] = 1, qu.push({ x,y });
        }
    }
}
int main()
{
    FastIO;
    int ans = 0; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto& r : v)
        for (auto& c : r) cin >> c;

    memset(vis, 0, sizeof(vis));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && v[i][j] == '.') ans++, BFS(i, j, v);

    cout << ans;
}