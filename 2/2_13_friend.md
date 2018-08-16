# friend

가시성 지시어 private에 대해 다음과 같이 설명하였다.

> 클래스 내부에 정의된 함수, 친구 함수, 친구 클래스의 멤버 함수 에서 접근 허용 

따라서 친구 클래스 또는 친구함수를 선언하면 해당 객체의 private 멤버에 접근을 허용한다.

# friend 클래스

```c
#include <iostream>
#include <cstring>
using namespace std;

class Boy; // Boy 클래스가 있다고 알림

class Girl {
  char name[20];
  char phone[20];
public:
  Girl(const char *name, const char *phone) {
    strcpy(this->name, name);
    strcpy(this->phone, phone);
  }
  friend class Boy; // Boy 클래스를 친구로 선언
};

class Boy {
  char name[20];
public:
  Boy(const char*name) {
    strcpy(this->name, name);
  }
  void showInfo(Girl &frn) {
    cout << "나는 " << name << "입니다." << endl;
    cout << "내 여자친구 이름은 " << frn.name << "입니다." << endl;
    cout << "그녀의 전화번호는 " << frn.phone << "입니다" << endl;
  }
};

int main() {
  Boy boy("홍길동");
  Girl girl("김지은", "010-0000-1234");
  boy.showInfo(girl);
  
  return 0;
}
```

Girl 클래스에서 Boy 클래스를 친구로 등록하였다.  
Boy 클래스에서 Girl 클래스의 객체를 접근할때 private 멤버에 직접 접근이 가능하다.  
firend 선언은 **정보은닉**을 무너뜨리는 문법이기 때문에 남용하지 말아야 한다.  
이후 연산자 오버로딩을 공부하면서 friend를 사용해 보게 될 것이다.

# friend 함수

클래스 뿐만 아니라 전역 함수를 대상으로도 friend 선언이 가능하다

```c
#include <iostream>
#include <cstring>
using namespace std;

class Point;

class PointOP {
public:
  Point add(const Point&, const Point&);
};

class Point {
  int x, y;
public:
  Point(int x, int y) 
    : x(x),y(y) {}

  // PointOP 클래스의 멤버함수를 친구로 선언
  friend Point PointOP::add(const Point&, const Point&);

  // 전역함수를 친구로 선언
  friend void showPointInfo(const Point&); 
};

int main() {
  Point p1(10, 20);
  Point p2(15, 25);
  PointOP op;

  showPointInfo(p1);
  showPointInfo(p2);

  Point p3 = op.add(p1, p2);
  showPointInfo(p3);
  return 0;
}

Point PointOP::add(const Point& p1, const Point& p2) {
  return Point(p1.x + p2.x, p1.y + p2.y);
}

void showPointInfo(const Point& pt) {
  cout << pt.x << ", " << pt.y << endl;
}
```

---
[목록으로](https://github.com/moosin76/cpp_tutorial)

