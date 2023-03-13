#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FastIO;
    string s;
    cin >> s;

    int l = 0, r = 0, ans = 0;

    while(l <= r && r < s.size())
    {

        if(s[l] != s[r])
            l++;
        else if(s[l] == s[r])   {
            ans = max(ans, r - l + 1);
            r++;
        }
    }

    cout << ans;
}