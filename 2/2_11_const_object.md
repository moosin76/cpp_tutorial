# const 객체
객체도 const로 생성하여 상수화할 수 있다.  
이때 const 함수가 아닌 함수는 호출할 수 없다.

```c
#include <iostream>
using namespace std;

class Simple {
  int num;
public :
  Simple(int n) : num(n) {}
  void add(int n) {
    num += n;
  }
  void showData() const {
    cout << "num : " << num << endl;
  }
};

int main() {
  const Simple obj(7);
  // obj.add(3); // const 함수가 아니기 때문에 호출할 수 없다.
  obj.showData();
  return 0;
}
```

# const함수의 함수오버로딩

함수 오버로딩의 조건은 다음과 같다고 설명하였다.

- 매개변수의 자료형
- 매개변수의 개수

다음과 같은 형태일때는 어떤가

```c
void showData() { ... }
void showData() const { ... }
```

다음의 예제를 실행해보자

```c
#include <iostream>
using namespace std;

class Simple {
  int num;
public :
  Simple(int n) : num(n) {}
  void add(int n) {
    num += n;
  }

  void showData() {
    cout << "showData() 호출 " << endl;
    cout << "num : " << num << endl;
  }

  void showData() const {
    cout << "showData() const 호출 " << endl;
    cout << "num : " << num << endl;
  }
};

int main() {
  Simple obj1(10);
  const Simple obj2(5);

  obj1.showData();
  obj2.showData();
  return 0;
}
```
const 객체에서는 const 함수가 실행이 된다.

---
[목록으로](https://github.com/moosin76/cpp_tutorial)