#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int  t, a, b; cin >> t;
	while (t-- && cin >> a>>b)
		cout << (max(a, b) ^ min(a, b)) << ((t) ? "\n" : "");
}
