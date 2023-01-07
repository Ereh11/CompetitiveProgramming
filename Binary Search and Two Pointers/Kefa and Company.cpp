#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    FastIO;
    int n, d; cin >> n >> d;

    vector<pair<int, int>> v(n);
    for (auto& it : v) 
        cin >> it.first >> it.second;

    sort(v.begin(), v.end());

    int l = 0, r = 0; ll mx=0, ans = 0;
    
    while (l < n && r < n)
    {
        if (v[r].first - v[l].first < d)
            ans += v[r].second, r++;
        else
            ans -= v[l].second, l++;

        mx = max(mx, ans);
    }

    cout << mx;
}