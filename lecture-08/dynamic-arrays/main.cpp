#include <iostream>

using namespace std;


int main(){
    int a[10]; // int 타입 변수 10개의 "포인터"들
    int *pi1;
    pi1 = a; // [가능] pi1 포인터가 int 10개 변수를 가지는 포인터 값을 가짐
    // a = pi1; // [불가능] 배열 포인터는 const라서 변경 불가

    // Dynamic Array
    typedef double* DoublePtr;
    DoublePtr d; // double 변수를 포인팅하는 포인터
    d = new double[10]; // double 변수를 포인팅 하는 포인터에 동적 크기(10개)의 배열을 할당

    // Dynamic Array 삭제
    delete [] d; // 메모리 삭제
    d = NULL; // 포인터가 가리키는 메모리 주소 초기화

    // 배열을 return 하는 함수 (기본적으로 배열은 반환 불가)
    int* sumOfList(int* targetArray);

    double *d1;
    d1 = new double[10];
    cout << *d1 << endl; // d1 배열의 첫 번째 값
    cout << *(d1+1) << endl; // d1 배열의 두 번째 값
    cout << *(d1+2) << endl; // d1 배열의 세 번째 값
    cout << *(d1+3) << endl; // d1 배열의 네 번째 값
    // +와 -로 배열 주소 이동이 가능 (나누기 곱하기 불가)

    // 다중 차원 배열
    int**m = new int*[3]; // 이중 포인터로 포인터를 포인팅 하는 포인터 생성
    for (int i=0; i<3; i++)
    {
        m[i] = new int[4]; // 3x4 배열 생성, 각 포인터 마다 int를 4개 가지는 포인터들을 생성
    }

    return 0;
}