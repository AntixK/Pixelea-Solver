#ifndef strassen_H_
#define strassen_H_

#include <math.h>
#include <vector>
#include <random>
#include <fstream>
#include <time.h>
#include<stdlib.h>

using namespace std;

#define N 8 /* NxN Puzzle */

typedef uint16_t byte;
typedef vector<byte> vect;
typedef vector<vect> matrix;

class pixelea
{
private:
	matrix puzz;
	vect point;
	fstream file;
	uint16_t no_of_moves;

public:
	pixelea();
	void display();
	bool get_puzzle();
	void solve_col();
	bool make_puzzle();
	void disp_moves();
	bool solve_puzzle();
	void solve_row(uint16_t &row);
};

pixelea :: pixelea()
{
	no_of_moves = 0;
	srand(time(NULL));
	puzz.resize(N);
	point.resize(2);

	for(uint16_t i = 0;i < N;++i)
		puzz[i].resize(N);
}

bool pixelea::get_puzzle()
{
	file.open("Puzzle.txt");

	if (!file.is_open())
		return false;

	byte temp = 0;
	uint16_t i = 0, j = 0;

	while (file >> temp)
	{
		puzz[i][j++] = temp;
		
		if (j == N )
		{
			i++;
			j = 0;
		}

	}

	file.close();

	return true;
}

void pixelea::solve_row(uint16_t &row)
{		
	uint16_t i = 0; 
	while (i<N)
	{
		if (puzz[row][i] != puzz[row][i+1])
		{
			puzz[row][i] = (6 / puzz[row][i] + 6 / puzz[row][i+1]) % 6;
			if (puzz[row][i] == 5)
				puzz[row][i] = 1;
			puzz[row][i+1] = puzz[row][i];
			no_of_moves++;
		}
		i += 2;
	}

	i = 1;
	while (i<N)
	{
		if (puzz[row][i] != puzz[row][i + 1])
		{
			puzz[row][i] = (6 / puzz[row][i] + 6 / puzz[row][i + 1]) % 6;
			if (puzz[row][i] == 5)
				puzz[row][i] = 1;
			puzz[row][i + 1] = puzz[row][i];
			no_of_moves++;
		}
		i += 4;
	}

	i = 0;
	while (i<N)
	{
		if (puzz[row][i] != puzz[row][i + 1])
		{
			puzz[row][i] = (6 / puzz[row][i] + 6 / puzz[row][i + 1]) % 6;
			if (puzz[row][i] == 5)
				puzz[row][i] = 1;
			puzz[row][i + 1] = puzz[row][i];
			no_of_moves++;
		}
		i += 4;
	}

	i = 1;
	while (i<N)
	{
		if (puzz[row][i] != puzz[row][i + 1])
		{
			puzz[row][i] = (6 / puzz[row][i] + 6 / puzz[row][i + 1]) % 6;
			if (puzz[row][i] == 5)
				puzz[row][i] = 1;
			puzz[row][i + 1] = puzz[row][i];
			no_of_moves++;
		}
		i += 4;
	}

	i = 0;
	while (i<N)
	{
		if (puzz[row][i] != puzz[row][i + 1])
		{
			puzz[row][i] = (6 / puzz[row][i] + 6 / puzz[row][i + 1]) % 6;
			if (puzz[row][i] == 5)
				puzz[row][i] = 1;
			puzz[row][i + 1] = puzz[row][i];
			no_of_moves++;
		}
		i += 2;
	}

	i = 3;

	if (puzz[row][i] != puzz[row][i + 1])
	{
		puzz[row][i] = (6 / puzz[row][i] + 6 / puzz[row][i + 1]) % 6;
		if (puzz[row][i] == 5)
			puzz[row][i] = 1;
		puzz[row][i + 1] = puzz[row][i];
		no_of_moves++;
	}

	uint16_t Sum = 0;
	bool flag = true;

	Sum = puzz[row][0];
	for (uint16_t i = 1;i < N;++i)
	{
		if (Sum != puzz[row][i])
		{
			flag = true;
			break;
		}
		else
			flag = false;
	}

	if (!flag)
		return;
	else
		solve_row(row);

}

void pixelea::solve_col()
{
	uint16_t i = 0, col = 0;
	while (i<N)
	{
		for (col = 0; col < N;++col)
		{
			if (puzz[i][col] != puzz[i + 1][col])
			{
				puzz[i][col] = (6 / puzz[i][col] + 6 / puzz[i + 1][col]) % 6;
				if (puzz[i][col] == 5)
					puzz[i][col] = 1;
				puzz[i + 1][col] = puzz[i][col];
				no_of_moves++;
			}
		}
		i += 2;
	}

	i = 1;
	while (i<N)
	{
		for (col = 0; col < N;++col)
		{
			if (puzz[i][col] != puzz[i + 1][col])
			{
				puzz[i][col] = (6 / puzz[i][col] + 6 / puzz[i + 1][col]) % 6;
				if (puzz[i][col] == 5)
					puzz[i][col] = 1;
				puzz[i + 1][col] = puzz[i][col];
				no_of_moves++;
			}
		}
		i += 4;
	}

	i = 0;
	while (i<N)
	{
		for (col = 0; col < N;++col)
		{
			if (puzz[i][col] != puzz[i + 1][col])
			{
				puzz[i][col] = (6 / puzz[i][col] + 6 / puzz[i + 1][col]) % 6;
				if (puzz[i][col] == 5)
					puzz[i][col] = 1;
				puzz[i + 1][col] = puzz[i][col];
				no_of_moves++;
			}
		}
		i += 4;
	}

	i = 1;
	while (i<N)
	{
		for (col = 0; col < N;++col)
		{
			if (puzz[i][col] != puzz[i + 1][col])
			{
				puzz[i][col] = (6 / puzz[i][col] + 6 / puzz[i + 1][col]) % 6;
				if (puzz[i][col] == 5)
					puzz[i][col] = 1;
				puzz[i + 1][col] = puzz[i][col];
				no_of_moves++;
			}
		}
		i += 4;
	}

	i = 0;
	while (i<N)
	{
		for (col = 0; col < N;++col)
		{
			if (puzz[i][col] != puzz[i + 1][col])
			{
				puzz[i][col] = (6 / puzz[i][col] + 6 / puzz[i + 1][col]) % 6;
				if (puzz[i][col] == 5)
					puzz[i][col] = 1;
				puzz[i + 1][col] = puzz[i][col];
				no_of_moves++;
			}
		}
		i += 2;
	}

	i = 3;

	for (col = 0; col < N;++col)
	{
		if (puzz[i][col] != puzz[i + 1][col])
		{
			puzz[i][col] = (6 / puzz[i][col] + 6 / puzz[i + 1][col]) % 6;
			if (puzz[i][col] == 5)
				puzz[i][col] = 1;
			puzz[i + 1][col] = puzz[i][col];
			no_of_moves++;
		}
	}

	uint16_t Sum = 0;
	bool flag = true;
	col = 0;
	Sum = puzz[0][col];
	for (uint16_t i = 1;i < N;++i)
	{
		if (Sum != puzz[i][col])
		{
			flag = true;
			break;
		}
		else
			flag = false;
	}

	if (!flag)
		return;
	else
		solve_col();

}

bool pixelea::solve_puzzle()
{
	uint16_t row = 0;

	while (row < N)
	{
		solve_row(row);
		row++;
	}

	solve_col();
	return true;
}

bool pixelea::make_puzzle()
{
	file.open("Puzzle.txt",ios::out);
	byte temp = 0;

	if (!file.is_open())
		return false;

	for (uint16_t i = 0; i < N*N; ++i)
	{
		temp = rand() % 3 + 1;

		if ((i+1) % N == 0)
			file << temp << "\n";
		else
			file << temp << " ";
	}

	file.close();
	return true;

}

void pixelea::display()
{
	for (uint16_t i = 0; i < N;++i)
	{		
		for (uint16_t j = 0;j < N;++j)
		{
			cout << puzz[i][j] << " ";
		}
		cout << "\n";
	}
}

void pixelea::disp_moves()
{
	cout << "\n The total Number of moves/swaps : " << no_of_moves;
}
#endif