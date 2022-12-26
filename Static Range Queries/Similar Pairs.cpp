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
        int n, ans = 0; cin >> n; 

        vector<int> v(n), frqmod(2), frqdif(102);

        for (auto& it : v) cin >> it, frqmod[it % 2]++, frqdif[it]++;
    
        for (auto& it : v)
            if (frqdif[it + 1] > 0) ans += 2, frqdif[it + 1]--, frqdif[it]--;
            else if (frqdif[it - 1] > 0) ans += 2, frqdif[it - 1]--, frqdif[it]--;
            else if (frqmod[it % 2] > 1) ans += 2, frqmod[it % 2] -= 2;

        cout << (ans  >= n ? "YES" : "NO");

        cout<< (t ? "\n" : "");
    }
}