#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//=========================================================================================================================================================================

bool hasDuplicates(const string array[], int size);
// Returns true if any of the elements of an array are repeated.

int countAllDigits(const string array[], int size);
// Counts all digits in all of the array items.

bool isInDecreasingOrder(const string array[], int size);
// If every value in array is smaller than preceeding, returns true.

int shiftRight(string array[], int size, int amount, string placeholder);
// Returns number of "placeholder" that there is in array and the array shifts right by "amount".

int find(const string array[], int size, string match);
// Returns smallest index of string searched for.

int replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter);
// Replaces chosen characters with another chosen character.

//============================================================ Begin Main =======================================================

int main()
{
	//   :)
	string myArray[] = { "Hello", "hi", "yuh", "ew", "um", "eh" };
	shiftRight(myArray, 5, 10, "yuh");
	for (int i = 0; i < 5, i++)
	{
		cout << myArray[i] << " ";
	}
}

//============================================================ End Main =========================================================

bool hasDuplicates(const string array[], int size)												// Done  Checked
{
	if (size <= 0)
	{
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			for (size_t k = 0; k < array[i].length(); k++)
			{
				if (array[i][k] != array[j][k])
				{
					break;
				}
				else if ((k == (array[i].length() - 1)) && (k == (array[j].length() - 1)))
				{
					return 1;
				}
			}

		}
	}
	return 0;
}

int countAllDigits(const string array[], int size)											// Done  Checked
{
	int counter = 0;
	if (size <= 0)
	{
		return (-1);
	}

	for (int i = 0; i < size; i++)
	{
		for (size_t j = 0; j < array[i].length(); j++)
		{
			if (isdigit(array[i][j]))
			{
				counter++;
			}
		}
	}
	return counter;
}

bool isInDecreasingOrder(const string array[], int size)									// Done  Checked
{
	if ((size == 0) || (size == 1))
	{
		return true;
	}
	else if (size < 0)
	{
		return false;
	}
	for (int i = 0; i < (size - 1); i++)
	{
		if (array[i] <= array[i + 1])
		{
			return false;
		}
	}
	return true;

}

int shiftRight(string array[], int size, int amount, string placeholder)					// Done  Checked
{
	if ((size < 0) || (amount < 0))
	{
		return (-1);
	}
	for (int i = (size - 1); i >= 0; i--)
	{
		if (((i + amount) < size) && (i >= 0))
		{
			array[i + amount] = array[i];
			array[i] = placeholder;
		}
		
	}
	return (amount);
}

int find(const string array[], int size, string match)										// Done  Checked
{
	if (size < 0)
	{
		return (-1);						// Size is less than 0
	}
	for (int i = 0; i < size; i++)
	{
		for (size_t j = 0; j < array[i].length(); j++)
		{
			if (array[i][j] != match[j])
			{
				break;
			}
			else if ((j == (array[i].length() - 1)) && (j == (match.length() - 1)))
			{
				return (i);
			}
		}
	}
	return (-1);							// Not found
}

int replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter)		// Done  Checked
{
	int counter = 0;

	if (size <= 0)
	{
		return (-1);
	}
	for (int i = 0; i < size; i++)
	{
		for (size_t j = 0; j < array[i].length(); j++)
		{
			if (array[i][j] == findLetter)
			{
				array[i][j] = replaceLetter;
				counter++;
			}
		}
	}
	return (counter);
}
