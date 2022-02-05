#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
bool isLucky(int a)
{
	string v = to_string(a);
	for (int i = 0; i < v.size(); i++) if (v[i] != '4' && v[i] != '7') return false;
	return true;
}
int main()
{
        { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
        int n; cin >> n;
	for (int i = 1; i <= n; i++) if (n % i == 0 && isLucky(i)) { cout << "YES"; return 0; }
	cout << "NO";
}
