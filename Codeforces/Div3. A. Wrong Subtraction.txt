#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
    int n, k; cin >> n >> k;
	while (k--) { ((n % 10)!=0) ? --n : n /= 10; }
	cout << n;
}
