#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const long long v_v = 1LL << 32;
int main()
{
    FastIO;
    int q; 
    long long  x, ans = 0; 
    cin >> q;
    string s; stack<long long> fr;

    while (q-- && cin >> s)
    {
        if (s == "for")
            cin >> x, fr.push(min(v_v, (fr.empty() ? 1 : fr.top()) * x));
        else if (s == "add")
            fr.empty() ? ans++ : ans += fr.top();
        else fr.pop();
    }

    if (ans >= v_v) cout << "OVERFLOW!!!";  
    else cout <<  ans;
}