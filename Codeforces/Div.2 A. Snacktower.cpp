#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int n, x, val; cin >> n; vector<bool> chk(n + 1); val = n;
	for (int i = 0; i < n; i++)
	{
		cin >> x, chk[x] = 1;
		while (chk[val]) cout << val << " ", chk[val] = 0, val--;
		if (i != n - 1)cout << '\n';
	}
	return 0;
}