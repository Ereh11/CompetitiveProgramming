#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int t; cin >> t;
	while (t--)
	{
		int n, cnt = 0; cin >> n; 
		vector<int> v(n), frqnum(102), frqmod(101);
		for (int i = 0; i < n; i++) 
		          cin >> v[i], frqnum[v[i]]++, frqmod[(v[i] % 2)]++;
		for (int i = 0; i < n; i++)
		{
			if (frqnum[v[i] - 1]) cnt += 2, frqnum[v[i] - 1]--, frqnum[v[i]]--;
			else if(frqnum[v[i] + 1]) cnt += 2, frqnum[v[i] + 1]--, frqnum[v[i]]--;
			else if (frqmod[v[i] % 2] >= 2) cnt += 2, frqmod[v[i] % 2] -= 2;
		}
		cout << ((cnt >= n) ? "YES" : "NO") << ((t) ? "\n" : "");
	}
}
