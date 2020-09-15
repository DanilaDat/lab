
#include <iostream>
#include <iomanip> 
using namespace std;


bool Solve(double a, double b, double& x)
{
	b = b * (-1);
	x = b / a;
	return true;
}


int main()
{
	int a, b;
	cout << "input a,b:\n";
	cin >> a >> b;
	double x = 0;
	bool temp = Solve(a, b, x);
	cout << setw(10) << setfill('+');
	cout << x << endl;
	system("pause");
}



