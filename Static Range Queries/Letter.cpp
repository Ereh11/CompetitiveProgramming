#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
   
	string heading, text; 
	getline(cin, heading), getline(cin, text);
	
	vector<int> frq(123);

	for (auto& it : heading) frq[it]++;

	for (auto& it : text)
		if (it != 32) {
			if (frq[it])  frq[it]--;
			else return cout << "NO", 0;
		}

	cout << "YES";
}