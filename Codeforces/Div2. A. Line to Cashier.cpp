#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
    int n; cin >> n; vector<int> d(n);
	for (int i = 0; i < n; i++) cin>>d[i];
	for (int i = 0; i < n; i++)
	{
		int sum = 0, x;
		for (int j = 0; j < d[i]; j++) { cin >> x; sum += (x * 5); }
		sum += d[i] * 15;
		d[i] = sum;
	}
	cout << *min_element(d.begin(), d.end());
}
