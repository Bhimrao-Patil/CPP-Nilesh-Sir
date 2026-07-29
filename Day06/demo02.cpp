/*
c+t+ --> object origented concep
1. class and objects
2. sttaic keyword
3. has-a relation
    - association/composition
        aggeregation
4. is -a relation
    inheritance
5. polymarphism
6. operator overloading
7. modularity
8, templated

Today we will see 3 point 
3. has-a relation
    - association/composition
        aggeregation

Driver has a car (loosly coupled which is simply association) and 
has engine part of it (tightly coupled) called  composition

car has wheel but its not something which is complicated which is dfine lif of car -> no
part of it but not perminant it will be detachable (weakly coupled)
car made of of 4 relationship called as aggregation

car ko engine bhi hai wheel bhi hai but one is tightly coupled that is engine because
lifetime connected directly to it
if we have issue with 1 wheel we can change it as its in stock with use

association
    1. composition (tightly coupled)
    2. aggregation ()
    3. association

anathor exaple

we have school and we have student and we have classroom
school has student loose coupld , student ka life stamp nhi hai o change krke dusre school 
mai ja skta hai
pr usme perticular classroom hai because its part of school means school band hua 
to class bhi band hoga so it has tightly coupling
school ke side mai road hai so its not belong to school so it simple association

UML diagram:
has a relationship
    1. composition. <>---- diamond arrorw
    2. Aggregation. <>---- diamond arror
    3. association.  -----

company and emp --> loosly coupled called aggretaion life time is not attached

---------------------------
person:
-name : string
-weight:int
-birth : date (diamond aray person has birth date means tightly coupled)
---------
+person()
+display()
---------------------------
date:
-day: int
-mon:int
-yr:int
------------
+date()
+display()
+accept()
+....

this digram called as class diaram or unified modeling language digarm
person is outer obj and day is inner object
here -(minus) nothing but private memmber
and +(plus) nothing but public member
UML digram is imp in interview its oop where its java , c++, or any other oop language
*/
#include <iostream>

using namespace std:

class date {
private:
    int day, month, year;
public:

}
