#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 200;
vector<int> edge[N], color;
bool ISBipartite(int node)
{
	for (auto& child : edge[node])
	{
		if (!color[child])
			color[child] = (color[node] == 1) ? 2 : 1, ISBipartite(child);
		else if(color[child] == color[node])return false;
	}
	return true;
}
void CL(int n) 
{
	color.clear();
	for (int i = 0; i < n; i++) edge[i].clear();
}
int main()
{
	FastIO;
	int n, m;
	while (cin >> n && n)
	{
		cin >> m; color.resize(n);
		for (int i = 0, x, y; i<m && cin >> x >> y; i++)  edge[x].push_back(y), edge[y].push_back(x);
		color[0] = 1;
		cout << ((ISBipartite(0)) ? "BICOLORABLE." : "NOT BICOLORABLE.") << "\n";
		CL(n);
	}
}