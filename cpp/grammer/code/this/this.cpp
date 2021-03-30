#include "../type_name.hpp"
#include <iostream>

using std::cout, std::endl;

class Test {
public:
  void member_func() {
    cout << "address of this: " << this << endl;
    cout << "type    of this: " << type_name<decltype(this)>() << endl;
  }
  void member_func() const {
    cout << "address of this: " << this << endl;
    cout << "type    of this: " << type_name<decltype(this)>() << endl;
  }
  void b_f() {
    cout << "type    of this: " << type_name<decltype(this)>() << endl;
  }
};

int main() {
  Test a;
  const Test b;
  cout << "address of a:    " << &a << endl;
  a.member_func();
  cout << "address of b:    " << &b << endl;
  b.member_func();
}
