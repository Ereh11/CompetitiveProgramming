#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{

  FastIO;
  int n, mx = 0, cnt = 0; cin >> n;
	
	vector<int> v(n), frq(1e3 + 1);

	for (auto& it : v) cin >> it, frq[it]++, mx = max(mx, frq[it]);
	for (auto& it : frq) cnt += (it != 0);

	cout << mx << " " << cnt;
}