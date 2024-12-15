#include <iostream>

using namespace std;

class MyClass{};

int main(){
    double *p; // double 타입의 변수 포인터
    int *p1, *p2, v1, v2; // 앞에 *가 붙으면 포인터, 아니면 일반 변수
    v1 = 12;
    p1 = &v1; // p1 포인터가 v1을 포인팅 하도록 함

    cout << *p1 << endl; // p1 포인터가 가리키고 있는 변수의 값을 출력

    p2 = p1; // p2가 p1이 포인팅 하고 있는 변수를 같이 포인팅함
    *p1 = *p2; // p1이 포인팅 하고 있는 변수의 값을 p2가 포인팅하고 있는 변수의 값과 같게 함

    // 이름 없는 포인터 (메모리 동적 할당)
    int *np1, *np2; // 포인터 선언
    np1 = new int; // 이름 없는 변수를 선언하여 np1 포인터에 할당 np1 -> int variable
    np2 = new int(12); // 12 값을 넣어 이름 없는 변수를 할당

    MyClass *cp1;
    cp1 = new MyClass; // 이름 없는 클래스를 생성하고 cp1 포인터가 포인팅, 클래스의 생성자가 실행됨

    delete np1, np2, cp1; // 할당된 동적 메모리를 정리 (그러나 포인터는 아직도 메모리 주소를 포인팅 하고 있음)

    np1 = np2 = NULL; // 포인터에 NULL을 대입하여 변수 포인팅 초기화
    cp1 = NULL;

    // 포인터 타입 이름 붙이기
    typedef int* IntPtr;
    IntPtr cnptr;
    cnptr = new int;
    *cnptr = 12;
    cout << *cnptr << endl;
    delete cnptr;

    return 0;
}