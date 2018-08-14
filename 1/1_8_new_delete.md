# 메모리 동적할당의 새로운 키워드 new & delete

C언어에서는 동적할당을 할때 `malloc()`과 `free()`를 사용하였습니다.
```c
#include <iostream>
#include <stdlib.h>
using namespace std;

char* inputString(int len) {
  cout << len << "자 입력 : ";
  char* str = (char*)malloc(len);
  cin >> str;
  return str;
}

int main(void)
{
  char* str = inputString(30);
  cout << "입력받은 문자열 : " << str << endl;
  free(str);
  return 0;
}
```

|code|설명|
|---|---|
|int* ptr = `new int`|int형 변수 할당|
|double* arr = `new double[3]`|길이가 3인 int형 배열 할당|
|`delete` ptr|할당한 ptr변수 소멸|
|`delete[]` arr|할당한 arr배열 소멸|

```c
#include <iostream>
#include <cstdlib>
using namespace std;

char* inputString(int len) {
  cout << len << "자 입력 : ";
  // char* str = (char*)malloc(len);
  char* str = new char[len]; // char형 배열 할당
  cin >> str;
  return str;
}

int main(void)
{
  char* str = inputString(30);
  cout << "입력받은 문자열 : " << str << endl;
  // free(str);
  delete[] str; // 배열 소멸
  return 0;
}
```
# 참고 C++ 에서 C언어 표준함수 사용하기
.h를 빼고 앞에 c를 붙이면됩니다.  

| C표준 | | C++표준 |
|---|:---:|---|
| `#include <stdio.h>` | -> | `#include <cstdio>` |
| `#include <stdlib.h>` | -> | `#include <cstdlib>` |
| `#include <math.h>` | -> | `#include <cmath>` |
| `#include <string.h>` | -> | `#include <cstring>` |

---
[목록으로](https://github.com/moosin76/cpp_tutorial)