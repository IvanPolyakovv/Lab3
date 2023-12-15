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

void doShakerSort(int (*arr)[sizeArr]) 
{
	bool swapped = true;
	int *end = *(arr + sizeArr * sizeArr - 1);

	while (swapped) {
		swapped = false;
		for (int *i = *arr; i < end; ++i) {
			if ((*i) > *(i + 1)) {
				swap(*i, *(i + 1));
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}

		swapped = false;
		end = end - 1;

		// Проход справа налево
		for (int *i = end - 1; i >= *arr; --i) {
			if (*i > *(i + 1)) {
				swap(*i, *(i + 1));
				swapped = true;
			}
		}

		arr = arr + 1;
	}
	printArray(arr);
}

void insertionSort(int (*arr)[sizeArr]) {
	for (int i = 0; i < sizeArr; i++) {
		for (int j = 0; j < sizeArr; j++) {
			int key = arr[i][j];
			int k = j - 1;

			while (k >= 0 && arr[i][k] > key) {
				arr[i][k + 1] = arr[i][k];
				k--;
			}

			arr[i][k + 1] = key;
		}
	}	
	printArray(arr);
}


void sumNumArray(int(*arr)[sizeArr], int input)
{
	for (int i = 0; i < sizeArr; i++)
		for (int j = 0; j < sizeArr; j++)
			arr[i][j] += input;
	printArray(arr);
}

void difNumArray(int(*arr)[sizeArr], int input)
{
	for (int i = 0; i < sizeArr; i++)
		for (int j = 0; j < sizeArr; j++)
			arr[i][j] -= input;
	printArray(arr);
}

void mulNumArray(int(*arr)[sizeArr], int input)
{
	for (int i = 0; i < sizeArr; i++)
		for (int j = 0; j < sizeArr; j++)
			arr[i][j] *= input;
	printArray(arr);
}

void divNumArray(int(*arr)[sizeArr], int input)
{
	for (int i = 0; i < sizeArr; i++)
		for (int j = 0; j < sizeArr; j++)
			arr[i][j] /= input;
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
		insertionSort(arr);
		break;
	case 4:
		int choice4;
		cout << "1 : Array + input\n2 : Array - input\n3 : Array * input\n4 : Array / input\nEnter the number: ";
		cin >> choice4;
		switch (choice4)
		{
		case 1:
			int input1;
			cout << "Enter the number: ";
			cin >> input1;
			createArray(arr);
			printArray(arr);
			Sleep(1000);
			sumNumArray(arr, input1);
			break;
		case 2:
			int input2;
			cout << "Enter the number: ";
			cin >> input2;
			createArray(arr);
			printArray(arr);
			Sleep(1000);
			difNumArray(arr, input2);
			break;
		case 3:
			int input3;
			cout << "Enter the number: ";
			cin >> input3;
			createArray(arr);
			printArray(arr);
			Sleep(1000);
			mulNumArray(arr, input3);
			break;
		case 4:
			int input4;
			cout << "Enter the number: ";
			cin >> input4;
			createArray(arr);
			printArray(arr);
			Sleep(1000);
			divNumArray(arr, input4);
			break;
		default:
			cout << "Error! You entered the wrong number!";
			break;
		}
		break;
	default: cout << "Error! You entered the wrong number!";
		break;
	}
	return 0;
}
