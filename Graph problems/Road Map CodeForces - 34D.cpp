#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int  N = 5 * 1e5 + 1;
vector<int> edge[N], par(N);
void DFS(int node, int parent) 
{
	par[node] = parent;
	for (int &child : edge[node]) {
		if (child != parent) DFS(child, node);
	}
}
int main()
{

	FastIO;
	int n, r1, r2, parent; cin >> n >> r1 >> r2;
	for (int i = 1; i <= n; i++) {
		if (i != r1) 
			cin >> parent, edge[parent].push_back(i), edge[i].push_back(parent);
	}
	DFS(r2, -1);
	for (int i = 1; i <= n; i++) if (i != r2) cout << par[i] << " ";
}