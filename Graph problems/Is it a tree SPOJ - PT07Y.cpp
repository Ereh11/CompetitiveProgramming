#include <bits/stdc++.h>
using namespace std;
#define Fast_InputOutput {ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);}
int n, m;
vector<vector<int>>d; vector<bool> vist;
bool IsCycle(int x, int p)
{
	vist[x] = 1;
	for (auto it : d[x]){
		if (vist[it] && p != it) return true;
		else if(!vist[it]) if (IsCycle(it, x)) return true;
	}
	return false;
}
int main()
{
	Fast_InputOutput;
	int x, y, Stnode; cin >> n >> m; 
	vist.resize(n + 1), d.resize(n + 1);
	for (int i = 0; i < m; i++){
		cin >> x >> y;
		d[x].push_back(y), d[y].push_back(x), Stnode = x;
	}
	cout << ((m == n - 1 && !IsCycle(Stnode, -1)) ? "YES" : "NO");
}
