#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, time; cin >> n >> time;
	vector<int> v(n); 
    for(auto& it: v) cin >> it;

	int l = 0, r = 0, sum = 0, mx = 0, ans = 0;
	while (r < n)
	{
		if (sum + v[r] <= time) 
            sum += v[r], r++, ans++;
		else 
            ans--, sum -= v[l], l++;

		mx = max(ans, mx);
	}
	cout << mx;
}