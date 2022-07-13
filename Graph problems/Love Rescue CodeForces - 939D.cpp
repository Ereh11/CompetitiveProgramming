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
	int n; string a, b; cin >> n >> a >> b;
	Parent.resize(27), Parent_Size.resize(27); 
	vector<pair<char, char>> ans;
	iota(Parent.begin(), Parent.end(), 0);

	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i] && Find(a[i] - 96) != Find(b[i] - 96)) 
		    ans.push_back({ a[i],b[i] }), Union(a[i] - 96, b[i] - 96);

	cout << ans.size() << ((ans.size()) ? "\n" : "");
	for (auto& it : ans) cout << it.first << " " << it.second << "\n";
}