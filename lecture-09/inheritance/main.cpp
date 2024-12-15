#include <string>

using namespace std;

class Hotel
{
public:
    int getRooms() const;
    string getName() const;
    Hotel(string name, int rooms); // 생성자
protected: // 상속 받은 클래스에서도 접근 가능 그러나 밖에선 불가능
    int star;
private:
    int rooms;
    string name;
};

class Fairmont:public Hotel
{
public:
    Fairmont(string name, int rooms, int star);
    bool canSleep() const;
    string getName() const; // Redefining
};

int main()
{
    Fairmont fm("Hello", 12, 5); // 생성자는 상속 되지 않음, 파괴자도 상속 안됨, 복사 및 할당 연산자도 상속 안됨
    fm.Hotel::getName(); // 부모 클래스의 getName 함수 사용
    return 0;
}