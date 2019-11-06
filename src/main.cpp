#include "myclass.h"
#include <iostream>

int main()
{
    std::cout<<MyClass::get_instance_count()<<" instances of MyClass are active at this time.\n";

    MyClass dodom{12};

    std::cout<<MyClass::get_instance_count()<<" instances of MyClass are active at this time.\n";

    MyClass* dodoptr = new MyClass(4);

    std::cout<<MyClass::get_instance_count()<<" instances of MyClass are active at this time.\n";

    MyClass dodokai{dodom};

    std::cout<<MyClass::get_instance_count()<<" instances of MyClass are active at this time.\n";
    std::cout<<dodom;
    return 0;
}