#include<iostream>
#include <thread>
#include "pixelea.h"

using namespace std;

void main()
{
	pixelea p;

	cout << "\n \t\t PIXELEA SOLVER \n";

	cout << "\n Creating a random puzzle...";
	if (!p.make_puzzle())
		cout << "Sorry File Error!!\n";

	cout << "Done!\n";

	cout << "\n Getting the puzzle...";
	p.get_puzzle();
	cout << "Done!\n";
	cout << "\n Original Puzzle - \n";
	p.display();


	cout << "\n Solving the puzzle...";
	p.solve_puzzle();
	cout << "Done!\n";
	cout << "\n";
	p.display();

	p.disp_moves();

	cout << "\n";

}