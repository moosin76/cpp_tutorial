# 새로운 자료형 bool
C언어에서 거짓은 0 참은 0이 아닌 모든수로 정수자료형을 사용하여 참과 거짓을 구분하였습니다.  
그리고 참은 대표적으로 1을 사용한다고 했습니다.

C++에서는 새로운 기본자료형으로 `bool`이 있으며 참과 거짓을 저장합니다.  
`true`와 `false` 값으로 저장이 가능합니다.

```c
#include <iostream>
using namespace std;

bool isPositiveNumber(int num) {
  if (num > 0) {
    return true;
  }
  else {
    return false;
  }
}

int main(void)
{
  bool isPos;
  int num;
  cout << "숫자를 입력하세요 : ";
  cin >> num;
  
  isPos = isPositiveNumber(num);

  if (isPos) {
    cout << "양수 입니다." << endl;
  }
  else {
    cout << "음수 입니다." << endl;
  }
}
```
---
[목록으로](https://github.com/moosin76/cpp_tutorial)