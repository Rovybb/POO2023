#include "Math.h"
#include <iostream>

using namespace std;

int main()
{
    int a = 234, b = 56, c = 876;
    double x = 34.432, y = 45, z = 0.7654;
    char v1[256] = "Hello \0", v2[256] = "world!\0";

    cout << "The sum of " << a << " and " << b << ": " << Math::Add(a, b) << endl;
    cout << "The sum of " << a << ", " << b << " and " << c << ": " << Math::Add(a, b, c) << endl;
    cout << "The sum of " << x << " and " << y << ": " << Math::Add(x, y) << endl;
    cout << "The sum of " << x << ", " << y << " and " << z << ": " << Math::Add(x, y, z) << endl << endl;
    
    cout << "The product of " << a << " and " << b << ": " << Math::Mul(a, b) <<endl;
    cout << "The product of " << a << ", " << b << " and " << c << ": " << Math::Mul(a, b, c) << endl;
    cout << "The product of " << x << " and " << y << ": " << Math::Mul(x, y) <<endl;
    cout << "The product of " << x << ", " << y << " and " << z << ": " << Math::Mul(x, y, z) << endl << endl;

    cout << "The sum of " << a << ", " << b << ", " << c << ", " << 32 << ", " << 4 << " and " << 19 << ": " << Math::Add(6, a, b, c, 32, 4, 19) << endl << endl;
    cout << "The concatenation of '" << v1 << "' and '" << v2 << "': '" << Math::Add(v1, v2) << "'\n";
    return 0;
}
