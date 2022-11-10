#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, ans = 0, su = 0; cin >> n; 
    
    vector<int> v(n), frq(4);

    for (auto& it : v) cin >> it, ans += it / 4, it %= 4;
    
    for (auto& it : v) if (it) frq[it]++;
    
    for (auto& it : v)
    {
        frq[it]--;
        if (frq[it] >= 0 && frq[4 - it] > 0) ans++, frq[4 - it]--;
        else frq[it]++;
    }

    for (auto& it : v)
        if(it == 3 && frq[it] > 0) ans++, frq[it]--;
        else if (frq[it] > 0) su += it, frq[it]--;

    cout << ans + ceil(su / 4.0);
}