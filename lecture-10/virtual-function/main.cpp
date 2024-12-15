#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr (C++11 이상)

using namespace std;

// 추상 클래스: Shape
class Shape {
public:
  virtual ~Shape() {} // 소멸자를 가상으로 선언
  virtual void draw() const = 0; // 순수 가상 함수 -> 추상 클래스

  void printCenter() const {
    // 도형을 화면 중앙에 그렸다고 가정하고, 그 상황에서 draw 호출
    cout << "[INFO] Move shape to center.\n";
    draw(); // 여기서 어떤 Shape를 가리키든 해당 파생 클래스의 draw()가 호출됨
  }
};

// 파생 클래스: Circle
class Circle : public Shape {
public:
  Circle(double r) : radius(r) {}

  virtual void draw() const override {
    cout << "Drawing a Circle with radius: " << radius << endl;
  }

private:
  double radius;
};

// 파생 클래스: Rectangle
class Rectangle : public Shape {
public:
  Rectangle(double w, double h) : width(w), height(h) {}

  virtual void draw() const override {
    cout << "Drawing a Rectangle with width: " << width
         << " and height: " << height << endl;
  }

private:
  double width, height;
};

int main() {
  // 다양한 도형을 Shape 포인터(또는 smart pointer)에 담아 관리
  vector<unique_ptr<Shape>> shapes;
  shapes.push_back(make_unique<Circle>(5.0));
  shapes.push_back(make_unique<Rectangle>(10.0, 20.0));
  shapes.push_back(make_unique<Circle>(2.5));

  // 순회하면서 각 도형을 그려봄
  for (const auto& shapePtr : shapes) {
    shapePtr->printCenter(); // 추상 클래스의 비가상 함수 안에서 가상 함수 draw() 호출
    cout << endl;
  }

  return 0;
}