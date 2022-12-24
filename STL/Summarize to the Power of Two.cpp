#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    FastIO;
    int n, ans = 0; cin >> n; 
    vector<int> v(n);
    unordered_map<int, int> mp;
    for (auto& it : v) cin >> it, mp[it]++;

    for (auto& it : v)
    {
        bool b = 1;
        
        for (int i = 0; i <= 31; i++)
            if ((1 << i) - it == it && mp[(1 << i) - it] > 1) b = 0;
            else if ((1 << i) - it != it && mp.find((1 << i) - it) != mp.end()) b = 0;
        
        ans += b;
    }

    cout << ans;
}