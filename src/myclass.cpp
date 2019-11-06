#include <cstring>
#include "myclass.h"
#include "aclass.h"


struct MyClass::MyStruct
{
    public:
    A s_a{};
    int m_num{10};
};

int MyClass::number_of_instance = 0;

MyClass::MyClass(int size): m_ptr{new int[size]},m_size{size},ms_ptr{new  MyClass::MyStruct()}
{
    std::cout<<this<<" one parameter constructor has been called. "<<std::endl;
    std::cout<<"Number of MyClass instances active is "<< ++number_of_instance<<std::endl;
}


MyClass::~MyClass()
{
    std::cout<<this<<" destructor has been called. "<<std::endl;
    std::cout<<(this->ms_ptr)->m_num<<std::endl;
    number_of_instance--;
    delete [] m_ptr;

   if (ms_ptr != nullptr)
    delete this->ms_ptr;
}

MyClass::MyClass(const MyClass &r)
{
    std::cout<<this<<" copy constructor has been called. "<<std::endl;
    number_of_instance++;
    this->m_ptr = new int{r.m_size};
    this->m_size = r.m_size;
    this->ms_ptr = new MyClass::MyStruct{};
    std::memcpy(this->m_ptr,r.m_ptr,m_size*sizeof(int));
    std::memcpy(this->ms_ptr,r.ms_ptr,sizeof(MyStruct));

}

MyClass& MyClass::operator=(const MyClass &r)
{
    std::cout<<this<<" copy assignment operator has been called. "<<std::endl;

    if (this == &r)
        return *this;
    if(this->m_ptr != nullptr)
    {
        delete [] this->m_ptr;
    }
    if(this->ms_ptr != nullptr)
    {
        delete this->ms_ptr;
    }
    this->ms_ptr = new MyClass::MyStruct{};
    this->m_ptr = new int[r.m_size];
    this->m_size = r.m_size;

    std::memcpy(this->m_ptr,r.m_ptr,(this->m_size)*sizeof(int));
    std::memcpy(this->ms_ptr,r.ms_ptr,sizeof(MyStruct));

    return *this;
}

int MyClass::get_instance_count()
{
    return MyClass::number_of_instance;
}

std::ostream& operator<<(std::ostream & os,const MyClass & r)
{
     os<<(r.ms_ptr)->m_num<<std::endl;
     return os;
}
