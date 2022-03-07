#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
ll dp[5][7490];
vector<int> d = { 1, 5, 10, 25, 50 };
ll Coins(int i, int rem)
{
	if (!rem) return 1;
	else if(i == d.size()) return 0;
	if (~dp[i][rem]) return dp[i][rem];
	return dp[i][rem] = ((d[i] <= rem) ? Coins(i, rem - d[i]) : 0) + Coins(i + 1, rem);
}	
int main()
{
	FastIO;
    int x; memset(dp, -1, sizeof dp);
	while (cin >> x){
		cout << Coins(0, x) << '\n';
	}
}