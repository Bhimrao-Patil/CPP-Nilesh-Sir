/*
Sttaic members:
I have something chair and it has diff attributes 
    height
    weight
    colour
but every chair has diff price
we are in such shop and where all chair has same price
typical like 99 shop all which can I take is of 99 like that
c1 chair has h=2. w= 1 and c = black
c2 chair has h=2.5 w= 1.5 and c = red
c3 chair has h=2. w= 1.5 and c = blue
having here price as data menber
and price will be same for each 
so keeping price for each c1, c2, c3 we can kept outside of it
so means it has same price for c1, c2, c3
so we can use word that is shared price which is shared among all objects of class
at that time we can go for static. 
so we can kept this outside object
shared = static (in VB dot net they are not using sttaic ther ar using shared directly)

*/ 
#include <iostream>
#define BLACK   0
#define RED     1
#define GREEN   2
#define BLUE    3

using namespace std;

class chair {
private :
int height;     // instance members (non-static members)
    int weight;     // instance members (non-static members)
    int color;      // instance members (non-static members)
    static int price; // (class member) static data member declaration
    // static declaration : its allowed in new c++ 
    // static not getting mem here . 
    // To get the mem define static explicitly outside the class

public:
    // static int price;
    chair()
    {
        height = 0;
        weight = 0;
        color = BLACK;
    }

    chair(int h, int w, int c)
    {
        height = h;
        weight = w;
        color = c;
    }

    //getters/setters <add for assignment>
    void display() {
        // non-static member fns of class can access, static members of class directly
        // cout << "chair: height=" << height << "\", weight=" << weight << "kg, color=" << color << endl;
        cout << "chair: height=" << height << "\", weight=" << weight << "kg, color=" << color << ", ** price=" << price << endl;
    }
    // static member fn
    //    - to access/manipulate static data members of the class
    //    - class members -- classname::member() e.g. chair::get_price()
    static int get_price()
    {
        return price;
    }

    static int set_price(int price)
    {
        // price; = price ; // will it cause confusion --> yes -- error
        //this->price; = price ; // its used on object, here no object is involed it- error
        chair::price = price; // this ist solution its class member 
    }

    static void display_price() {
        cout << "price = " << price << endl;
        //cout << "height = " << height << endl; // compiler error - no object is available here (this pointer)
        // chair c;
        // c.height = 2; // allowed -- accessed on some object
    }

    // helper fns/util fns -- belongs to class -- from main() chair::calc_total_weight(arr);
    static int cal_total_weight(char chairs[])// all chairs weight
    {
        // add one loop and do addition its an assignment

        return 0;
    }
};
// no static keyword use here
int chair::price = 2000; // sttatic defination using scope resolition here mem get allocated. 
/*
in old cpp it was mandotory to initiaize it but in modern c++ its not gives any error
otherwise in old cpp it was gave linking error
if we remove "chair::"" so it will be global variable not a part of class
so that price is common for all c1, c2, c3
like india is my country, all people can sai that as its shared
if we not initialised it will be 0
static data member -- life throughtout the program
     -- scope limited to class in which it is declared
         - accessible directly inside class
         - accessible outside class using scope resolution (if public)

static fn are same as global fn only the scope is limited to the class
static mem dont contribute to size of object
the dont have receive implicit this 
applications of static
1. to access / manipulate static data members
2. to associate same logic with class (not indivial object)
3. to create obj of the class
    e.g. singleton design patter, factory design pattern
    

*/

int main()
{  
    // we can modify the price as well and it will change all chair price
    // here c1, c2, c3 are local variable decared in main are created on stack
    // price is static filed or  data member stored in data section
    // and it has int so size is diff for static data member and ist not part of size of class
    // so its belongs to the class not belong to individual objects

    //chair::price = 2500; // // can access static members outside the class, if they are declared public
    chair::set_price(2500); // static member fns are recommended to be called on class name
        // since no object is involved, it doesn't have "this" pointer.

    chair c1(2, 1, BLACK);
    chair c2(1, 2, RED);
    chair c3(3, 2, BLUE);
    c1.display();
    c2.display();
    c3.display();
    // we can also access price if its public
    // cout << "c2 price: " << c2.price << endl; 
    // but ideally access like below as it will cerate confusion like its specific to c2
    // cout << "chair price: " << chair::price << endl; // can access static outside class, if public
    //     // classname::staticmember (recommended) or objname.staticmember
    // cout << "chair object size: " << sizeof(c1) << endl;
    // but if we want security public is not be good
    // still we can access price using display method where we already printed price
    // or 2nd way using getter setter specifically to price
    //cout << "c2 price: " << c2.get_price() << endl; // still that is misleading we want chair price
    cout << "c2 price: " << chair::get_price() << endl;
    // static member fns shared by all objs of class, so they can be called on object using . operator.
    //  however, we should avoid calling like that. it is misleading
    cout << "chair object size: " << sizeof(c1) << endl;

    return 0;
}