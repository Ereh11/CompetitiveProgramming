#include <iostream>
using namespace std;
bool isvalid(int r,int c)
{
	if ((r >= 0 && r < 3) && (c >= 0 && c < 3)) return true;
	else return false;
}
int main()
{
	int grid[3][3]; bool res[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)cin >> grid[i][j], res[i][j] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i][j] & 1)
			{
				res[i][j] = (!res[i][j]);
				if (isvalid(i, j + 1))res[i][j + 1] = (!res[i][j + 1]);
				if (isvalid(i, j - 1))res[i][j - 1] = (!res[i][j - 1]);
				if (isvalid(i - 1, j))res[i - 1][j] = (!res[i - 1][j]);
				if (isvalid(i + 1, j))res[i + 1][j] = (!res[i + 1][j]);
			}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) cout << res[i][j];
		if(i!=2) cout << '\n';
	}
}