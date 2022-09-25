#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{

  FastIO;
  int n, k; cin >> n >> k; vector<int> v(n);
	for (auto& it : v) cin >> it;

	sort(v.begin(), v.end());

	if (!k)
		cout << ((v[0] > 1) ? v[0] - 1 : -1);
	else
		cout << ((k == n || v[k - 1] != v[k]) ? v[k - 1] : -1);
  
}