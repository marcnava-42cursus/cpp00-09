#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << "String: " << str << endl;
	cout << "Memory Address" << endl;

	cout << "Memory of string: " << &str << endl;
	cout << "Memory of ptr: " << stringPTR << endl;
	cout << "Memory of ref: " << &stringREF << endl;

	cout << "Values" << endl;
	cout << "Value of string: " << str << endl;
	cout << "Value of ptr: " << *stringPTR << endl;
	cout << "Value of ref: " << stringREF << endl;
}
