#include <iostream>
using namespace std;

class Base {
public:
  // virtual 키워드를 제거하면 어떤 일이 일어나는지 비교할 수 있음
   virtual void print() const {
    cout << "Base::print() 호출\n";
  }
};

class Derived : public Base {
public:
  void print() const override {
    cout << "Derived::print() 호출\n";
  }
};

int main() {
  Base b;
  Derived d;

  // 기반 클래스 포인터로 객체를 가리킨다
  Base* ptr = &b;
  ptr->print(); // Base 객체를 가리키므로 당연히 Base::print() 호출

  ptr = &d;
  // 1) virtual을 사용했다면:
  //    여기서 ptr은 Base* 타입이지만 실제로 Derived 객체를 가리키므로 Derived::print() 호출
  // 2) virtual을 사용하지 않았다면:
  //    Base의 정적 바인딩에 의해 Base::print()가 호출되어 다형성이 발휘되지 않음

  ptr->print();

  return 0;
}