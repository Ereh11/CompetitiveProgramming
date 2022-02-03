#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
    int n, d, ru, su = 0, x; cin >> n >> d;
	for (int i = 0; i < n; i++) { cin >> x; su += x; }
	ru = (--n * 10) + su;
	(ru > d) ? cout << -1 : cout << (ru - su) / 5 + (d - ru) / 5;
}
