// dynamic memory allocation
#include <iostream>
using namespace std;

int main()
{
    int num; // getting mem wehn fun called, movment fun comleted mem get destroyed
            //  // local var - scope limited to fn - auto created when fn start, auto destroyed when fn returns
    // if we want mem at runtime
    // input marks of 5 students and sum them
    /*
	// input marks of 5 students and sum them.
	int i, marks[5], sum = 0;
	cout << "enter marks of 5 students: ";
	for (i = 0; i < 5; i++)
		cin >> marks[i];
	for (i = 0; i < 5; i++)
		sum = sum + marks[i];
	cout << "sum of marks = " << sum << endl;
	*/
	// input marks of 5 students and sum them.
    // where n is given at runtime
    int i, n, sum = 0;
	cout << "how many students? ";
	cin >> n;
	int* scores = new int[n]; // dynamic memory allocation
		// if n=3, mem allocated = 3 * sizeof(int) = 12
	cout << "enter marks of "<< n << " students: ";
	for (i = 0; i < n; i++)
		cin >> scores[i];
	for (i = 0; i < n; i++)
		sum = sum + scores[i];
	cout << "sum of marks = " << sum << endl;
    // its at runtime so once its done we need to delete it its moral responsibilty of programmer
    delete[] scores; // deallocate the memory

    
	return 0;
}
