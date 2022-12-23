#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    FastIO;
    string s, ans; cin >> s;
    map<string, int> mp;
    for (int i = 0; i < 10; i++) cin >> ans, mp[ans] = char(i + 48);
    ans.clear();

    for (int i = 0; i < s.size(); i += 10)
    {
        string tp = s.substr(i, 10);
        ans.push_back(mp[tp]);
    }

    cout << ans;
}