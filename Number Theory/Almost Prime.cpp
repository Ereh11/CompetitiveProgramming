#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> Divisors(int n)
{
	vector<int> d; int i = 1;
	for (i = 1; (i * i) < n; i++)
		if (n % i == 0) d.push_back(i), d.push_back(n / i);
	if ((i * i) == n) d.push_back(i);
	return d;
}

bool check(int n) {
	for (int i = 2; i <= n / 2; i++) 
		if (!(n % i)) return 0;
	return (n > 1);
}

int main()
{
    FastIO;
    int n, ans = 0; cin >> n;

	for (int i = 6; i <= n; i++) 
    {
		int cnt = 0; 
        vector<int> divs = Divisors(i);

		for (auto& it : divs) cnt += check(it);
		ans += (cnt == 2);
	}

	cout << ans;
}