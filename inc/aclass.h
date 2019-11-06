#include <iostream>

class A
{
    int x{5};
    public:
    A()= default;
    void print() const{
        std::cout<<this->x<<std::endl;
    }
};