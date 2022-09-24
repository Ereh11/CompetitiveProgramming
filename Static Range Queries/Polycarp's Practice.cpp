#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{

  FastIO;
  int n, k, profit = 0, cnt = 0; cin >> n >> k;
 
	vector<int> v(n), vecTsort, wanted(2e3 + 1); 
 
	for (auto& it : v) cin >> it;
 
	vecTsort = v, sort(vecTsort.begin(), vecTsort.end()), cnt = k;
 
	for (int i = n - 1; i >= 0 && cnt--; i--) wanted[vecTsort[i]]++, profit += vecTsort[i];
	cout << profit << "\n", cnt = 0;
 
	for (int i = 0; i < n; i++)
		if (wanted[v[i]]) 
			cout << ((k != 1) ? cnt + 1 : cnt + (n - i)) << " ", wanted[v[i]]--, k--, cnt = 0;
		else cnt++;
}