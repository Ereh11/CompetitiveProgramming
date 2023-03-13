#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

void solve(ll n)
{
    cout << n <<" ";

    if(n == 1) 
        return;

    solve((n & 1) ? ((3 * n) + 1) : (n >> 1));
}

int main()
{
    FastIO;
    ll n; cin >> n;
    solve(n);
}