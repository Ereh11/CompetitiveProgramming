#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    FastIO;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n; 
        vector<int> v(n);
        for (auto& it : v) cin >> it;
        sort(v.begin(), v.end());
        int mn = 1001;
        for (int i = n - 1; i > 0; i--) 
              mn = min(mn, v[i] - v[i - 1]);

        cout << mn;

        cout << ((t) ? "\n" : "");
    }
}