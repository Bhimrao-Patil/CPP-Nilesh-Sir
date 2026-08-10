#pragma once
// #pragma once --> ensures that the header file is included only once in
//	any source file, so that its contents are not duplicated.
// alternative option --> header guard in C --> #ifndef #define ... #endif

// class declaration
class product {
public:
	product(const char* title = "", double price = 0.0);
	virtual void accept();
	virtual void display();
	double get_price();
	void set_price(double price);
	const char* get_title();
	void set_title(const char* title);
private:
	char title[20];
	double price;
};

/*

c++ Project -> Shop

product.h
----------
|.       |
|        |
|. 
--------- 
*/