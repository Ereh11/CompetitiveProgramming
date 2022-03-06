#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
vector<int> d(3);
const int  N = 4 * 1e3 + 7;
int dp[N];
int CutRibbon(int n)
{
	if (n < 0) return INT_MIN;
	else if(n == 0) return 0;
	if (dp[n] != -1) return dp[n];
	int op1 = 1 + CutRibbon(n - d[0]);
	int op2 = 1 + CutRibbon(n - d[1]);
	int op3 = 1 + CutRibbon(n - d[2]);
	return dp[n] = max({ op1, op2, op3 });
}
int main()
{
	FastIO;
    int n; cin  >> n; memset(dp, -1, sizeof dp);
    for (int i = 0; i < 3; i++) cin >> d[i];
	cout << CutRibbon(n);
}