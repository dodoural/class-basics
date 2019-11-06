#include <iostream>


class MyClass
{
private:
    static int number_of_instance;
    int* m_ptr{};
    int m_size{};
    struct MyStruct;
    MyStruct *ms_ptr{};
public:
    MyClass()= delete;
    explicit MyClass(int size);
    MyClass(const MyClass &);
    ~MyClass();
    MyClass &operator=(const MyClass &);
    static int get_instance_count();
    friend std::ostream& operator<<(std::ostream &,const MyClass &);
};

