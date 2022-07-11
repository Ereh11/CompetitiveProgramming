#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 1;

vector<bool> vis;
vector<pair<int, bool>> edge[N];
void BFS()
{
	queue<pair<int, int>> qu; pair<int, int> ft;
	qu.push({ 1,1 });  vis[1] = 1;
	unordered_set<int> ans;
	while (!qu.empty())
	{
		ft = qu.front(); qu.pop();
		for (auto& child : edge[ft.first])
		{
			if (!vis[child.first]) 
			{
				if (!child.second) 
					ans.erase(ft.second), ans.insert(child.first), qu.push({ child.first,child.first });
				qu.push({ child.first, ft.second }), vis[child.first] = 1;
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto& it : ans) cout << it << " ";
}
int main()
{
	FastIO;
	int n; cin >> n;  vis.resize(n + 1);
	for (int i = 0, u, v, type; i<n - 1 && cin >> u >> v >> type; i++)
		edge[u].push_back({ v, 2 - type }), edge[v].push_back({ u, 2 - type });
	BFS();
}