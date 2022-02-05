#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
    int t; cin >> t;
	while (t--)
	{
		int s, v; cin >> s; v = ceil(sqrt(s));
		cout << v;
		if (t) cout << '\n';
	}
}
