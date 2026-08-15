#include <iostream>
using namespace std;
/*
- friend classes are not inherited to derived class
- when A class friend of B class. A can access all memberrs of B class
- But B class is not friend of A class. So B cannot access members of A class
- real time exaple tum jisko fried smjte ho o tumko sab bata deta hai but tum usko kuch nahi batate
- so that is no gruarantte who is our friend.
- if A is friend of B, B is friend of C, then A is not friend of C. So A cannot access members of C class.
*/
class Node {
private:
    int data;
    Node* next;
public:
    Node(int val) {
        data = val;
        next = NULL;
    }
    friend class List;
        // when List class become friend of Node class,
        //  its all members fns will have acccess to Node class private members.
};

class List {
private:
    Node* head;
public:
    List() {
        head = NULL;
    }
    void add_last(int val) {
        Node* newnode = new Node(val);
        if (head == NULL)
            head = newnode;
        else {
            Node* trav = head;
            while (trav->next != NULL)
                trav = trav->next;
            trav->next = newnode;
        }
    }
    void display() {
        Node* trav = head;
        while (trav != NULL) {
            cout << trav->data << ", ";
            trav = trav->next;
        }
        cout << endl;
    }
    // add_first(), del_first(), del_last(), ... -- all fns need access to private members of Node class
};


int main()
{
    List l1;
    l1.add_last(11);
    l1.add_last(22);
    l1.add_last(33);
    l1.add_last(44);
    l1.display();
    return 0;
}