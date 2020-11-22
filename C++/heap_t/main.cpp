#include "heap_t.hpp"


int main()
{
    int Arr[10];
    int* ptr = Arr;

    for(int i = 0; i < 10; i++) 
    {
        Arr[i] = i;
    }
    
    Arr[9] = 99;

    heap_t<float> test(ptr);

    test.print();

    /*test.extractMin();
    cout << test.minimum() << endl;
    test.~heap_t();
    test.print();*/

    return 0;
}