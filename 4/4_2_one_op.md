# 단항 연산자 오버로딩

대표적인 단한 연산자는 다음 두가지가 있다

- +1 증가 연산자 : ++
- -1 감소 연산자 : --

## 전위 표기법

```c
#include <iostream>
using namespace std;

class Point {
  int xPos;
  int yPos;
public:
  Point(int x, int y)
    : xPos(x), yPos(y) {}
  
  void showPosition() const {
    cout << "[" << xPos << ", " << yPos << "]" << endl;
  }

  Point& operator++() {
    xPos += 1;
    yPos += 1;
    return *this;
  }

  friend Point& operator--(Point& ref);
};

Point& operator--(Point& ref) {
  ref.xPos -= 1;
  ref.yPos -= 1;
  return ref;
}

int main() {
  Point pos(10, 10);

  ++(++(++pos));
  pos.showPosition();

  --(--(--pos));
  pos.showPosition();
  return 0;
}
```

전위연산은 참조객체를 넘겨 중첩된 결과가 나올 수 있게 한다.

## 후위 표기법

전위 연산과 후위 연산은 다음과 같은 규칙을 정해놓고 있다

> 전위 연산 : ++pos -> `pos.operator++()`  
> 후위 연산 : pos++ -> `pos.operator++(int)`

이렇게 형식 매개변수에 `int` 키워드를 넣으며 `int`는 단지 후위연산을 구분하기 위한 목적으로 선택된 것이다.

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

  const Point operator++(int) {
    const Point obj(xPos, yPos);
    xPos += 1;
    yPos += 1;
    return obj;
  }

  friend const Point operator--(Point& ref, int);
};

const Point operator--(Point& ref, int) {
  const Point obj(ref);
  ref.xPos -= 1;
  ref.yPos -= 1;
  return obj;
}

int main() {
  Point pos(10, 10);
  Point cpy;

  cpy = pos++;
  cpy.showPosition();
  pos.showPosition();

  cpy = pos--;
  cpy.showPosition();
  pos.showPosition();
  return 0;
}
```
상수객체를 반환하기 때문에 `(pos++)++`이러한 형식은 사용할 수 없다.

이렇게 하는 이유는 C++의 후위연산의 특성을 그대로 반영한 결과이다.

```c
int main() {
  int num = 10;
  (num++)++; // 컴파일 에러
  return 0;
}
```