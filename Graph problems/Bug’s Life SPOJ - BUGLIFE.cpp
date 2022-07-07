#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 2001;
vector<int> edge[N], color; bool ok = 1;
void ISbipartite(int node)
{
	for (auto& child : edge[node]) {
		if (!color[child] && ok) color[child] = (color[node] == 1) ? 2 : 1, ISbipartite(child);
		else if(color[child] == color[node]) ok = 0;
	}
}
void CL(int n)
{
	ok = 1, color.clear();
	for (int i = 1; i <= n; i++) edge[i].clear();
}
int main()
{
	FastIO;
	int t; cin >> t;
	for (int i = 1, n, m; i <= t && cin >> n >> m; i++)
	{
		color.resize(n + 1);
		for (int i = 1, x, y; i <= m && cin >> x >> y; i++) 
		    edge[x].push_back(y), edge[y].push_back(x);
		for (int i = 1; i <= n && ok; i++)
			if (!color[i]) color[i] = 1, ISbipartite(i);
		cout << "Scenario #" << i << ":\n";
		cout << ((ok) ? "No suspicious bugs found!" : "Suspicious bugs found!") << ((i != t) ? "\n" : "");
		CL(n);
	}
}