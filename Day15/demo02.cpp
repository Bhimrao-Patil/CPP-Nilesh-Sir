/* Upcasting and downcasting
sir will not so much imp to above topic, but he will explain in detail about
object slicing (pointer and reference) is nothing but upcasting
    -> upcasting: assigning derived class object address to base class pointer
    -> why upcasting: -> generalization
    -> allowed in all oop languages
    -> why its allowed: -> because every derived is a base 
    -> like every manager is also employee
    -> every student is person
    -> instead of treating circle, rectangle, square as separate entities, we can treat them as shape
shape*
arr[5]. -> you have not 1 pointer, but 5 pointers
0| *| -> rectangle object. |
1| *| -> circle object.    |
2| *| -> square object      
3| *| -> rectangle object
4| *| -> square object
ye tabhi possible hoga, jab hum upcasting karenge,
this is upcasting, because we are assigning derived class object to base class pointer
- common in all is calculation area, perimeter, volume etc

Downcasting: assigning base class object to derived class object
// global fn
void display(shape *s) {
    if (s is type of rectangle) {
        rectangle *r = (rectangle*)s; // downcasting base class to dereved class poniter
        // base class pointer ko derived class pointer me convert karna is called downcasting
        cout << "Area of rectangle: " << r->calc_area() << endl;
    } else if (s is type of circle) {
        circle *c = (circle*)s; // downcasting
        cout << "Area of circle: " << c->calc_area() << endl;
    } else if (s is type of square) {
        square *sq = (square*)s; // downcasting
        cout << "Area of square: " << sq->calc_area() << endl;
    }

- why downcasting: -> specialization
- not allowed in all oop languages
- can access members specific to derived class
- not directly supported in oop lang-> need explicit type casting
- why-> not evry base is derived
-------------
OOA and OOD:
OOA is a methodology to analyze the problem and identify the objects and their relationships
check the notes
OOA -> OOD -> OOP
only class likh rhe ho not inheritance, polymorphism, encapsulation, abstraction then it is not oop

Pillars of object model:
The four major pillars of object-oriented programming are:
1. Abstraction: Abstraction is the process of hiding the implementation details and showing only the functionality to the user. In C++, abstraction is achieved using abstract classes and interfaces.
2. Encapsulation: Encapsulation is the process of wrapping data and functions into a single unit called a class. It restricts direct access to some of the object's components, which can prevent the
3. Modularity: Modularity is the process of dividing a program into smaller, independent modules that can be developed and tested separately. In C++, modularity is achieved using classes and namespaces.
4. Hierarchy: Hierarchy is the process of organizing classes into a hierarchy based on their relationships. In C++, hierarchy is achieved using inheritance.
    - is a(inheritance and polymorphism) and has a(composition and aggregation)
The three minor pillars of object-oriented programming are:
1. Typing: Typing is the process of defining the data types of variables and functions. In C++, typing is achieved using static typing, which means that the data types are checked at compile time.
    - Polymorphic dynamic binding and static binding
2. Concurrency: Concurrency is the process of executing multiple tasks simultaneously. In C++, concurrency is achieved using threads and asynchronous programming.
    - 
3. Persistence: Persistence is the process of storing data in a way that it can be retrieved later. In C++, persistence is achieved using file I/O

why major and minor piller separetd because of below
Object base language : 
- you are dealing with class and object, but not dealing with inheritance and polymorphism
- abstraction and encapsulation
e.g  Old VB (not VB dot net), Ada, 

Object oriented language:
- Support all majr pillars -> including inheritance and polymorphism
- C++, Java, Python(has oop support),Smalltalk

Fully object oriented language:
-> supports all major and minor pillars of object model
-> everything is an object
->eg. c #

Abstaction:
- Defination:
 focus on the essential characteristics of an object, while ignoring the irrelevant details.
 here we are not using hiding like other book. Getting essential details is called abstraction

- Key Questions:- What is the object?
- Goal
    . Stack object -> LIFO 
    . push and pop are essential details, but how it is implemented is not important
    - Display but that is not important, how it is implemented is not important

    - Model only what is important
    - Ignore unnecessary implementation details
    - Represent the problem domain in a simple way
- A person can be viewed differently depending on the application
    . Hospital -> patient, doctor, nurse, receptionist
    . Payroll -> employee, manager, accountant
    . Airline -> passenger, pilot, flight attendant, ground staff
- Key idea :  there is no single correct abstraction
- Choose the abstaraction that best reprsent the problem being solved
eg PMT bus -> imp kya hai passaenger 
     conductor uske lie imp hai ki able to collect fare, driver ke lie imp hai ki able to drive bus, bus owner ke lie imp hai ki able to earn profit

data abstraction:
- Data abstraction is the process of hiding the implementation details of data and showing only the essential features
- Example: Stack(LIFO) -> push and pop are essential features, but how they are implemented is not important
  - user does not know about array, linked list, etc. used to implement stack
- inspired -> data structures and algorithms i.e abstract data types (ADT)

- Encapsulation :
Defination:
Compartmentalizing data and behavior; separating the interface from implementation
Key Questions: How is the object implemented?
- Goal: 
 - Protect internal data 
 - Hide implementation details
 - Expose only required services
 - Prevent external misuse
 like capsule : in capsule is binding all medicine in one capsule
 only we see how its eat not what its added in it

 Interafce vs implementation:
 - client ineract only with the public interface
  - deposit, withdraw, check balance
  class accound mai kya likha imp nhi void deposite mai kya hai o imp hai
  Account a1;
  a1.deposite();
- Hidden implementation details
  - database , variables, functions, etc.
- Implementation can be changed without affecting the client

Information hiding:
 - Principle : Hide implementation details that are likely to change

- Abstraction vs Encapsulation:
- Abstraction (what):
    - focus on the outside view
    - Model essential feratures
    - Simplifies complexity from the problem domain
- Encapsulation (how):
    - focus on the inside view
    - Hide implementation details > private or public hide code
    - Protect complexity in software implementation
- Remember: Abstraction is about what an object does, while encapsulation is about how it does it.
exaple :
    diagram of watch:
            watch -> outside view
        /       \
    digital     analog <- inside view
    digital watch:
    - what: display time in digital format
    - how: using LCD or LED display     
- So both abstraction and encapsulation are important concepts in object-oriented programming, and they work together to create well-designed and maintainable software systems.
- ak duje ke liye hai o
- Abstraction decided WHAT to expose
- Encapsulation budles data and behavior and decides HOW to expose it


*/
