#include <iostream>
#include <string>
#include <cstdlib> // exit 함수 사용 시 필요
using namespace std;

// 1) 함수 템플릿 예: 임의 타입 T에 대해 두 변수의 값을 교환
template<class T>
void swapValues(T& var1, T& var2) {
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

// 2) 클래스 템플릿 예: 두 개의 T 타입 값을 저장하는 Pair 클래스
template<class T>
class Pair {
public:
    Pair(T firstVal, T secondVal) : first(firstVal), second(secondVal) {}
    T getFirst() const { return first; }
    T getSecond() const { return second; }
    void setFirst(T val) { first = val; }
    void setSecond(T val) { second = val; }
private:
    T first;
    T second;
};

// 3) 템플릿 함수: Pair<T>에 대해 두 값의 합을 반환하는 함수(숫자 타입 T 가정)
template<class T>
T addUp(const Pair<T>& p) {
    return p.getFirst() + p.getSecond(); // T가 + 연산자를 지원해야 함
}

// 4) 템플릿 클래스를 이용한 부분적 구현 예 (간단한 PFArray)
template<class T>
class PFArray {
public:
    PFArray(int cap = 50) : capacity(cap), used(0) {
        a = new T[capacity];
    }
    PFArray(const PFArray<T>& other) : capacity(other.capacity), used(other.used) {
        a = new T[capacity];
        for (int i = 0; i < used; i++) a[i] = other.a[i];
    }
    void addElement(const T& element) {
        if (used >= capacity) {
            cout << "Array is full.\n";
            exit(1);
        }
        a[used++] = element;
    }
    int getNumberUsed() const { return used; }
    T& operator[](int index) {
        if (index < 0 || index >= used) {
            cout << "Illegal index.\n";
            exit(1);
        }
        return a[index];
    }
    ~PFArray() { delete[] a; }
private:
    T* a;
    int capacity;
    int used;
};

// 5) PFArray를 상속하는 PFArrayBak 템플릿 예
template<class T>
class PFArrayBak : public PFArray<T> {
public:
    PFArrayBak(int cap = 50) : PFArray<T>(cap), usedB(0) {
        b = new T[cap];
    }
    void backup() {
        usedB = this->getNumberUsed();
        for (int i = 0; i < usedB; i++) b[i] = (*this)[i];
    }
    void restore() {
        for (int i = 0; i < usedB; i++)
            (*this)[i] = b[i];
        // 만약 restore 후 used를 usedB에 맞추려면 이를 수정하는 함수 필요 (예: 별도 emptyArray or resize)
    }
    ~PFArrayBak() { delete[] b; }
private:
    T* b;
    int usedB;
};

int main() {
    // 함수 템플릿 테스트
    int x = 10, y = 20;
    cout << "Before swap: x=" << x << ", y=" << y << endl;
    swapValues(x, y);
    cout << "After swap: x=" << x << ", y=" << y << endl;

    // 클래스 템플릿 테스트
    Pair<int> intPair(3, 7);
    cout << "Pair: (" << intPair.getFirst() << ", " << intPair.getSecond() << ")\n";
    cout << "Sum of pair: " << addUp(intPair) << endl;

    // PFArrayBak 테스트
    PFArrayBak<string> arr(3);
    arr.addElement("Hello");
    arr.addElement("Templates");
    arr.addElement("World");
    cout << "Array contents before backup:\n";
    for (int i = 0; i < arr.getNumberUsed(); i++) cout << arr[i] << " ";
    cout << endl;

    arr.backup();
    // 배열을 일부 변경
    arr[0] = "Changed";
    cout << "Array after change:\n";
    for (int i = 0; i < arr.getNumberUsed(); i++) cout << arr[i] << " ";
    cout << endl;

    arr.restore();
    cout << "Array after restore:\n";
    for (int i = 0; i < arr.getNumberUsed(); i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}