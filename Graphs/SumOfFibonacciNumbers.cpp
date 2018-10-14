#include <iostream>


int main()// main fibonacci program
{
	int fib1 = 0;
	int fib2 = 1;
	int fib3 = 0;
	int c;
    int sum=0;
	//decalare all variables
	std::cout << "How many fibonacci numbers do you want to sum?" << std::endl;
	std::cin >> c;
	//get user input and print the first "0" and "1"
	std::cout << fib1 << std::endl;;
	std::cout << fib2 << std::endl;
	for (int i = 0; i < c; i++)// Looping though the fibonacci algorithm
	{
		fib3 = fib1 + fib2;
        sum += fib3;
		fib1 = fib2;
		fib2 = fib3;
	}
    std::cout<<sum<<endl;
    return 0;
}
