#include <iostream>

using namespace std;

const int STR_MAX = 256;

int strlen(const char str[])
{
	int result = 0;
	while (str[++result]);

	return result;
}//strlen

int strcpy(char dest[], const char source[])
{
	int i;
	for (i = 0; source[i] && i < STR_MAX; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';

	return i;
}//strcpy

int main()
{
	char str_frst[STR_MAX];

	cout << "> ";
	cin >> str_frst;
	cout << str_frst << endl;

	cout << strlen(str_frst) << endl;

	char str_scnd[STR_MAX];

	cout << "Number of copied characters: " 
			<< strcpy(str_scnd, str_frst)
			<< endl;

	cout << str_scnd << endl;

	for (int i = 0; i < STR_MAX; i++)
	{
		cout << (!str_scnd[i] ? '0' : str_scnd[i]) << " "; 
	}
	cout << endl;

	return 0;
}//main
