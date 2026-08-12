#include <iostream>
using namespace std;

class Time {
private:
    int hrs, min, sec;
public:
    Time() {
        hrs = 0;
        min = 0;
        sec = 0;
    }
    void set_hrs(int h) {
        if (h < 0 || h >= 24)
            // throw h; // throw h is not good because it will throw an int value which is not meaningful. so we need to throw a string message which is meaningful.
            throw "invalid hrs";
        hrs = h;
    }
    void set_min(int m) {
        if (m < 0 || m >= 60)
            // throw m; // throw m is not good because it will throw an int value which is not meaningful. so we need to throw a string message which is meaningful.
            throw "invalid mins";
        min = m;
    }
    void set_sec(int s) {
        if (s < 0 || s >= 60)
            // throw s; // throw s is not good because it will throw an int value which is not meaningful. so we need to throw a string message which is meaningful.
            throw "invalid secs";
        sec = s;
    }
    void display() {
        cout << "time: " << hrs << ":" << min << ":" << sec << endl;
    }
};

int main()
{
    Time t1;
    try {
        t1.set_hrs(22);
        t1.set_min(16);
        t1.set_sec(40);
        t1.display();
    }
    // catch (int err) {
    //     cout << "ERROR: " << err << endl;
    // }better to throw string message instead of int value because it is more meaningful and readable.
    catch (const char *err) {
        cout << "ERROR: " << err << endl;
    }
    return 0;
}