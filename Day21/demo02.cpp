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
	// Copy Ctor = Take single arg of type of the class itself.
	//	If not implemented, compiler provides a default copy ctor for every class.
	//	Default copy ctor performs bitwise copy a.k.a. shallow copy.
	// 12 bytes of d1 will be copied to d2, so d2 will be created as a copy of d1.
	// shallow copy ko samajne ke liye deep copy samjna imp hai
	Date(const Date& other) {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
    // getters / setters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

	// Assign Operator Overloading = 
	//	If not implemented, compiler provides default assignment operator for every class.
	//	Default assign operator performs bitwise copy a.k.a. shallow copy.
	void operator=(const Date& other) {
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
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
	Date d2(d1); 
	cout << "d2 => " << d2 << endl;

	Date d2 = d1; // copy ctor is called implicitly
	cout << "d2 => " << d2 << endl;

	Date d3, d4;
	d3 = d1; // copy assignment operator is called - we need assign operator to be overloaded for this, otherwise default assignment operator will be used
	// so what is diff between line no 65 and 69 ? 
	// line 65 is copy constructor, line 69 is copy assignment operator
	// so we need to write our assignment operator to avoid shallow copy, otherwise default assignment operator will be used
	
	cout << "d3 => " << d3 << endl;

	return 0;
}
/*
copy constructor is called implicitly in multiple places, like:
1. when we create new obj as copy of existing obj
	Date d2(d1); // copy ctor is called implicitly
	Date d2 = d1; // copy ctor is called implicitly
2. when the clas's obj is passed by value to any function
	void test(Date d) { // copy ctor is called implicitly
	}
	test(d1);
3. when the class's obj is returned by value from any function
	Date test() { // copy ctor is called implicitly
		Date d1;
		return d1;
	}
	Date d3 = test(); // copy ctor is called implicitly
// interview question: 
why copy ctor arg is passed as const reference?
Ans:
- pass by value is compile error
- if passed by value to call it you will need the copy ctor itself and allowing may cause infinite recursion
- To avoid this compiler raises error on passing by value
1. to avoid infinite recursion, if we pass by value, copy ctor will be called again
2. to avoid unnecessary copy of obj, if we pass by value, copy ctor will be called again
3. to avoid modification of the original obj, if we pass by reference, we can modify the original obj, so we pass by const reference
*/