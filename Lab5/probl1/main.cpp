#include "Number.h"
#include <iostream>

using namespace std;

int main()
{
    Number n1("FE45", 16);
    Number n2 = n1;
    n2.SwitchBase(7);
    Number n3 = (n1 + n2);
    Number n4("2342", 5);
    Number n5("1A56", 11);
    n1.Print(); cout << endl;
    n2.Print(); cout << endl;
    n3.Print(); cout << endl;
    n4.Print(); cout << endl;
    n5.Print(); cout << endl;
    n4 = n5;
    n5 = (n3 + n4);
    n4 += 45;
    n5 -= n1;
    n2 = (8723 - n4) + (n5 - n4) + 3;
    n1.Print(); cout << endl;
    --n1;
    n1.Print(); cout << endl;
    n2.Print(); cout << endl;
    n2--;
    n1.Print(); cout << endl;
    if (n1 > n2) {
        cout << "n1 mai mare" << endl;
    }
    return 0;
}
