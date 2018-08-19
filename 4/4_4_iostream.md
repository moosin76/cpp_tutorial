# 스트림 입출력의 정체

이제 `cout << 10 << endl`과 같이 `<<`연산자가 오버로딩되어 출력연산이 일어지는 것을 알 수 있을것이다.

다음의 예제를 통해 cout과 endl에 대한 이해를 해보자

```c
#include <iostream>

namespace myStd 
{
  using namespace std; // myStd 내에서만 사용

  class ostream {
  public :
    ostream& operator<<(const char * str) {
      printf("%s", str);
      return *this;
    }
    ostream& operator<<(char ch) {
      printf("%c", ch);
      return *this;
    }
    ostream& operator<<(int num) {
      printf("%d", num);
      return *this;
    }
    ostream& operator<<(double e) {
      printf("%g", e);
      return *this;
    }

    ostream& operator<<(ostream& (*fp)(ostream&)) {
      return fp(*this);
    }
  };

  ostream& endl(ostream& os) { // 전역함수
    os << '\n';
    fflush(stdout); // 출력버퍼 비우기
    return os;
  }

  ostream cout; // 객체 생성
}

int main() {
  using myStd::cout;
  using myStd::endl;

  cout << "파이는 " << 3.14 << " " << 123 << endl;
  return 0;
}
```

예제에서 보이듯이 셀프레퍼런스를 반환하여 계속 사용이 가능하게 구성되었다.

# 사용자 정의 객체와 스트림 입출력

앞서본 예제의 Point 클래스는 `showPosition()` 함수로 출력하였다.  
`<<` 연산자를 오버로드하여 다음과 같이 호출하는 형태를 만들어 보자

```c
Point pos(10,20);
cout << pos << endl;
```

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

  friend ostream& operator<<(ostream& os, const Point& ref);
};

ostream& operator<<(ostream& os, const Point& ref) {
  os << "[" << ref.xPos << ", " << ref.yPos << "]";
  return os;
}

int main() {
  Point pos(10, 20);
  cout << pos << endl;
  return 0;
}
```
cout 은 `ostream` 클래스의 객체 이며 `<iostream>`헤더파일에 선언되어 있다.

cin은 `istream` 클래스의 객체이다.  
cin을 이용해 다음과 같은 형태로 입력받도록 `>>` 연산자를 다중정의 해보자
```
Point pos;
cin >> pos;
```

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

  friend ostream& operator<<(ostream& os, const Point& ref);
  friend istream& operator>>(istream& is, Point& ref);
};

ostream& operator<<(ostream& os, const Point& ref) {
  os << "[" << ref.xPos << ", " << ref.yPos << "]";
  return os;
}

istream& operator>>(istream& is, Point& ref) {
  is >> ref.xPos >> ref.yPos;
  return is;
}

int main() {
  Point pos;
  cout << "x, y 형태로 입력 : ";
  cin >> pos;
  cout << pos << endl;
  return 0;
}
```






