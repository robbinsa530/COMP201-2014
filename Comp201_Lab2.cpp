#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

//function that pops newest two values off stack and updates the stack (made to shorten code a little)
void temps(vector<int> &n, int &t1, int &t2);

int main()
{
	vector<string> strings;
	vector<int> nums;
	string s;
	char *end;
	int i = 0, temp1, temp2;

	cout << "Enter your postfix expression, then type \"done\" : ";
	
	//keep taking in input until the user specifies they are done
	while (cin >> s)
	{
		if (s == "done")
		{
			break;
		}
		strings.push_back(s);
	}

	//runs postfix algorithm a number of times equal to the amount of input characters (numbers and operators)
	while (i < strings.size())
	{
		if (strings[i] == "+")
		{
			//fail-safe in every operator option to make sure there are enough values to operate on
			if (nums.size() < 2)
			{
				cout << "Not enough values entered.\n";
				return 1;
			}
			temps(nums, temp1, temp2);
			nums.push_back(temp1 + temp2);
		}
		else if (strings[i] == "-")
		{
			if (nums.size() < 2)
			{
				cout << "Not enough values entered.\n";
				return 1;
			}
			temps(nums, temp1, temp2);
			nums.push_back(temp2 - temp1);
		}
		else if (strings[i] == "*")
		{
			if (nums.size() < 2)
			{
				cout << "Not enough values entered.\n";
				return 1;
			}
			temps(nums, temp1, temp2);
			nums.push_back(temp1 * temp2);
		}
		else if (strings[i] == "/")
		{
			if (nums.size() < 2)
			{
				cout << "Not enough values entered.\n";
				return 1;
			}
			temps(nums, temp1, temp2);
			nums.push_back(temp2 / temp1);
		}
		else
		{
			//if entered character is a number, add it to the number vector ("place it on the stack")
			nums.push_back(strtol(strings[i].c_str(), &end, 10));
		}
	
	i++;
	}

	//check to make sure there is only one value (the answer) on the stack at the end of the algorithm
	if (nums.size() > 1)
	{
		cout << "Too many values entered.\n";
		return 1;
	}

	cout << endl << nums.back() << endl << endl;
	return 0;
}

void temps(vector<int> &n, int &t1, int &t2)
{
	t1 = n.back();
	n.pop_back();
	t2 = n.back();
	n.pop_back();
} 