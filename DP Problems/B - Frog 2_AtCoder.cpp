#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
const int  N = 1e5 + 1;
ll dp[N]; vector<int> d; int k;
ll Frog(int x) {
	if (x + 1 == d.size()) return 0;
	if (~dp[x]) return dp[x];
	ll a = LLONG_MAX, mn = LONG_MAX;
	for (int i = 1; i <= k; i++) {
		if (x + i < d.size()) a = abs(d[x + i] - d[x]) + Frog(x + i);
		mn = min(mn, a);
	}
	return dp[x] = mn;
}
int main()
{
	memset(dp, -1, sizeof dp);
	int n; cin >> n >> k; d.resize(n); 
	for(int i=0;i<n;i++) cin>>d[i];
	cout << Frog(0);
}