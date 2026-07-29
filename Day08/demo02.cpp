/*
I want to implement a stack using linked list .
Stack is a linear data structure which follows LIFO (Last In First Out) principle.
In stack, the element which is inserted last is removed first.
In stack, we can perform following operations:
1. push() : to insert an element in stack
2. pop() : to remove an element from stack
3. peek() : to get the top element of stack without removing it
Real time example is chair, where the last person who sits on the chair is the first person to get up from the chair.
Means the end element is the first element to be removed from the stack.
SO we can say that stack is a linear data structure which follows LIFO (Last In First Out) principle.
exaple if we have kept 5 books on the table and we want to remove the books from the table, then we will remove the last book which is kept on the top of the stack first.
if we have already 4 books on the table and we want to add 1 more book on the table, then we will add the book on the top of the stack.
There are 2 ways to implement stack:
1. using array
2. using linked list

So 
- push is on the top of the stack 
- pop is from the top of the stack.
So here we can see where we the use of private inheritance 
|head ptr|-->|10|*|--> |20|*|--> |30|*|--> NULL
So linked list is basically list of nodes, where each node contains data and pointer to the next node.
and they linked to each other in sequential manner.
 and head pointer contains the address of first node of the linked list.
node = data + pointer to next node
In linked list we can add the node at the end of the list or at the beginning of the list or at any position in the list.
we can delete item from the end of the list or from the beginning of the list or from any position in the list.
List operations:
1. Add last
2. Add first
3. Add at position
4. Delete last
5. Delete first
6. Delete at position

currently we are implementing stack using linked list, so we will add the node at the beginning of the list and delete the node from the beginning of the list.
intially our head will be nuull and we all 10 to the stack, so we will create a node with data 10 and pointer to next node as null and head will point to this node.
then we will add 20 to the stack, so we will create a node with data 20 and pointer to next node as head and head will point to this node.
then we will add 30 to the stack, so we will create a node with data 30 and pointer to next node as head and head will point to this node.
So the stack will look like this:
|head ptr|-->|30|*|--> |20|*|--> |10|*|--> NULL
So the last element which is added to the stack is 30 and the first element which is removed from the stack is 30.
So the stack follows LIFO (Last In First Out) principle.
So the last element which is added to the stack is 30
and the first element which is removed from the stack is 30.    
So we will create 2 functions for stack operations:
1. Add first : to add the node at the beginning of the list
2. Delete first : to delete the node from the beginning of the list

so we are implemnting this using inheritance, so we will create a class node which will contain data and pointer to next node and we will create a class stack which will inherit the class node and will contain head pointer and functions to add and delete the node from the list.
Stack is special type of linked list in which add and delete is allowed only from start(first node).
so here we are using private inheritance because we want to hide the implementation details of the linked list from the user and we want to provide only the stack operations to the user.
class linkedlist { 
public:
    
}
class stack : private linkedlist {
public:
    void push(int data) {
        addfirst(data);
    }
    void pop() {
        deletefirst();  
    }
};
stack s1;
s1.addfirst(10); // its not allowed because addfirst is private member of linkedlist class and stack class is inheriting linkedlist class privately, so addfirst is not accessible in stack class.
s1.push(10); // its allowed because push is public member of stack class and stack

*/

#include <iostream>
using namespace std;

class linkedlist {
public:
    void addfirst(int data) {
        cout << "addfirst() called with data: " << data << endl;
    }
    void deletefirst() {
        cout << "deletefirst() called" << endl;
    }
    void addlast(int data) {
        cout << "addlast() called with data: " << data << endl;
    }
    void deletelast() {
        cout << "deletelast() called" << endl;  
    }

};

// implementing stack using existing linked list class using private inheritance
//  stack "is a" special type of linked list in which addition/deletion must be done from start (first).

class mystack : private linkedlist {
public:
    void push(int data) {
        linkedlist::addfirst(data); // calling base class method
    }
    void pop() {
        linkedlist::deletefirst(); // calling base class method
    }
};

class yourstack: private linkedlist {
public:
// add first and delete first are private members of linkedlist class and yourstack class is inheriting linkedlist class privately, so addfirst and deletefirst are not accessible in yourstack class.

    linkedlist::addfirst; // redeclare as public
    linkedlist::deletefirst; // redeclare as public
    // so here if you see addfirst and deletefirst are public members of yourstack class, so they are accessible in yourstack class.

};
int main() {
    mystack s1;
    // s1.addfirst(10); // its not allowed because addfirst is private member of linkedlist class and mystack class is inheriting linkedlist class privately, so addfirst is not accessible in mystack class.
    // s1.addlast(20); // its not allowed because addlast is private member of linkedlist class and mystack class is inheriting linkedlist class privately, so addlast is not accessible in mystack class.
    // if we make the mystack class to inherit linkedlist class publicly, then addfirst and addlast will be accessible in mystack class, but we don't want to allow addlast in stack because stack is a special type of linked list in which addition/deletion must be done from start (first).
    // so we are using private inheritance to hide the addlast and deletelast methods of linkedlist class from mystack class.
    
    s1.push(10); // its allowed because push is public member of mystack class
    s1.push(20);
    s1.push(30);    
    s1.pop(); // its allowed because pop is public member of mystack class

    yourstack s2;
    s2.addfirst(11);
    s2.addfirst(22);
    s2.addfirst(33);
    s2.deletefirst();
    return 0;
}   
