#include <iostream>
#define SQR(n) (n*n)

using namespace std;

// int square(int n) {
//     return n * n;
// }

inline int square(int n) {
    return n * n;
}

int main() {
    int num = 7;
    int res = square(7);
    cout << "result: " << res << endl; 
    res = SQR(num);
    cout << "result: " << res << endl;

    return 0;
}
// fn call:
// 1. fn activation record on stack
//2. vars/args intialsed
//3. fn code aexcuted
//4. fn activation recored destrroyed

