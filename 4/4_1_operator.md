# 연산자 오버로딩의 이해

# 멤버함수에 의한 연산자 오버로딩

```c
#include <iostream>
using namespace std;

class Point {
  int xPos;
  int yPos;
public:
  Point(int x, int y)
    : xPos(x), yPos(y) {}
  
  void showPosition() const  {
    cout << "[" << xPos << ", " << yPos << "]" << endl;
  }

  Point add(const Point &ref) {
    return Point(xPos + ref.xPos, yPos + ref.yPos);
  }
};

int main() {
  Point p1(10, 20);
  Point p2(15, 25);
  Point p3 = p1.add(p2);

  p1.showPosition();
  p2.showPosition();
  p3.showPosition();
  return 0;
}
```

예제코드의 add 함수는 Point 객체의 참조를 받아서 xPos, yPos의 값을 더해 새로운 Point 객체를 반환하는 함수이다.

그럼 다음과 같이 호출할 수 있을까?

```c
Point p3 = p1 + p2;
```
이렇게 기본 연산자인 +연산자를 재정의 하여 사용자정의 자료형도 연산을 할 수 있게 하는것이 연산자 다중정의 이다.

add() 함수의 이름을 `operator+`로 변경한 후 +연산을 해보자.

```c
Point operator+(const Point &ref) {
  return Point(xPos + ref.xPos, yPos + ref.yPos);
}
```
main 함수를 다음과 같이 변경해 보자

```c
int main() {
  Point p1(10, 20);
  Point p2(15, 25);
  Point p3 = p1.operator+(p2);
  Point p4 = p1 + p2;

  p1.showPosition();
  p2.showPosition();
  p3.showPosition();
  p4.showPosition();
  return 0;
}
```

결과를 보면 `p1.operator+(p2);`와 `p1 + p2;` 동일한 것을 알 수 있다.

# 전역함수에 의한 연산자 오버로딩

전역 operator+ 함수를 다중정의(over loading) 하여 친구함수로 등록한다.

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

  friend Point operator+(Point& pos1, Point& pos2);
};

Point operator+(Point& p1, Point& p2) {
  return Point(p1.xPos + p2.xPos, p1.yPos + p2.yPos);
}

int main() {
  Point p1(10, 20);
  Point p2(15, 25);
  Point p3 = p1 + p2;

  p1.showPosition();
  p2.showPosition();
  p3.showPosition();
  return 0;
}
```

# 이항 연산자의 다중정의

## 산술연산자의 다중정의
+, -, *, /, % 등의 산술연산자는 위의 예제를 참고하여 작성할 수 있다.  
이때 연산자의 기본 기능을 벗어난 형태의 연사자 오버로딩은 허용되지 않는다.

## 관계연산자의 다중정의
관계연산자 ==, !=, >, >=, <, <= 등의 관계연산자는 `bool` 자료형을 반환하는 형태로 다중정의 해야 한다.

다음은 `==` 연산자의 예제이다.

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

  bool operator==(const Point& ref) const {
    return xPos == ref.xPos && yPos == ref.yPos;
  }
};

int main() {
  Point p1(10, 20);
  Point p2(10, 20);
  
  if (p1 == p2) {
    cout << "같다" << endl;
  }
  else {
    cout << "다르다" << endl;
  }
  return 0;
}
```

# 참고 사항

## 연산자 다중정의가 불가능한 연산자의 종류

연산자 | 비고
---|---
. | 멤버 접근 연산자 
.* | 멤버 포인터 연산자
:: | 범위지정 연산자
? : | 조건 연산자  
sizeof | 바이트 단위 크기 계산 연산자
typeid | RTTI 관련 연산자 
static_cast<br>dynamic_cast<br>const_cast<br>reinterpret_cast | 형변환 연산자 

## 멤버 함수 기반으로만 오버로딩 가능한 연산자 종류

연산자 | 비고
---|---
= | 대입연산자
() | 함수 호출 연산자
[] | 배열 접근 연산자(인덱스 연산자)
-> | 멤버 접근을 위한 포인터 연산자

## 연산자 오버로딩시 주의 사항
- 본래의 의도를 벗어난 형태의 연사자 오버로딩은 좋지 않다.
- 연산자 우선순위와 결합성은 바뀌지 않는다.
- 매개변수의 디폴트 값 설정이 불가능하다.
- 연산자의 기본 기능을 벗어난 형태의 연사자 오버로딩은 허용되지 않는다.