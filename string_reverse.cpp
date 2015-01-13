#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string some_string;
	const char * c_string;
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	cin >> some_string;
	c_string = some_string.c_str();
	cout << some_string << endl;
	cout << c_string << endl;
	for (int i = strlen(c_string) - 1; i >= 0; i--)
	{
		cout << c_string[i];
	}
	cout << endl;
	return 0;
}