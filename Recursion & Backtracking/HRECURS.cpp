#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int solve(int indx, vector<int>& v)
{ 
	if (indx == v.size()) return 0;
	return v[indx] + solve(indx + 1, v);
}

int main()
{
	FastIO;
	
	int t, n; cin >> t;
	
	for (int i = 1; i <= t && cin >> n; i++)
	{
		vector<int> v(n); 
		for(auto&it : v) cin >> it;
		
		cout << "Case " << i << ": " << solve(0, v) << ((i < t) ? "\n" : "");
	}
}