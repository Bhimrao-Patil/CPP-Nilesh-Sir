/*
Virtual fn table & Virtual fn pointer  -> related to late binding

- If class contains at least one virtual function, vtable is created for the class.

- It contains addresses of virtual functions in that class.

- Vtable of derived class is made from vtable of base class and
  entries of overridden methods are updated.

- If class contains at least one virtual function, vptr is added as
  first data member of the class.

- The vptr always points to vtable of that class.
  This initialization is done by constructor of the class.

- Late binding calls are resolved using vptr & vtable at runtime.

Example:

class A {
public:
    int a;
    void f1() {}
    virtual void f2() {}
    void f3() {}
    virtual void f4() {}
};

class B : public A {
public:
    int b;
    void f1() {}
    void f2() {}
    virtual void f3() {}
    void f5() {}
    virtual void f6() {}
};

A::vftable
0 -> A::f2
1 -> A::f4

B::vftable
0 -> B::f2
1 -> A::f4
2 -> B::f3
3 -> B::f6

Object size idea (64-bit):
A object: vptr(8) + a(4) = 12 bytes
B object: vptr(8) + a(4) + b(4) = 16 bytes

Late binding call flow:
1) Find index of function in vftable (n).
2) Go to object address.
3) Read vfptr (first 8 bytes) and get vftable.
4) Call nth function from vftable.

Code explanation:

1) Class A
- f1() and f3() are non-virtual, so calls are resolved by compiler (early binding).
- f2() and f4() are virtual, so they get entries in A::vftable.

2) Class B : public A
- f2() in B overrides A::f2. Since base function is virtual, override stays virtual.
  So B::vftable updates slot 0 from A::f2 to B::f2.
- B does not override f4(), so B::vftable keeps A::f4 at slot 1.
- B introduces new virtual f3() and f6(), so new slots are added in B::vftable.
- f1() and f5() are non-virtual in B, so they are not in vftable.

3) Why this matters in calls
- A *p = new A; p->f2(); -> late binding target is A::f2.
- A *p = new B; p->f2(); -> late binding target is B::f2 (overridden).
- A *p = new B; p->f4(); -> late binding still happens, but target is A::f4
  because B has not overridden f4().
- A *p = new B; p->f1(); -> early binding, resolved by pointer type A*,
  so call goes to A::f1 (non-virtual).

4) Important interview point
- Late binding decides function at runtime using object type, but only for virtual functions.
- Non-virtual calls remain early-bound even when using pointer/reference.

Early binding vs Late binding (class notes):

- Virtual function invoked using pointer or reference is always late binding
  (call is resolved at runtime). Rest all are early binding
  (call is resolved at compile time).

- In early binding, function is called from the caller's class;
  while in late binding function is called from object's class.

- In case of late binding execution plan is still prepared at compile time
  (as vtable is created by the compiler).

  Steps:
  1) Find index of function in vftable (n).
  2) Go to object address.
  3) Read vfptr (first 8 bytes) and get vftable.
  4) Call nth function from vftable.

Late binding conditions:
- cond 1: function must be virtual.
- cond 2: function must be called on base pointer/reference.

Quick note:
- obj.fun(); usually early binding.
- ptr/ref call of virtual function -> late binding.
- If function is not overridden in object's class, inherited base class
  function is called.
*/