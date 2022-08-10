#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, m, k, ans = 0; cin >> n >> m >> k;
	vector<string> v;
 
	for (int i = 0, x; i <= m && cin >> x; i++)
	{
		bitset<32> b(x);
		v.push_back(b.to_string());
	}
	
	for (int i = 0; i < m; i++) {
	    
		int cnt = 0;
		for (int j = 0; j <= 31; j++)
			if (v[i].at(j) != v[m].at(j) && (v[i].at(j) == 49 || v[m].at(j) == 49)) cnt++;
 
		if (cnt <= k) ans++;
	}
	cout << ans;
}
