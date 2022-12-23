#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    FastIO;
    int n, m, k, t; string s; 
 
    cin >> n >> m >> k;
    vector<string> words(n); vector<int> cost(n); 
    unordered_map<string, long long> mp;
 
    for (auto& it : words) cin >> it;
    for (auto& it : cost) cin >> it;
 
    long long ans = 0;
    while (m-- && cin >> t)
    {
        int mn = INT_MAX; 
        vector<int> v(t);
        for (auto& it : v) cin >> it, mn = min(mn, cost[it - 1]);
        for (auto& it : v) mp[words[it - 1]] = mn;
    }
 
    for (int i = 0; i < k; i++)
         cin >> s, ans += mp[s];
 
    cout << ans;
}