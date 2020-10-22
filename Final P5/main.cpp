#include "Ticket.h"
#include "BoxOffice.h"
#include <cassert>
using namespace std;

int main()
{
	Ticket t("Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", 150.00, Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM");
	BoxOffice b;
	assert(std::to_string(t.getPrice()) == "150.000000");
	assert(t.getKind() == Ticket::KIND::ATHLETICGAME);
	assert(t.getRow() == "Pavillion Row 13");
	assert(t.getSeat() == 45);
	assert(t.getVenue() == "Dodger Stadium");
	assert(t.getEvent() == "Dodgers vs. Brewers");
	assert(t.getDayTime() == "August 1, 7:30PM");

	//==============================================================================================REGULAR ORCHESTRA
	t = b.buyRoyceHallTicket("Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "130.000000");
	assert(t.getKind() == Ticket::KIND::CONCERT);
	assert(t.getRow() == "Orchestra Row A");
	assert(t.getSeat() == 12);

	t = b.buyRoyceHallTicket("Orchestra Row A", 54321, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30PM");
	
	assert(t.getKind() == Ticket::KIND::OTHER);
	assert(t.getRow() == "Orchestra Row A");
	assert(t.getSeat() == 54321);


	t = b.buyRoyceHallTicket("Orchestra Row B", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "25.000000");
	assert(t.getKind() == Ticket::KIND::MOVIE);
	assert(t.getRow() == "Orchestra Row B");
	assert(t.getSeat() == 12);
	assert(t.getEvent() == "Barry Manilow Live In Concert");
	assert(t.getDayTime() == "November 1, 7:30PM");
	assert(t.getVenue() == "Royce Hall");

	t = b.buyRoyceHallTicket("Orchestra Row A", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "150.000000");
	assert(t.getKind() == Ticket::KIND::ATHLETICGAME);
	assert(t.getRow() == "Orchestra Row A");
	assert(t.getSeat() == 12);

	//===========================================================================================================REGULAR REGULAR PM
	t = b.buyRoyceHallTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "75.000000");

	t = b.buyRoyceHallTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "65.000000");

	t = b.buyRoyceHallTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "12.500000");

	t = b.buyRoyceHallTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "55.000000");

	//===========================================================================================================REGULAR REGULAR AM
	t = b.buyRoyceHallTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "75.000000");

	t = b.buyRoyceHallTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "50.000000");

	t = b.buyRoyceHallTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "12.500000");

	t = b.buyRoyceHallTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "40.000000");

	//===========================================================================================================REGULAR STUDENT AM
	t = b.buyRoyceHallStudentTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "45.000000");

	t = b.buyRoyceHallStudentTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "20.000000");

	t = b.buyRoyceHallStudentTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "10.000000");

	t = b.buyRoyceHallStudentTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "10.000000");

	//===========================================================================================================REGULAR STUDENT PM
	t = b.buyRoyceHallStudentTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "45.000000");

	t = b.buyRoyceHallStudentTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "35.000000");

	t = b.buyRoyceHallStudentTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "10.000000");

	t = b.buyRoyceHallStudentTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "25.000000");

	//===========================================================================================================ORCHESTRA STUDENT PM
	t = b.buyRoyceHallStudentTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "120.000000");

	t = b.buyRoyceHallStudentTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "100.000000");

	t = b.buyRoyceHallStudentTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "20.000000");

	t = b.buyRoyceHallStudentTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "80.000000");

	//===========================================================================================================ORCHESTRA STUDENT AM
	t = b.buyRoyceHallStudentTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "120.000000");

	t = b.buyRoyceHallStudentTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "70.000000");

	t = b.buyRoyceHallStudentTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "20.000000");

	t = b.buyRoyceHallStudentTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "50.000000");

	//===========================================================================================================ORCHESTRA STAFF AM
	t = b.buyRoyceHallStaffTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "130.000000");

	t = b.buyRoyceHallStaffTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "80.000000");

	t = b.buyRoyceHallStaffTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "22.500000");

	t = b.buyRoyceHallStaffTicket("Orchestra Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30AM");
	assert(std::to_string(t.getPrice()) == "60.000000");

	//===========================================================================================================REGULAR STAFF PM
	t = b.buyRoyceHallStaffTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::ATHLETICGAME, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "55.000000");

	t = b.buyRoyceHallStaffTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::CONCERT, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "45.000000");

	t = b.buyRoyceHallStaffTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::MOVIE, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "11.250000");

	t = b.buyRoyceHallStaffTicket("Balcony Row J", 12, "Barry Manilow Live In Concert", Ticket::KIND::OTHER, "November 1, 7:30PM");
	assert(std::to_string(t.getPrice()) == "35.000000");


	cout << "No issues." << endl;

	return 0;
}