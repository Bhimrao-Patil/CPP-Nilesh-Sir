
/*
#include <iostream>

int main()
{
	std::cout << "Hello World!" << std::endl; // recommended in industry
	// in huge codebase there are high chances of name collisions.
	// recommended to always use namespace::member name.
	return 0;
}
*/

#include <iostream>
using namespace std;

namespace dsa {
	namespace listspace {
		class node {
			// list node
		public:
			node() {
				cout << "list-node() called" << endl;
			}
		};

		class list {
		public:
			list() {
				cout << "list() called" << endl;
			}
		};

		int count = 10;

		void display() {
			//node n; // listspace::node -- accessing inside listspace itself
			cout << "list is displayed" << endl;
		}
	} // end of listspace

	namespace treespace {
		class node {
			// tree node
		public:
			node() {
				cout << "tree-node() called" << endl;
			}
		};

		class tree {
		public:
			tree() {
				cout << "tree() called" << endl;
			}
		};

		int count = 20;

		void display() {
			cout << "tree is displayed" << endl;
		}
	} // end of treespace
}
/*
int main() {
	// access nested namespace members using full name of the member.
	dsa::listspace::node n1;
	dsa::treespace::node n2;
	return 0;
}
*/

/*
int main() {
	// alias (short name) for fully qualified class name.
	// similar to typedef in C programming -- designed to be used with namespaces.
	using ls_node = dsa::listspace::node;
	using ts_node = dsa::treespace::node;
	// use the alias
	ls_node n1;
	ts_node n2;
	// namespace alias
	namespace ls = dsa::listspace;
	namespace ts = dsa::treespace;
	// use these aliases
	ls::display();
	ts::display();
	return 0;
}
*/

/*
// In C++, all global variables, functions, types are considered to be part
//	of "global" namespace. It is accessed using :: operator.
int global_variable = 123;

int main() {
	cout << "global_variable=" << ::global_variable << endl;
	return 0;
}
*/

/*
// anonymouse/unnamed namespace
//	its members will be hidden, if there are global vars/fns with same name.
namespace {
	int count = 0;
	void internal_fn() {
		cout << "internal count = " << count << endl;
	}
}

int count = 1;

int main() {
	//cout << count << endl; // compiler error: count is ambiguous
	cout << "global count = " << ::count << endl;
	internal_fn();
	return 0;
}
*/

#include "demo.h"

int main() {
	//cout << "test = " << test << endl; // error
	cout << "test = " << outerspace::test << endl; // okay
	outerspace::myclass obj;
	obj.display();
	return 0;
}