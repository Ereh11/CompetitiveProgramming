#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int t, n;
    cin >> t;
    while (t-- && cin >> n)
    {
        cout << (int)ceil(n / 2.0) << ((t) ? "\n" : "");
    }
}