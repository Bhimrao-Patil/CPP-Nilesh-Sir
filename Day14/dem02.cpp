/*
what we studied till today:
C++ features:
 - class and object
 - cin & cout
 - references
 - def argument
 - inline fn
 - fn overloading
 - class methods
  - constructor
  - destructor
  - mutator fn
  - faclitator fn
- new operator
- association (has-a) relationship
  - composition (strong association)
  - aggregation (weak association)
- inheritance (is-a) relationship
  - access specifier (public, private, protected)
  - types
  - diamond problem
  - virtual inheritance
  - fn overriding
  - polymorphism
  - abstract class
  - interface
  - compile and execution time polymorphism
  - memory / internals

Now we can see the object oriented programming features in C++ language, which are not available in C language.
and practical understanding of it
- we will talk about one by one
Object oriented programming features in C++ language:
- there are so many variation available in different books of c++
- but which is book is good for learning c++ language, it is not possible to say, because it depends on the person who is learning c++ language.
- but we can say that, if we want to learn c++ language, then we should learn from the book which is written by the person who has practical experience of c++ language, because
- if we learn from the book which is written by the person who has practical experience of c++ language, then we will get practical knowledge of c++ language, which is very useful for us

- Book : object oriented analysis and design with applications, by grady booch (father of object oriented programming)
- this book is foundation of object oriented programming, and it is very useful for us to learn c++ language
- this book is complicated but its english is very good, and it is very useful for us to learn c++ language
- chapter 1 is begin with joke.
- 1st 3 to 4 chapters are also enough to learn oop
- there are certain concepts or terms
 - OOA : object oriented analysis ->
 - OOD : object oriented design ->
 - OOP : object oriented programming 
 OOA--> OOD --> OOP
- Sir shared one prolem statement -> start with system description
  - please go through notes         |
-Pronblem statement:                |
1> Object oriented analysis         |
e.g. Employee management system     |
            |                       |
  -------------------               list down all the nouns
  |                 |                |
decomposition     decomposition     may be
  | (not oops)        |               | 
functional         objects           objects (should have some criteria)--> one concrete instance-> state & identy
 1.accept_emp     1.employee          ||-> state
 2.disalay_emp.   2.manager           ||-> behavior
 3.approve_leave. 3.attedence         ||-> identity     
 4.make_Salary    4.salaray           |                 
                  5.name             class --------------template/ structure-> common behavior
                  6. id

customer places an order using shopping cart
objects??
 - customer
 - order    --> placing the order
 - cart.    --> add or delete item
this thinking called as object oriented analysis (OOA) whcih we need to think pratically 

- so what exactly class is its blue print of object.
- its nothiing but template
- iphone 14 in my hand is object, and iphone 14 is class
- human is class and nilesh is object, one human is one object
- one water bottle is class and the space accupied by water bottle is object, one water bottle is one object
- fuite and mango its not example of class and object its example of inheritance
- pen is class and the actual pen in my hand is object
- plastic chair is class and the actual plastic chair in my room is object
- shirt is class and the actual shirt in which i wear is object
- when we creating class there is some responsibility of class, which is called as class responsibility
- eg. invoice is class and the responsibility of invoice class is to generate invoice with item and total + tax, and the object of invoice class is to generate invoice for particular customer
- - resoponsibiility is divied into two parts
  - class responsibility
  - object responsibility
 */