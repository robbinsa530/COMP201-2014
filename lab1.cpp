#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	const char * c_string; //git bash won't open input file with name as a regular string. use this instead
	string name;
	ifstream input;
	ofstream output;
	int count = 0, sum = 0, temp;
	vector<int> nums;
	cout << "Enter the file you wish to open: ";
	cin >> name;
	
	c_string = name.c_str(); //change string to c-string so git bash will accept it
	
	input.open(c_string);
	if (input.fail()) //check to see if input file opened
	{
		cout << "Could not open input file\n";
		return 1;
	}
	output.open("output.txt");
	if (output.fail()) //check to see if output file opened
	{
		cout << "Could not open output file\n";
		return 1;
	}
	output << "x\tx^2\tCurrent Sum\n";
	output << "=\t===\t===========\n";

	while (input >> temp)
	{
		nums.push_back(temp); //add integers to vector
		sum = sum + nums[count]; //update total sum
		output << nums[count] << "\t" << nums[count] * nums[count] << "\t" << sum << endl; //output info
		count++; //update integer count
	}
	return 0;
}
