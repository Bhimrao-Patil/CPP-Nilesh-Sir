/*
friend function is a function that is not a member of a class but has access to the private and protected members of the class. A friend function can be a normal function, a member function of another class, or a global function. A friend function can be declared inside the class definition using the keyword "friend". A friend function can also be declared outside the class definition using the keyword "friend" followed by the function prototype. A friend function can be called like a normal function, but it has access to the private and protected members of the class. A friend function can also be called using an object of the class, but it does not have access to the private and protected members of the class through that object. A friend function can also be called using a pointer to an object of the class, but it does not have access to the private and protected members of the class through that pointer.
*/

#include <iostream>
using namespace std;

// Dev1
class Distance {
private:
	int feet, inches;
public:
	Distance(int f = 0, int i = 0) {
		feet = f;
		inches = i;
	}
	void display() {
		cout << feet << "' " << inches << "\"" << endl;
	}
	friend Distance add_distance(Distance a, Distance b);
};


// Dev2 - Teammate of Dev1
// global function - that want to access private members of the class
//	such function can be declared as "friend" of the class.
// instead of getter and setter functions, we can use friend function to access private members of the class.
// if we do getter and setter that good look weired
// friend function can access private members of the class but it is not a member of the class. It is a global function
// but what about data security: c++ only friend fn concept
// is it security threat ? 
// fried is only for sharing secret
// so is it good to use friend function ?
// dhoka vahi deta hai jispe bharosa hota hai 
// to galti kiski jisne friedn usko banaya
// there is nothing wrong with friend its its our fault
// to soch samajk friend function ko use karna chahiye ya nahi- yes

Distance add_distance(Distance a, Distance b) {
	Distance r;
	r.inches = a.inches + b.inches;
	r.feet = a.feet + b.feet;
	if (r.inches >= 12) {
		r.inches -= 12;
		r.feet++;
	}
	return r;
}
int main()
{
	Distance d1(3, 4), d2(5, 5), d3;
	d3 = add_distance(d1, d2);
	d3.display(); // 8' 9"
	return 0;
}