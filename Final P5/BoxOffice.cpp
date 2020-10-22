#include "BoxOffice.h"

BoxOffice::BoxOffice()
{

}

Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime)
{
	Ticket t(row, seat, event, venue, 0, kind, daytime);
	return t;
}

Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
	Ticket t(row, seat, event, "Royce Hall", 0, kind, daytime);
	double newPrice;
	if (daytime.find("PM") != std::string::npos)	// Is PM
	{
		switch (kind) {
		case 0:
			newPrice = 75.00;
			break;
		case 1:
			newPrice = 65.00;
			break;
		case 2: 
			newPrice = 12.50;
			break;
		case 3:
			newPrice = 55.00;
			break;
		}
	}
	else											// Is AM
	{
		switch (kind) {
		case 0:
			newPrice = 75.00;
			break;
		case 1:
			newPrice = 50.00;
			break;
		case 2:
			newPrice = 12.50;
			break;
		case 3:
			newPrice = 40.00;
			break;
		}

	}

	if (row.find("Orchestra") != std::string::npos)  // Is Orchestra
	{
		newPrice = (newPrice * 2.0);
	}

	if (newPrice >= 40.00)
	{
		newPrice = (newPrice - 30.00);
	}
	else
	{
		newPrice = (newPrice * 0.8);
	}

	t.setPrice(newPrice);
	return t;
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
	Ticket t(row, seat, event, "Royce Hall", 0, kind, daytime);
	double newPrice;
	if (daytime.find("PM") != std::string::npos)	// Is PM
	{
		switch (kind) {
		case 0:
			newPrice = 75.00;
			break;
		case 1:
			newPrice = 65.00;
			break;
		case 2:
			newPrice = 12.50;
			break;
		case 3:
			newPrice = 55.00;
			break;
		}
	}
	else											// Is AM
	{
		switch (kind) {
		case 0:
			newPrice = 75.00;
			break;
		case 1:
			newPrice = 50.00;
			break;
		case 2:
			newPrice = 12.50;
			break;
		case 3:
			newPrice = 40.00;
			break;
		}

	}

	if (row.find("Orchestra") != std::string::npos)  // Is Orchestra
	{
		newPrice = (newPrice * 2.0);
	}

	if (newPrice >= 40.00)
	{
		newPrice = (newPrice - 20.00);
	}
	else
	{
		newPrice = (newPrice * 0.9);
	}

	t.setPrice(newPrice);
	return t;
}

Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
	Ticket t(row, seat, event, "Royce Hall", 0, kind, daytime);
	double newPrice;
	if (daytime.find("PM") != std::string::npos)	// Is PM
	{
		switch (kind) {
		case 0:
			newPrice = 75.00;
			break;
		case 1:
			newPrice = 65.00;
			break;
		case 2:
			newPrice = 12.50;
			break;
		case 3:
			newPrice = 55.00;
			break;
		}
	}
	else											// Is AM
	{
		switch (kind) {
		case 0:
			newPrice = 75.00;
			break;
		case 1:
			newPrice = 50.00;
			break;
		case 2:
			newPrice = 12.50;
			break;
		case 3:
			newPrice = 40.00;
			break;
		}

	}

	if (row.find("Orchestra") != std::string::npos)  // Is Orchestra
	{
		newPrice = (newPrice * 2.0);
	}

	t.setPrice(newPrice);
	return t;
}
