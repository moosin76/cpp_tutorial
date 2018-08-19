# 교환법칙

### A+B 는 B+A와 결과가 같다.  

곱셈 연산과 덧셈연산은 교환법칙이 성립하는 연산이다.  
이때 두 자료형이 다른경우에는 자료형에 맞는 연산자 다중정의를 해야 한다.

```c
#include <iostream>
using namespace std;

class Point {
  int xPos;
  int yPos;
public:
  Point() {}

  Point(int x, int y)
    : xPos(x), yPos(y) {}
  
  void showPosition() const {
    cout << "[" << xPos << ", " << yPos << "]" << endl;
  }

  Point operator*(int num) {
    Point pos(xPos*num, yPos*num);
    return pos;
  }

  friend Point operator*(int num, Point& ref);
};

Point operator*(int num, Point& ref) {
  return ref * num;
}

int main() {
  Point p1(3, 5);
  Point p2 = p1 * 10;
  Point p3 = 5 * p1;

  p1.showPosition();
  p2.showPosition();
  p3.showPosition();
  return 0;
}
```

`Point operator*(int num)` 함수와 `friend Point operator*(int num, Point& ref)` 함수가 교환 법칙을 이루고 있다.

그리고 이러한 형태로 **서로 다른 자료형을 대상으로 한 연산자 오버로딩**도 구현이 가능하다는 것이다.