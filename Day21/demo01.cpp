/*
foundation of modern C++ programming
Shallow copy vs Deep copy:
read sir notes for more details

*/
#include <iostream>
using namespace std;

class Date {
private:
	int day, month, year; // 12 bytes
public:
	Date() {
		this->day = 1;
		this->month = 1;
		this->year = 2000;
	}
	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	~Date() {
	}

    // getters / setters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
};
ostream& operator<<(ostream& out, const Date& d) {
	out << d.day << "-" << d.month << "-" << d.year;
	return out;
}
istream& operator>>(istream& in, Date& d) {
	cout << "date (dd mm yyyy): ";
	in >> d.day >> d.month >> d.year;
	return in;
}

int main() {
	Date d1;
	cin >> d1; // 14 8 2026
	cout << "d1 => " << d1 << endl;
	Date d2(d1); // without doing any thing, d2 will be created as a copy of d1 using the default copy constructor
	cout << "d2 => " << d2 << endl;
	return 0;
}