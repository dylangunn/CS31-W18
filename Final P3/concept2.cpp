#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int elapsedMinutes(string rowerString);
// Collects the time in minutes

int elapsedSeconds(string rowerString);
// This will activate after the colon, after running strokesPerMinute
// Collects the time in seconds

int strokesPerMinute(string rowerString);
// Activates after space after seconds
// Collects the strokes per minute

int totalDistance(string rowerString);
// Activates after strokes per minute
// Collects total distance traveled

int heartRate(string rowerString);
// Activates after total distance
// Collects the beats per minute

bool isValidRowerString(string rowerString);
// Validates all string values


int main()
{
	string s;
	getline(cin, s);
	cout.setf(ios::boolalpha);
	cout << elapsedMinutes(s) << " " << elapsedSeconds(s) << " " << strokesPerMinute(s) << " " << totalDistance(s) << " " << heartRate(s) << " " << isValidRowerString(s);
	return (0);
}

//______________________________________________________________________________________________________________//
int elapsedMinutes(string rowerString)
{
	string minutes = "";

	for (size_t j = 0; j < rowerString.length(); j++)   // Leading 0
	{
		if ((isdigit(rowerString[j])) && (rowerString[j] != '0'))
		{
			break;
		}
		else if ((isdigit(rowerString[j])) && (rowerString[j] == '0'))
		{
			return (-1);
		}

	}

	for (size_t i = 0; i < rowerString.length(); i++)
	{
		if (isdigit(rowerString[i]))
		{
			minutes = minutes + rowerString[i];
		}
		else if (rowerString[i] == ':')   // Hits first ":"
		{
			if (minutes == "")   // No digits before ":"
			{
				return(0);
			}
			int minVal = stoi(minutes);
			if ((minVal < 0) || (minVal > 59))   // If minVal not valid, returns -1
			{
				return(-1);
			}
			return(minVal);
		}
		else if ((!isdigit(rowerString[i])) && (rowerString[i] != ' ') && rowerString[i] != ':')
		{
			return(-1);   // Is something other than a digit or space or colon
		}
	}
	return -1;  // Never is a digit or colon
}


int elapsedSeconds(string rowerString)
{
	if (elapsedMinutes(rowerString) == -1)   // Invalid rower string
	{
		return (-1);
	}
	string seconds = "";

	for (size_t i = 0; i < rowerString.length(); i++)
	{
		if (rowerString[i] == ':')
		{
			if (!isdigit(rowerString[i + 1]) || !isdigit(rowerString[i + 2]) || isdigit(rowerString[i + 3]))  // Error if seconds vals are not digits  or 3rd is
			{
				return -1;
			}
			else
			{
				seconds = rowerString[i + 1];
				seconds += rowerString[i + 2];
				int secVal = stoi(seconds);
				if ((secVal > 59) || (secVal < 0))   // Error if outside of second range
				{
					return(-1);
				}
				return(secVal);
			}
			
		}
	}
	return -1;   // No colon
}


int strokesPerMinute(string rowerString)
{
	if ((elapsedMinutes(rowerString) == -1) || (elapsedSeconds(rowerString) == -1))   // Invalid rower string
	{
		return (-1);
	}
	string strokes = "";
	int i = 0;

		while (rowerString[i] != ':')   // Up to colon
		{
			i++;
		}

		while (rowerString[i] != ' ')   // Up to space separating seconds and s/m
		{
			i++;
		}

		while (rowerString[i] == ' ')   // Up to s/m value
		{
			i++;
		}

		if (isdigit(rowerString[i]))
		{
			if (rowerString[i] == 0)   // If leading 0
			{
				return (-1);
			}
			strokes = rowerString[i];
			if (isdigit(rowerString[i + 1]))
			{
				strokes = strokes + rowerString[i + 1];
				if (isdigit(rowerString[i + 2]))
				{
					strokes = strokes + rowerString[i + 2];
					if ((rowerString[i + 3] != ' ') || (rowerString[i + 4] != 's') || (rowerString[i + 5] != '/') || (rowerString[i + 6] != 'm'))   // If more than 3 digits making up s/m value returns error
					{
						return(-1);
					}
					else   // Returns valid strokes per minute value if in hundreds
					{
						int strokeVal = stoi(strokes);
						return (strokeVal);
					}
				}
				else if ((rowerString[i + 2] == ' ') && (rowerString[i + 3] == 's') && (rowerString[i+4] == '/') && (rowerString[i + 5] == 'm'))   // If after second digit is a " s/m"
				{
					int strokeVal = stoi(strokes);
					return (strokeVal);
				}
				else   // If not " s/m" and not digit
				{
					return (-1);
				}
			}
			else if ((rowerString[i + 1] == ' ') && (rowerString[i + 2] == 's') && (rowerString[i + 3] == '/') && (rowerString[i + 4] == 'm'))   // If after first digit is a " s/m"
			{
				int strokeVal = stoi(strokes);
				return (strokeVal);
			}
			else   // If not " m" and not digit
			{
				return (-1);
			}
		}
		else
		{
			return(-1);   // Isn't a digit after the second value
		}
}


int totalDistance(string rowerString)
{
	if ((elapsedMinutes(rowerString) == -1) || (elapsedSeconds(rowerString) == -1) || (strokesPerMinute(rowerString) == -1))   // Invalid rower string
	{
		return (-1);
	}
	string distance = "";
	int i = 0;

	while (rowerString[i] != ':')   // Up to colon
	{
		i++;
	}

	while (rowerString[i] != ' ')   // Up to space separating seconds and s/m val
	{
		i++;
	}

	while (rowerString[i] == ' ')   // Up to s/m value
	{
		i++;
	}
				
	while (isdigit(rowerString[i]))   // Up to space separating s/m val and "s/m"
	{
		i++;
	}

	while (rowerString[i] == ' ')   // Up to "s/m"
	{
		i++;
	}
	if (rowerString[i] != 's')   // No 's'
	{
		return (-1);
	}
	else   // Takes to after 's'
	{
		i++;
	}

	if (rowerString[i] != '/')   // No '/'
	{
		return (-1);
	}
	else   // Takes to after '/'
	{
		i++;
	}

	while (rowerString[i] == '/')   // Up to 'm'
	{
		i++;
	}
	if (rowerString[i] != 'm')   // No 'm'
	{
		return (-1);
	}
	else   // Takes to after 'm'
	{
		i++;
	}

	if (rowerString[i] != ' ')   // No space between "s/m" and value of distance
	{
		return(-1);
	}
	
	while (rowerString[i] == ' ')   // Up to distance value
	{
		i++;
	}

	if (isdigit(rowerString[i]) && rowerString[i] != 0)
	{
		distance = rowerString[i];
		if (isdigit(rowerString[i + 1]))
		{
			distance += rowerString[i + 1];
			if (isdigit(rowerString[i + 2]))
			{
				distance += rowerString[i + 2];
				if ((rowerString[i + 3] == ' ') && (rowerString[i + 4] == 'm'))
				{
					int distVal = stoi(distance);
					return (distVal);
				}
				else   // Length of distance value is too long and may have something other than integer
				{
					return (-1);
				}
			}
			else if ((rowerString[i + 2] != ' ') || (rowerString[i + 3] != 'm'))   // If not space or digit after tens place
			{
				return (-1);
			}
			else
			{
				int distVal = stoi(distance);
				return (distVal);
			}
		}
		else if ((rowerString[i + 1] != ' ') || (rowerString[i + 2] != 'm'))   // If not space or digit after hundreds place
		{
			return (-1);
		}
		else   // If is " m" after first digit
		{
			int distVal = stoi(distance);
			return(distVal);
		}
	}
	else   // No digit or a 0 after "s/m" for distance traveled
	{
		return (-1); 
	}
}


int heartRate(string rowerString)
{
	if ((elapsedMinutes(rowerString) == -1) || (elapsedSeconds(rowerString) == -1) || (strokesPerMinute(rowerString) == -1) || (totalDistance(rowerString) == -1))   // Invalid rower string
	{
		return (-1);
	}
	string hrate = "";
	int i = 0;

	while (rowerString[i] != ':')   // Up to colon
	{
		i++;
	}

	while (rowerString[i] != ' ')   // Up to space separating seconds and s/m val
	{
		i++;
	}

	while (rowerString[i] == ' ')   // Up to s/m value
	{
		i++;
	}

	while (isdigit(rowerString[i]))   // Up to space separating s/m val and "s/m"
	{
		i++;
	}

	while (rowerString[i] == ' ')   // Up to "s/m"
	{
		i++;
	}
	if (rowerString[i] != 's')   // No 's'
	{
		return (-1);
	}
	else   // Takes to after 's'
	{
		i++;
	}

	if (rowerString[i] != '/')   // No '/'
	{
		return (-1);
	}
	else   // Takes to after '/'
	{
		i++;
	}

	while (rowerString[i] == '/')   // Up to 'm'
	{
		i++;
	}
	if (rowerString[i] != 'm')   // No 'm'
	{
		return (-1);
	}
	else   // Takes to after 'm'
	{
		i++;
	}

	if (rowerString[i] != ' ')   // No space between "s/m" and value of distance
	{
		return(-1);
	}

	while (rowerString[i] == ' ')   // Up to distance value
	{
		i++;
	}

	while (isdigit(rowerString[i]))   // Up to space after dist
	{
		i++;
	}
	if (rowerString[i] != ' ')   // If not space after dist
	{
		return (-1);
	}

	if (rowerString[i] == ' ')
	{
		i++;
	}
	else   // No single space after distance value
	{
		return (-1);
	}
	if (rowerString[i] != 'm')   // No 'm' after distance value
	{
		return (-1);
	}
	else   // Is an 'm' after distance value, gets over 'm'
	{
		i++;
	}
	if (rowerString[i] != ' ')   // If no space after m
	{
		return (-1);
	}

	while (rowerString[i] == ' ')
	{
		if ((i + 1) == rowerString.length())   // No heart rate value present
		{
			return (-1);
		}
		i++;
	}

	if ((isdigit(rowerString[i])) && (rowerString[i] != '0'))   // If hrate val leads with acceptable number
	{
		hrate += rowerString[i];
		if ((i + 1) == rowerString.length())
		{
			int rateVal = stoi(hrate);
			return (rateVal);
		}
		else if (isdigit(rowerString[i + 1]))
		{
			hrate += rowerString[i + 1];
			if ((i + 2) == rowerString.length())
			{
				int rateVal = stoi(hrate);
				return (rateVal);
			}
			else if (isdigit(rowerString[i + 2]))
			{
				hrate += rowerString[i + 2];
				if ((i + 3) == rowerString.length())
				{
					int rateVal = stoi(hrate);
					return (rateVal);
				}
				else   // If is longer than maximally possible
				{
					return(-1);
				}
			}
			else   // If is something after hr val
			{
				return (-1);
			}
		}
		else   // If is something after hr val
		{
			return (-1);
		}
	}
	else   // If hr value leads with a 0 or isn't a number
	{
		return (-1);
	}

}


bool isValidRowerString(string rowerString)
{
	if ((elapsedMinutes(rowerString) != -1) && (elapsedSeconds(rowerString) != -1) && (strokesPerMinute(rowerString) != -1) && (totalDistance(rowerString) != -1) && (heartRate(rowerString) != -1))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}