#include <iostream>

using namespace std;

class dist {
private:
    int feet, inches;
public:
    dist(int f = 0, int i = 0) // deafult args
    {
        this->feet = f;
        this->inches = i;
        cout << "dist() called" << endl;
    }

    ~dist()
    {
        cout << "~dist() called" << endl;
    }
    void display()
    {

        cout << "distance : " << feet << "\" " << inches << " " << endl;
    }
};

int main() 
{
    // static mem allocation
    dist d1(5, 8);
    d1.display();

    //int *ptr = new int[n];  // dynamic mem allocation for array
    // delete[] ptr;          // mem deallocation of array

    dist* p2 = new dist();   // dynamic mem alloc for one object and calls constructor with 0 argument
    p2->display();  
    // run program befor delete   
    
    delete p2;      // mem deallocation

    dist* p3 = new dist(4, 9);  // dynamic mem alloc for one object - param ctor
    p3->display();
    delete p3;

    dist* ptr = new dist[3];  // we are allocating mem for array of 3 dist obj's , 24 bytes mem will allocate
    for(int i=0; i < 3; i++)
        ptr[i].display();    // why here we are calling with dot <please ans>
    
    delete[] ptr;       // plmem deallocation of array
    ptr = NULL;
    cout << ptr << endl;
    
    //ptr = &d1;      // you may reuse ptr to refer another object

    dist *p4 = (dist*)malloc(sizeof(dist)); // malloc() alloc mem, but doesn't call ctor
    cout << "p4 allocated using malloc()" << endl;
    p4->display(); // garbage values
    free(p4); // free() release mem, but doesn't call dtor
    // In C++, never use malloc() and free(). Always use new and delete.

    return 0;
}