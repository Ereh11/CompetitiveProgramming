#include <iostream>
#include <vector>
using namespace std;
int main()
{
   long long n, m, res = 0, str; cin >> n >> m; vector<int> d(m + 1);
   for (int i = 1; i <= m; i++) cin >> d[i];
   for (int i = 1; i <= m; i++)
	{
		if (i == 1) str = d[1], res += d[i] - 1;
		else if(d[i] > str) res += d[i] - str, str = d[i];
		else if(d[i] < str) res += ((n - str) + d[i]), str = d[i];
	}
	cout << res;
}
