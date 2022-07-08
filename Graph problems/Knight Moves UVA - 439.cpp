#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int kx[] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int ky[] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
map<pair<int, int>, int> vis;
vector<vector<string>>chess(65, vector<string>(65));
bool check(int r, int c) { 
	return (c >= 1 && c <= 8 && r >= 1 && r <= 8); 
}
int BFS(pair<int, int> st, pair<int, int> en)
{
	queue<pair<int, int>> qu; pair<int, int> ft;
	qu.push(st), vis[st] = 0;
	while (!qu.empty())
	{
		ft = qu.front(), qu.pop();
		if (ft == en) break;
		for (int i = 0; i < 8; i++) 
		{
			int x = ft.first + kx[i], y = ft.second + ky[i];
			if (!vis[{x, y}] && check(x, y)) 
				qu.push({x, y}), vis[{x, y}] = (vis[{ft.first, ft.second}] + 1);
		}
	}
	return vis[ft]; 
}
int main()
{
	FastIO;
	string source, target;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) chess[i][j] = char(96 + i) + to_string(j);
	while (cin >> source >> target)
	{
		pair<int, int> st, en;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++) {
				if (source == chess[i][j]) st = { i,j };
				if (target == chess[i][j]) en = { i,j };
			}
		cout << "To get from " << source << " to " << target << " takes " << BFS(st, en) << " knight moves." << "\n";
		vis.clear();
	}
}