#include <iostream>
using namespace std;
 int pow(int s);

int main()
{
	cout << "The cube of 3 is: " << pow(3) << "\n";
	return 0;
}
 int pow(int s) { return s * s * s; }

