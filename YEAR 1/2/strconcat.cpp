#include <iostream>

using namespace std;

const int MAX_LEN = 1024;

int strsize(char* ptr_str)
{
	int result = 0;
	while (*(ptr_str++) && ++result < MAX_LEN);
	
	return result;
}//strsize

void strconcat(char* ptr_frst, char* ptr_scnd, char* ptr_dest)
{
	while (*ptr_frst)
	{
		*(ptr_dest++) = *(ptr_frst++);
	}
	while (*ptr_scnd)
	{
		*(ptr_dest++) = *(ptr_scnd++);
	}
	*ptr_dest = '\0';
}//strconcat

int main()
{
	cout << "First string: ";
	char str_frst[MAX_LEN];
	cin >> str_frst;
	cout << "Second string: ";
	char str_scnd[MAX_LEN];
	cin >> str_scnd;	
	char str_dest[MAX_LEN];
	strconcat(str_frst, str_scnd, str_dest);

	cout << str_dest << endl;

	return 0;
}//main
