#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int q;
    cin >> q;
    string s, t, p; 
    while(q-- && cin >> s >> t >> p)
    {
        
        vector<int> frq(26);
        for (auto& it : p) frq[it - 97]++;
    
        bool ok = 1;
        int indx = 0;

        for (auto& it : t)
        {
            if (indx < s.size() && s[indx] == it) indx++;
            else
            {
                if (frq[it - 97] > 0) frq[it - 97]--;
                else ok = 0;
            }
        }

        cout << ((indx == s.size() && ok) ? "YES" : "NO") << ((q) ? "\n" : "");
    }
}