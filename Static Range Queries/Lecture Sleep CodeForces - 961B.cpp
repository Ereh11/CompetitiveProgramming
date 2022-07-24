#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, k, ans = 0, curr = 0, sum = 0; cin >> n >> k;
	vector<int> lecture(n + 1), pfx(n + 2), time(n + 1);
 
	for (int i = 1; i <= n; i++) cin >> lecture[i];
	for (int i = 1; i <= n; i++) cin >> time[i];
 
	for (int i = 1; i <= n; i++) 
		pfx[i] = pfx[i-1] + ((!time[i]) ? lecture[i] : 0), sum += ((time[i]) ? lecture[i] : 0);
 
	for (int i = k; i <=n; i++) 
		ans = max(ans, (pfx[i] - pfx[i - k]));
	
	cout << ans + sum;
}
