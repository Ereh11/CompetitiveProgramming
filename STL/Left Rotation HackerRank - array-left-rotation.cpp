#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, d; cin >> n >> d;
	vector<int> v(n);
	for (int i = 0; i < n; i++)  cin >> v[i];
	for (int i = d ; i < n; i++) cout << v[i] << " ";
	for (int i = 0; i < d; i++) cout << v[i] << " ";
}