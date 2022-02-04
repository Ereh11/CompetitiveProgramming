#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
      int n, co = 0; cin >> n; vector<int> d(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	sort(d.begin(), d.end());
	cout << 1 << " " << d[0] << '\n';
	if (d[1] < 0 && d[2] < 0)
	{
		cout << 2 << " " << d[1] << " " << d[2] << '\n'<< n - 3 << " ";
		for (int i = 3; i < n; i++) cout << d[i] << " ";
	}
	else
	{
		cout << 1 << " " << d[n - 1] << '\n'<< n - 2 << " " << d[1] << " ";
		for (int i = 2; i < n-1; i++) cout << d[i] << " ";
	}
}
