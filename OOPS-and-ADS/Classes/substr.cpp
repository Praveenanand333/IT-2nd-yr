#include<bits/stdc++.h>
using namespace std;
void subString(char str[], int n)
{
	// Pick starting point
	for (int len = 1; len <= n; len++)
	{	
		// Pick ending point
		for (int i = 0; i <= n - len; i++)
		{
			// Print characters from current
			// starting point to current ending
			// point.
			int j = i + len - 1;			
			for (int k = i; k <= j; k++)
				cout << str[k];
			
			cout << endl;
		}
	}
}
int main()
{
	char str[] = "abcd";
	subString(str, strlen(str));
	return 0;
}
