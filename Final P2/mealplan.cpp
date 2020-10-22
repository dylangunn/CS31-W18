#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Here I declare all of my variables that I will use.  All of them are strings.
	string payment;
	string meal;
	string position;
	string resStatus;
	string cost;

	// This asks for method of payment and grabs my "payment" string.
	cout << "Ticket or BruinCard? ";
	getline(cin, payment);

	// Track continued if answer to payment is BruinCard.
	if (payment == "BruinCard")
	{
		// This asks for meal type and grabs my "meal" string.
		cout << "Breakfast, Lunch or Dinner? ";
		getline(cin, meal);

		// Track continued if answer to meal is Breakfast.
		if (meal == "Breakfast")
		{
			// This asks for position and grabs my "position" string.
			cout << "Student or Staff? ";
			getline(cin, position);

			// Track continued if answer to position is Student.
			if (position == "Student")
			{
				// This asks for resident status and grabs my "resStatus" string.
				cout << "Resident? ";
				getline(cin, resStatus);

				// Track continued if answer to resStatus is Yes.
				if (resStatus == "Yes")
				{
					cost = "9.75";
				}

				// Track continued if answer to resStatus is No.
				else if (resStatus == "No")
				{
					cost = "10.00";
				}

				// Track continued if answer to resStatus is not expected.
				else
				{
					cout << "The resident value must either be Yes or No." << endl;
					return(4);
				}
			}

			// Track continued if answer to position is Staff.
			else if (position == "Staff")
			{
				cost = "11.25";
			}

			// Track continued if answer to position is not expected.
			else
			{
				cout << "The type value must either be Student or Staff." << endl;
				return(3);
			}
		}

		// Track continued if answer to meal is Lunch.
		else if (meal == "Lunch")
		{
			// position?
			cout << "Student or Staff? ";
			getline(cin, position);

			// Student
			if (position == "Student")
			{
				// resStatus?
				cout << "Resident? ";
				getline(cin, resStatus);

				// Yes
				if (resStatus == "Yes")
				{
					cost = "11.25";
				}

				// No
				else if (resStatus == "No")
				{
					cost = "11.75";
				}

				// resStatus???
				else
				{
					cout << "The resident value must either be Yes or No." << endl;
					return(4);
				}
			}

			// Staff
			else if (position == "Staff")
			{
				cost = "12.75";
			}

			// position???
			else
			{
				cout << "The type value must either be Student or Staff." << endl;
				return(3);
			}
		}

		// Track continued if answer to meal is Dinner.
		else if (meal == "Dinner")
		{
			// position?
			cout << "Student or Staff? ";
			getline(cin, position);

			// Student
			if (position == "Student")
			{
				// resStatus?
				cout << "Resident? ";
				getline(cin, resStatus);

				// Yes
				if (resStatus == "Yes")
				{
					cost = "12.25";
				}

				// No
				else if (resStatus == "No")
				{
					cost = "12.75";
				}

				// resStatus???
				else
				{
					cout << "The resident value must either be Yes or No." << endl;
					return(4);
				}
			}

			// Staff
			else if (position == "Staff")
			{
				cost = "14.75";
			}

			// position???
			else
			{
				cout << "The type value must either be Student or Staff." << endl;
				return(3);
			}
		}

		// Track continued if answer to meal is not expected.
		else
		{
		cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
			return(2);
		}
	}

	// Track continued if answer to payment is Ticket.
	else if (payment == "Ticket")
	{
		// meal?
		cout << "Breakfast, Lunch or Dinner? ";
		getline(cin, meal);

		// Breakfast
		if (meal == "Breakfast")
		{
			cost = "12.50";
		}

		// Lunch
		else if (meal == "Lunch")
		{
			cost = "14.50";
		}

		// Dinner
		else if (meal == "Dinner")
		{
			cost = "17.00";
		}

		// meal???
		else
		{
			cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
			return(2);
		}
	}

	// Track continued if answer to payment is not expected.
	else
	{
		cout << "The kind value must either be Ticket or BruinCard." << endl;
		return(1);
	}

	// Final print out, reads out required statement and inputs "cost" string with value assigned in "if" statements above.
	// I have each of my return values sorted by question.  If the error was in question 1, a 1 is returned.  In question 2, a 2 returned.  And so on.
	cout << "Thank you for eating at UCLA today.  Your meal cost is $" << cost << "." << endl;
	return(0);
}