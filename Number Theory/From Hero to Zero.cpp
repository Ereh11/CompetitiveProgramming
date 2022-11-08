#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int t;
    long long n, m;
    cin >> t;
    while(t-- && cin >> n >> m)
    {
        long long ans = 0;
        while (n)
        {
            if (n % m) ans += n % m, n -= n % m;
            while (!(n % m) && n > 0) ans++, n /= m;
        }
        cout << ans << ((t) ? "\n" : "");
    }
}