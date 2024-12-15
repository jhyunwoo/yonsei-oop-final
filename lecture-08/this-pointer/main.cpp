#include <iostream>

using namespace std;

class Simple
{
public:
  void showStuff() const
  {
    cout << this->stuff << endl; // this 포인터로 객채의 stuff 변수에 접근 (this 포인터는 객체 그 자체를 포인팅함) (값에 바로 접근, 주소 아님)
  };
  ~Simple(); // 파괴자 (out of scope 될 때 자동으로 실행)
private:
  int stuff;
  char* charptr;
};

int main(){
  return 0;
}

Simple::~Simple() // 파괴자 선언
{
  delete charptr; // 할당된 char을 가리키는 포인터 제거
  charptr = NULL; // 포인터 주소 값 초기화
}
