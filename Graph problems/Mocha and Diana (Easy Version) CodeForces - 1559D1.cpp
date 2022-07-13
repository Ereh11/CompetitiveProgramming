#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> Parent1, Parent_Size1, Parent2, Parent_Size2;

int Find(int node, vector<int> &Parent) { return (Parent[node] == node) ? node : Parent[node] = Find(Parent[node], Parent); }

void Union(int nodeA, int nodeB, vector<int> &Parent, vector<int> &Parent_Size) // approximatly O(1)
{
	nodeA = Find(nodeA, Parent), nodeB = Find(nodeB, Parent);
	if (nodeA != nodeB && Parent_Size[nodeB] > Parent_Size[nodeA])
		swap(nodeB, nodeA), Parent_Size[nodeA] += Parent_Size[nodeB];
	Parent[nodeA] = nodeB;
}


int main()
{
    FastIO;
	int n, m1, m2; cin >> n >> m1 >> m2; vector<pair<int, int>> ans;
	Parent1.resize(n + 1), Parent2.resize(n + 1), Parent_Size1.resize(n + 1), Parent_Size2.resize(n + 1);
	iota(Parent1.begin(), Parent1.end(), 0);
	iota(Parent2.begin(), Parent2.end(), 0);

	for (int i = 0, u, v; i<m1 && cin >> u >> v; i++) Union(u, v, Parent1, Parent_Size1);
	for (int i = 0, u, v; i<m2 && cin >> u >> v; i++) Union(u, v, Parent2, Parent_Size2);

	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			if (Find(i, Parent1) != Find(j, Parent1) && Find(i, Parent2) != Find(j, Parent2))
				Union(i, j, Parent1, Parent_Size1), Union(i, j, Parent2, Parent_Size2), ans.push_back({ i, j });
		}

	cout << ans.size() << ((ans.size()) ? "\n" : "");
	for (auto& it : ans) cout << it.first << " " << it.second << "\n";

}