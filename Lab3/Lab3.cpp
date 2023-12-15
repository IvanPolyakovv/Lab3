#include <ctime>
#include <iostream>
#include <Windows.h>
using namespace std;

const int sizeArr = 6;

void createArray(int(*arr)[sizeArr]) 
{
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			arr[i][j] = rand() % 200 - 100;
		}
	}
}

void printArray(int(*arr)[sizeArr])
{
	system("cls");
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			destCoord.X = i * 5;
			destCoord.Y = j;
			SetConsoleCursorPosition(hStdout, destCoord);
			cout << arr[i][j];
		}
	}
}

void printSnake(int(*arr)[sizeArr])
{
	for (int i = 0; i < sizeArr; i++)
		for (int j = 0; j < sizeArr; j++) 
		{
			arr[i][j] = 0;
		}
	int* end = arr[0] + sizeArr * sizeArr - 1;
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int* ptr = arr[0], i = 0, x = 0, y = 0; ptr <= end + (sizeArr - 1); ptr++, i++, y++) 
	{
		if (i % sizeArr == 0 && i != 0) 
		{
			x++;
			y = 0;
			if (x % 2 == 0)
				ptr = &arr[x][y];
			else
				ptr = &arr[x][y + sizeArr - 1];
		}
		if (x % 2 == 0) 
		{
			destCoord.X = x * 4;
			destCoord.Y = y;
			SetConsoleCursorPosition(hStdout, destCoord);
			*ptr = 1 + rand() % (sizeArr * sizeArr);
			cout << *ptr;
			Sleep(50);
		}
		else 
		{
			destCoord.X = x * 4;
			destCoord.Y = sizeArr - y - 1;
			SetConsoleCursorPosition(hStdout, destCoord);
			*(ptr - y - y) = 1 + rand() % (sizeArr * sizeArr);
			cout << *(ptr - y - y);
			Sleep(50);
		}
	}
}

void printNewMatrixCircle(int (*arr)[sizeArr])
{
	for (int i = 0; i < (sizeArr / 2); i++) 
	{
		for (int j = 0; j < sizeArr; j++) 
		{
			swap(arr[i][j], arr[i + (sizeArr / 2)][j]);
		}
	}
	for (int i = 0; i < (sizeArr / 2); i++) 
	{
		for (int j = 0; j < (sizeArr / 2); j++) 
		{
			swap(arr[i][j], arr[i + (sizeArr / 2)][j + (sizeArr / 2)]);
		}
	}
	printArray(arr);
}

void printNewMatrixDiagonal(int(*arr)[sizeArr])
{
	for (int i = 0; i < (sizeArr / 2); i++) 
	{
		for (int j = 0; j < sizeArr; j++) 
		{
			if (j < (sizeArr / 2)) 
			{
				swap(arr[i][j], arr[i + (sizeArr / 2)][j + (sizeArr / 2)]);
			}
			else 
			{
				swap(arr[i][j], arr[i + (sizeArr / 2)][j - (sizeArr / 2)]);
			}
		}
	}
	printArray(arr);
}

void printNewMatrixVertical(int(*arr)[sizeArr])
{
	for (int i = 0; i < sizeArr; i++) 
	{
		for (int j = 0; j < (sizeArr / 2); j++) 
		{
			swap(arr[i][j], arr[i][j + (sizeArr / 2)]);
		}
	}
	printArray(arr);
}

void printNewMatrixHorizontal(int(*arr)[sizeArr])
{
	for (int i = 0; i < (sizeArr / 2); i++) 
	{
		for (int j = 0; j < sizeArr; j++) 
		{
			swap(arr[i][j], arr[i + (sizeArr / 2)][j]);
		}
	}
	printArray(arr);
}

void shakerSort(int(*arr)[sizeArr])
{
	int* start = &arr[0][0];
	int* end = &arr[sizeArr * sizeArr - 1][sizeArr * sizeArr - 1];
	int direction = 1;

	while (start < end) 
	{
		for (int *i = start; i < end; i += direction) 
		{
			if ((*i) > *(i + 1)) 
			{
				swap((*i), *(i + 1));
			}
		}

		end -= direction;

		for (int *i = end; i > start; i -= direction) 
		{
			if ((*i) < *(i - 1)) {
				swap(*i, *(i - 1));
			}
		}

		*start += direction;
		direction *= -1;
	}
	printArray(arr);
}

int main()
{
	int arr[sizeArr][sizeArr];
	cout << "1. Using pointer arithmetic, fills a quadratic integer matrix of order N (6,8,10) with random numbers from 1 to N*N according to the schemes shown in the figures.\n" <<
"2. Obtains a new matrix from the matrix of claim 1, rearranging its blocks in accordance with the schemes.\n" << 
"3. Using pointer arithmetic, sorts the elements by shaker sort\n" <<
"4. Reduces, increases, multiplies or divides all elements of the matrix by the number entered by the user\n\n";
	cout << "Enter the number: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: 
		int choice1;
		cout << "1 - Circle print\n" << "2 - Snake print\n";
		cout << "Enter the number: ";
		cin >> choice1;
		switch (choice1)
		{
		case 1: 
			cout << "V razrabotke";
			break;
		case 2:
			createArray(arr);
			cout << endl;
			system("cls");
			HANDLE hStdout;
			COORD destCoord;
			hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
			for (int i = 0; i < sizeArr; i++)
			{
				for (int j = 0; j < sizeArr; j++)
				{
					destCoord.X = i * 5;
					destCoord.Y = j;
					SetConsoleCursorPosition(hStdout, destCoord);
					cout << ' ';
				}
			}
			printSnake(arr);
			break;
		default: 
			cout << "Error! You entered the wrong number!";
			break;
		}
		break;
	case 2: 
		int choice2;
		cout << "1 - Circle\n" << "2 - Diagonal\n" << "3 - Vertical\n" << "4 - Horizontal\n";
		cout << "Enter the number: ";
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			createArray(arr);
			printArray(arr);
			Sleep(5000);
			printNewMatrixCircle(arr);
			break;
		case 2:
			createArray(arr);
			printArray(arr);
			Sleep(5000);
			printNewMatrixDiagonal(arr);
			break;
		case 3:
			createArray(arr);
			printArray(arr);
			Sleep(5000);
			printNewMatrixVertical(arr);
			break;
		case 4:
			createArray(arr);
			printArray(arr);
			Sleep(5000);
			printNewMatrixHorizontal(arr);
			break;
		default:
			cout << "Error! You entered the wrong number!";
			break;
		}
		break;
	case 3: 
		createArray(arr);
		printArray(arr);
		Sleep(500);
		shakerSort(arr);
		break;
	case 4: 
		
		break;
	default: cout << "Error! You entered the wrong number!";
		break;
	}
	return 0;
}
