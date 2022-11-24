#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
//const int N = 1e5 + 1;

int main()
{
    FastIO;

    int t, n, s; cin >> t;
    while(t-- && cin >> n >> s)
    {
        int su = 0, mx = 0; 

        vector<bool> frq(51);

        for (int i = 0, x; i < n && cin >> x; i++) 
                 frq[x] = 1, su += x, mx = max(mx, x);
        bool ok = 1;
        for (int i = 1; i <= max(mx, s); i++)
                if (!frq[i] && s - i >= 0) s -= i;
                else if (frq[i]) su -= i;
                else
                    ok = 0;

        cout << (ok && !s && !su ? "YES" : "NO") << (t ? "\n" : "");
    }
}