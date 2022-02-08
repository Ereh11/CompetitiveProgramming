#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
    int a, b, co_a = 0, co_b = 0, i = 1; cin >> a >> b;
	while (i <= 6)
	{
		if (abs(i - a) < abs(i - b)) co_a++;
		else if(abs(i - a) > abs(i - b)) co_b++;
		++i;
	}
	cout << co_a << " " << 6 - (co_a + co_b) <<" "<< co_b;
}
