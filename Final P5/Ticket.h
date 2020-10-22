#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;

class Ticket
{
public:
	string getRow();
	int getSeat();
	string getEvent();
	string getVenue();
	double getPrice();
	void setPrice(double price);
	enum KIND { ATHLETICGAME, CONCERT, MOVIE, OTHER };
	KIND getKind();
	string getDayTime();

	Ticket();																								// Default Constructor
	Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime);		// Overloaded Constructor


private:
	string mRow;
	int mSeat;
	string mEvent;
	string mVenue;
	double mPrice;
	KIND mKind;
	string mDayTime;
};


#endif