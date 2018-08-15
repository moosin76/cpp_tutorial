# this 포인터
클래스 내부에서 `this`를 사용하여 자기 자신을 참조하는 포인터이다.

#### this포인터를 활용한 예제

```c
#include <iostream>
using namespace std;

class Point {
  int x;
  int y;
public :
  Point(int x = 0, int y = 0) : x(x), y(y) {
    cout << "객체 생성" << endl;
   }

  void add(int x, int y = 0) {
    this->x += x;
    this->y += y;
  }

  void show() {
    cout << "[" << x << "," << y << "]" << endl;
  }
};

int main() {
  Point p1(10, 50);
  Point p2(20);

  p1.add(20, -10);
  p2.add(5, 23);
  p1.show();
  p2.show();
}
```

# 자기 자신 참조자(Self Reference) 반환

this포인터가 가리키는 값을 반환하여 참조자를 반환할 수 있다.

```c
#include <iostream>
using namespace std;

class Point {
  int x;
  int y;
public :
  Point(int x = 0, int y = 0) : x(x), y(y) { 
    cout << "객체 생성" << endl;
  }

  Point& add(int x, int y = 0) {
    this->x += x;
    this->y += y;
    return *this;
  }

  Point& show() {
    cout << "[" << x << "," << y << "]" << endl;
    return *this;
  }
};

int main() {
  Point p1(10, 50);
  Point& p2 = p1.add(10, -10);

  p1.show();
  p2.show();

  p1.add(15, 15).show().add(-3, -17).show();
  p2.show();
}
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)