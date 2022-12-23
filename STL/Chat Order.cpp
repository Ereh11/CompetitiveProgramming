#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    FastIO;
    int n; string s; cin >> n;

    vector<string> v; map<string, bool> mp;

    while (n-- && cin >> s) v.push_back(s);

    while (!v.empty()) 
    {
        if (!mp[v.back()])            
            cout << v.back() << '\n', mp[v.back()] = 1;
        v.pop_back();
    }
}