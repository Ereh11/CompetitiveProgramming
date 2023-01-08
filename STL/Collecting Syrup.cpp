#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FastIO;
    int n, mx = 0; cin >> n;

    vector<int> v(n); 
    unordered_map<int, vector<int>> mp;

    for (auto& it : v) cin >> it;
    
    for (int i = 1, x, y; i < n; i++)
        cin >> x >> y, mp[x].push_back(y), mp[y].push_back(x);

    for (auto& it : mp)
    {
        int cnt = v[it.first - 1];
        for (auto& i : mp[it.first]) cnt += v[i - 1];
        mx = max(mx, cnt);
    }

    cout << mx;
}