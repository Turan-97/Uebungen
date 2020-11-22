#include "stack_t.hpp"
#include <iostream>
using namespace std;


int main(void)
{
    stack_t<float> test;

    test.push(5.0);
    test.push(1.0);
    test.push(3.0);
    test.push(12.0);
    test.print();

    cout << test.top() << endl;

    test.pop();
    test.print();

    test.~stack_t();

    //Liste müsste nun leer sein
    test.top();
}