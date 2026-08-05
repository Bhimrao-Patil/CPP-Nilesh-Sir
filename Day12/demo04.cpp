#include <iostream>
using namespace std;

#pragma pack(1) // to remove slack bytes, so that we can see the actual size of the class

class B {
public:
	int b;
	virtual void bf1() 
    {
        cout << "B::bf1()" << endl;
    }
	virtual void bf2() 
    {
        cout << "B::bf2()" << endl;
    }
};// what is size of B? 12 bytes (4 bytes for int b + 8 bytes for vptr)
class C {
public:
	int c;
	virtual void cf1() 
    {
        cout << "C::cf1()" << endl;
    }
	virtual void cf2() 
    {
        cout << "C::cf2()" << endl;
    }
};// what is size of C? 12 bytes (4 bytes for int c + 8 bytes for vptr). because there is no inheritance between B and C, so they are independent classes, so they have their own vptr and vftable
class D : public B, public C {
public:
	int d;
	virtual void df1() 
    {
        cout << "D::df1()" << endl;
    }
	virtual void df2() 
    {
        cout << "D::df2()" << endl;
    }
};// what is size of D? 28 bytes (4 bytes for int b + 8 bytes for vptr of B + 4 bytes for int c + 8 bytes for vptr of C + 4 bytes for int d). because there is inheritance between B and C, so they have their own vptr and vftable, so the size of D is the sum of the sizes of B and C plus the size of int d
int main()
{
	B objB;
	C objC;
	D objD;
	cout << "sizeof(B) = " << sizeof(B) << endl; // 12
	cout << "sizeof(C) = " << sizeof(C) << endl; // 12
	cout << "sizeof(D) = " << sizeof(D) << endl; // 28
	B* pb = &objD;
	pb->bf2();
	C* pc = &objD;
	pc->cf2();
	D* pd = &objD;
	pd->bf1();
	pd->df1();
	pd->cf1();	
	return 0;
}
/*
obj b --> diagram:
objB
+-------------------+
| vptr (B::vftable) | 8 bytes
+-------------------+
| int b             | 4 bytes
+-------------------+
size of B = 12 bytes

obj c --> diagram:
objC
+-------------------+
| vptr (C::vftable) | 8 bytes
+-------------------+
| int c             | 4 bytes
+-------------------+
size of C = 12 bytes


obj d --> diagram:
objD
+-------------------+
| vptr (B::vftable) | 8 bytes
+-------------------+
| int b             | 4 bytes
+-------------------+
| vptr (C::vftable) | 8 bytes
+-------------------+
| int c             | 4 bytes
+-------------------+
| int d             | 4 bytes
+-------------------+
size of D = 28 bytes
---------------------------------
B:vftable
+-------------------+
| B::bf1()          | 8 bytes
+-------------------+
| B::bf2()          | 8 bytes
+-------------------+

C:vftable
+-------------------+
| C::cf1()          | 8 bytes
+-------------------+
| C::cf2()          | 8 bytes
+-------------------+

D:vftable for B part
+-------------------+
| B::bf1()          | 0
+-------------------+
| B::bf2()          | 1
+-------------------+
| D::df1()          | 2
+-------------------+
| D::df2()          | 3
+-------------------+

D:vftable for C part
+-------------------+
| C::cf1()          | 0 
+-------------------+ 
| C::cf2()          | 1
+-------------------+

So typically, in multiple inheritance, each base class has its own vptr and vftable, so the derived class has multiple vptrs and vftables. The size of the derived class is the sum of the sizes of the base classes plus the size of its own members.

*/

/*
Object slicing: when a derived class object is assigned to a base class object, the derived class part is sliced off and only the base class part is copied. So if we have a pointer of base class type pointing to a derived class object, we can only access the members of the base class and not the members of the derived class. This is called object slicing.

B *pb = &objD; // pb is a pointer to B, but it points to objD, which is of type D. So pb can only access the members of B and the members of D that are inherited from B. It cannot access the members of C or the members of D that are inherited from C.
pb->bf1(); // late binding, B::bf2() is called because pb is of type B and it points to objD, which is of type D. So the vptr of objD points to the vftable of D for the B part, so the function bf2() of D is called.

C *pc = &objD; // pc is a pointer to C, but it points to objD, which is of type D. So pc can only access the members of C and the members of D that are inherited from C. It cannot access the members of B or the members of D that are inherited from B.
pc->cf2(); // late binding, C::cf2() is called because pc is of type C and it points to objD, which is of type D. So the vptr of objD points to the vftable of D for the C part, so the function cf2() of D is called.

D *pd = &objD; // pd is a pointer to D, so it can access all the members of D, including the members of B and C that are inherited by D.
pd->bf1(); // late binding, B::bf1() is called because pd is of type D and it points to objD, which is of type D. So the vptr of objD points to the vftable of D for the B part, so the function bf1() of D is called.
pd->df1(); // late binding, D::df1() is called because pd is of type D and it points to objD, which is of type D. So the vptr of objD points to the vftable of D for the B part, so the function df1() of D is called.
pd->cf1(); // late binding, C::cf1() is called because pd is of type D and it points to objD, which is of type D. So the vptr of objD points to the vftable of D for the C part, so the function cf1() of D is called.

now there is serious problem with multiple inheritance,

*/
