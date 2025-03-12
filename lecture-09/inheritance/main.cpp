#include <string>
#include <iostream>

using namespace std;

class Hotel
{
public:
    void getRooms() const
    {
        cout << rooms << endl;
    };
    void getName() const
    {
        cout << name << endl;
    };
    Hotel(string name, int rooms); // 생성자
protected: // 상속 받은 클래스에서도 접근 가능 그러나 밖에선 불가능
    int star;
    string name;
private:
    int rooms;
};

Hotel::Hotel(string name, int rooms): rooms(rooms), name(name), star(5)
{
}


class Fairmont:public Hotel
{
public:
    Fairmont(string name, int rooms, int star);
    void canSleep() const{
        cout << star << endl;
    };
    void getName() const
    {
        cout << "Fairmont " << name << endl;
    }; // Redefining
};

Fairmont::Fairmont(string name, int rooms, int star):Hotel(name, rooms)
{
    this->star = 4;
}


int main()
{
    Fairmont fm("Hello", 12, 5); // 생성자는 상속 되지 않음, 파괴자도 상속 안됨, 복사 및 할당 연산자도 상속 안됨
    fm.Hotel::getName(); // 부모 클래스의 getName 함수 사용
    fm.canSleep();
    return 0;
}