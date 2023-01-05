#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    FastIO;
    int n, mx = 0; cin >> n; 
    vector<int> frq(101);
    for (int i = 0, x; i < n; i++)
        cin >> x, frq[x]++, mx = max(mx, frq[x]);

    cout << mx;
}