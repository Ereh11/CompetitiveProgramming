#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n; cin >> n;

    vector<int> v(n);
    for (auto& it : v) cin >> it;
    sort(v.begin(), v.end());

    int st = (n / 2) - 1, en = n - 1, cnt = 0;

    while (~st && en >= n / 2)
    {
        if (v[st] * 2 <= v[en]) st--, en--, cnt++;
        else st--;
    }

    cout << n - cnt;
}