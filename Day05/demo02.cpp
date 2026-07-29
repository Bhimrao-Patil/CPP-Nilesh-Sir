#include <iostream>

using namespace std;

// input marks of n students in a school.
// display all the marks and display avg marks.
// write an object oriented appln.

class school {
private:
    int n;
    int* marks;

public:
    school(int n) {
        this->n = n;
        this->marks = new int[n];
        cout << "Inside school() ctor " << endl;
    }

    ~school() {
        delete[] this->marks;
        this->marks = NULL;
        cout << "Inside ~school() dtor " << endl;
    }

    void accept() {
        cout << "enter marks of " << this->n << " students: ";
        for (int i = 0; i < this->n; i++)
            cin >> this->marks[i];
    }

    void display() {
        int sum = 0;
        cout << "marks: ";
        for (int i = 0; i < this->n; i++) {
            sum += this->marks[i];
            cout << this->marks[i] << ", ";
        }
        double avg = (double)sum / this->n;
        cout << "\naverage = " << avg << endl;
    }

};
int main()
{
    // school s1(15);
    // school s2(3)

    int num;
    cout << "enter num of students in school: ";
    cin >> num;
    school s1(num); // internally dynamically allocate array of "num" ints using "new" in constructor
    s1.accept();
    s1.display();


    return 0;
}// s1 destroying - destructor - should deallocate dynamically allocated memory.5
