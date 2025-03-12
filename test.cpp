#include <iostream>
#include <string>

using namespace std;

class Airlines{
public:
int getPlanes();
string getName();
Airlines(string name, int planes);
virtual void sayHello();
private:
int planes;
string name;
};

class KoreanAir:public Airlines {
public:
KoreanAir(string meal);
void getMeal();
void sayHello() override;
private:
string meal;
};

int main(){
KoreanAir a("shin");
a.getMeal();
a.sayHello();
return 0;
}


Airlines::Airlines(string name, int planes):name(name), planes(planes){}

void Airlines::sayHello(){
cout << "Hello Sky" << endl;
}

int Airlines::getPlanes(){
return planes;
}

string Airlines::getName(){
return name;
}

KoreanAir::KoreanAir(string meal):Airlines("Korean Air", 300), meal(meal){}

void KoreanAir::getMeal(){
cout << meal << endl;
}

void KoreanAir::sayHello(){
cout << getName() << " Hello" << endl;
}


