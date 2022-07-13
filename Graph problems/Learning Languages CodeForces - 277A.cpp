#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> Parent, Parent_Size;
int Find(int node)
{
	if (Parent[node] == node) return node;
	return Parent[node] = Find(Parent[node]);
}
void Union(int nodeA, int nodeB) // approximatly O(1)
{
	nodeA = Find(nodeA), nodeB = Find(nodeB);
	if (nodeA != nodeB && Parent_Size[nodeB] > Parent_Size[nodeA])
		swap(nodeB, nodeA), Parent_Size[nodeA] += Parent_Size[nodeB];
	Parent[nodeA] = nodeB;
}

int main()
{
	FastIO;
    int n, m, zero = 0; cin >> n >> m;
	Parent.resize(203), Parent_Size.resize(203);
	iota(Parent.begin(), Parent.end(), 0);

	for (int i = 1, k, x; i <= n && cin >> k; i++) 
	{
		zero += (k == 0);
		while (k-- && cin >> x) Union(x + n, i);
	}
	unordered_set<int> se;
	for (int i = 1; i <= n; i++) se.insert(Find(i));
	cout << ((zero != n) ? (se.size()) - 1 : zero);
}