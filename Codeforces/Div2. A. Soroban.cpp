#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
	string s; cin >> s; 
	for (int i = s.size()-1; i >=0 ; i--)
	{
		int co = s[i] - 48;
		if (co == 0) cout << "O-|-OOOO";
		else if (co > 4)
		{
			cout << "-O|", co -= 5;
			for (int j = 0; j < co; j++) cout << 'O';
			cout << '-';
			for (int j = 0; j < 4 - co; j++) cout << 'O';
		}
		else
		{
			cout << "O-|";
			for (int j = 0; j < co; j++) cout << 'O';
			cout << '-';
			for (int j = 0; j < 4 - co; j++) cout << 'O';
		}
		if(i)cout << '\n';
	}
}
