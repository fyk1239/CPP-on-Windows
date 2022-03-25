#include <iostream>

template <typename T>
T max(T x, T y)
{
    return x > y ? x : y;
}

template <typename T>
class Person
{
public:
    Person(T attr) : attribute(attr)
    {
    }
    ~Person()
    {
    }
    void show() const
    {
    }

private:
    T attribute;
};

int main()
{
    float x = 0.3, y = 0.4;
    std::cout << max(x, y) << std::endl;
    int a = 3, b = 4;
    std::cout << max(a, b) << std::endl;
    Person<int> p0(a);
    Person<float> p1(x);
    p0.show();
    p1.show();
    return 0;
}