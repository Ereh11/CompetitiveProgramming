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
        int n; string s;  cin >> n >> s;
        bool b = 1;
        vector<int> frq(27);

        frq[s[0] - 65]++;

        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1] && frq[s[i] - 65]) {
                b = 0;
                break;
             }
            frq[s[i] - 65]++;
        }
        
        cout << (b ? "YES" : "NO");

        cout << (t ? "\n" : "");
    }
}