#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int Dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int Dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
pair<int, int> st, en;
map<pair<int, int>, int> dist;
set<pair<int, int>> se;
void BFS()
{
	queue<pair<int, int>>qu; 
	pair<int, int> ft; qu.push(st);
	while (!qu.empty())
	{
		ft = qu.front(); qu.pop();
		if (ft == en) break;
		for (int i = 0; i < 8; i++) {
			int x = Dx[i] + ft.first,  y = Dy[i] + ft.second;
			if (se.find({ x,y }) != se.end()) 
				se.erase({ x,y }), dist[{x, y}] = dist[ft] + 1, qu.push({ x,y });
		}
	}
	cout << ((dist[en]) ? dist[en] : -1);
}
int main()
{
	FastIO;
	int n, r, x, y; cin >> st.first >> st.second >> en.first >> en.second >> n;
	while (n-- && cin >> r >> x >> y)
		for (int i = x; i <= y; i++) se.insert({ r,i });
	BFS();
}