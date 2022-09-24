#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{

  FastIO;
  int n, mx = 0; cin >> n;
  vector<int> v(n), frq(2e5 + 1);
 
	for (auto& it : v) cin >> it;
 
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) frq[v[i] + v[j]]++, mx = max(mx, frq[v[i] + v[j]]);
 
	cout << mx;
}