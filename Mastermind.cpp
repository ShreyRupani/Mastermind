#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 4
#define TRIES 10

int code[SIZE];
int entry[TRIES] = {0};
int numcode = 0;

int check(int i)
{
	int j, k, tempDigit;
	int matched1[SIZE] = {0}, matched2[SIZE] = {0}, currentTry[SIZE] = {0};
	if(entry[i] == numcode)
	return 1;
	tempDigit = 0;
	for(j = SIZE-1; j >= 0; j--)
	{
		currentTry[j] = entry[i]%10;
		entry[i] /= 10;
	}

	for(j = 0; j < SIZE; j++)
	if(currentTry[j] == code[j])
	{
		cout << "o";
		matched1[j] = 1;
		matched2[j] = 1;
	}

	for(j = 0; j < SIZE; j++)
	{
		if(matched1[j])
		continue;
		for(k = 0; k < SIZE; k++)
		if(currentTry[j] == code[k] && matched2[k] == 0)
		{
			cout << "*";
			matched2[k] = 1;
			break;
		}
	}
	cout << "\n";
	return 0;
}

int main()
{
	int seed;
	cout << "\n\nMASTERMIND\n\nGuess the 4 digit number\n\n";
	cout << "Enter SEED\n";
	cin >> seed;
	srand(seed);
	while(true)
	{
		int i, flag;
		for(i = 0; i < SIZE; i++)
		code[i] = 0;
		numcode = 0;
		for(i = 0; i < SIZE; i++)
		{
			code[i] = rand()%10;
			numcode += code[i];
			numcode *= 10;
		}
		numcode /= 10;
//		cout <<  "\n\n" << numcode << "\n\n";
		for(i = 0; i < TRIES; i++)
		{
			if(i == TRIES-1)
			cout << "Last try\t";
			else
			cout << "Try:" << i+1 << "\t\t";
			cin >> entry[i];
			if(check(i))
			{
			cout << "\nSUCCESS!\n";
			break;
			}
			if(i == TRIES-1)
				cout << "Out of tries!\nAnswer was:\t" << numcode << endl;
		}
		cout << "Play again?1:0\n";
		cin >> flag;
		if(!flag)
			break;
		}
}
