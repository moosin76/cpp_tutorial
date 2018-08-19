# [](배열접근 연산자)의 다중정의

첨자를 이용해 배열에 접근하래의 단점은 사용한 첨자가 유효한 범위의 값인지 검사하지 않기 때문에 때로는 오류가 발생한다.

[] 연산자를 다중정의하여 이러한 문제를 해결해보자.

```c
#include <iostream>
using namespace std;

class SafeArray {
  int limit;
  int *arr;
public :
  SafeArray(int len) :
    limit(len)
  {
    arr = new int[len];
  }

  ~SafeArray() {
    delete[] arr;
  }
  
  // 참조를 반환하여 값을 대입할 수 있게 한다.
  int& operator[](int idx) {
    if (idx < 0 || idx >= limit) {
      cout << "배열의 범위를 벗어났습니다." << endl;
      exit(1); // 프로그램 종료
    }
    return arr[idx];
  }
};

int main() {
  SafeArray arr(5);

  for (int i = 0; i < 5; i++) {
    arr[i] = (i + 1) * 10;
  }

  cout << arr[3] << endl;
  cout << arr[8] << endl;
  cout << arr[0] << endl;
  return 0;
}
```