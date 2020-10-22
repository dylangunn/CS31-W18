#include "Ticket.h"
using namespace std;

Ticket::Ticket() : mRow(""), mSeat(0), mEvent(""), mVenue("Royce Hall"), mPrice(0), mKind(), mDayTime("")  // Initialization List
{																										   // Default with price 0 to later set by driver
																										   // Venue as "Royce Hall" bc BoxOffice only use that venue
}

Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime)
{
	mRow = row;
	mSeat = seat;
	mEvent = event;
	mVenue = venue;
	mPrice = price;
	mKind = kind;
	mDayTime = daytime;
}

string Ticket::getRow()
{
	return mRow;
}

int Ticket::getSeat()
{
	return mSeat;
}

string Ticket::getEvent()
{
	return mEvent;
}

string Ticket::getVenue()
{
	return mVenue;
}

double Ticket::getPrice()
{
	return mPrice;
}

void Ticket::setPrice(double price)
{
	mPrice = price;
}

Ticket::KIND 
Ticket::getKind()
{
	return mKind;
}

string Ticket::getDayTime()
{
	return mDayTime;
}
