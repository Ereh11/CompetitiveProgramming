#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
const int  N = 1e5 + 1;
ll dp[N]; vector<int> d;
ll Frog(int x) {
	if (x + 1 == d.size()) return 0;
	if (~dp[x]) return dp[x];
	ll a = LLONG_MAX, b = LLONG_MAX;
	if (x + 1 < d.size())  a = abs(d[x + 1] - d[x]) + Frog(x + 1);
	if (x + 2 < d.size())  b = abs(d[x + 2] - d[x]) + Frog(x + 2);
	return dp[x] = min(a, b);
}
int main()
{
	memset(dp, -1, sizeof dp);
	int n; cin >> n; d.resize(n); 
	for(int i=0;i<n;i++) cin>>d[i];
	cout << Frog(0);
}