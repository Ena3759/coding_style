#include <iostream>
#include "mycomplex.h"

using namespace std;

int main()
{//тестирование класса комплексных чисел
    Complex A, B(-4), C(23.0, 45.9);
    cout << A << "," << B << "," << C << endl;
    A = B + C;
    cout << "A=B+C,A=" << A << endl;


    Complex D;
    cout << "Enter complex number D = ";
    cin >> D;
    A += C + D;
    cout << "D = " << D << "\nA = " << A << endl;
    return 0;
}
