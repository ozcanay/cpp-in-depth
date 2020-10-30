#include <iostream>
#include <cassert>

#include "templates/is-prime.h"

using namespace std;

int main() {
//    assert(sizeof(int) == 4);
//    static_assert(sizeof(int) == 4, "int size is not 4 bytes long.");

    cout << IsPrime<9>::value << endl;
    cout << IsPrime<7>::value << endl;

    cout << isPrime11(9) << endl;
    cout << isPrime11(7) << endl;

    cout << isPrime14(9) << endl;
    cout << isPrime14(7) << endl;
}
