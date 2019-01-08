#include <string>
#include <iostream>

class Foo {

    private:
        static std::string *m_s;

    public:
        static std::string& myfunc() {
            if(!m_s) m_s = new std::string("foo");
            return *m_s;
        }
        static void change(std::string &s) {
            s.append("888");
        }
};
std::string *Foo::m_s = NULL;

void foo() {
    std::string &foo = Foo::myfunc();
    std::string bar = Foo::myfunc();
    std::cout << &foo << std::endl;
    std::cout << &bar << std::endl;
    bar.append("123");
    std::cout << foo << std::endl;
    std::cout << bar << std::endl;
    delete &foo;

    std::string bla("999");
    Foo::change(bla);
    std::cout << bla << std::endl;

}

int* count() {
    static int c = 0;
    c++;
    std::cout << c << std::endl;
    return &c;
}

void mycount(int* c) {
    (*c)++;
    std::cout << *c << std::endl;
}

int main() {
    foo();
    for(int i = 0; i < 10; ++i) {
        int *s = count();
        mycount(s);
    }
    return 0;
}
