# 함수 템플릿

예를 들어 다음과 같은 덧셈 함수가 있다고 하자


```c
int add(int num1, int num2) {
  return num1 + num2;
}
```

이것은 정수 매개변수 2개를 더해서 정수를 반환하는 함수이다.  
템플릿은 자료형이 결정되어 있지 않고 기능을 구현한다 다음과 같은 형식으로 만들수 있다.

```c
template <typename T>
T add(T num1, T num2) {
  return num1 + num2;
}
```
**T**는 자료형의 형식 이름으로 사용자가 이름을 지정하면 된다.  
그리고 **T**를 함수 호출시 결정하면 컴파일러가 함수를 만들어 준다.

`typename` 대신에 `class` 키워드를 사용할 수 있다.
```c
template <typename T>
```
```c
template <class T>
```
두가지 모두 같은 선언이다.

함수 템플릿은 `함수이름<자료형>(매개변수)` 형식으로 호출한다.

다음 예제를 통해 함수 템플릿을 호출해 보자

```c
#include <iostream>
using namespace std;

template <typename T>
T add(T num1, T num2) {
  return num1 + num2;
}

int main() {
  cout << add<int>(10, 15) << endl;
  cout << add(31, 7) << endl;
  cout << add<double>(2.9, 3.7) << endl;
  cout << add(3.15, 5.11) << endl;
  return 0;
}
```

`add<int>(10, 15)` 호출되면 컴파일러는 다음과 같은 **템플릿 함수**를 하나 만든다.

```c
int add<int>(int num1, int num2) {
  return num1 + num2;
}
```
`add<double>(2.9, 3.7)` 호출되면 컴파일러는 다음과 같은 **템플릿 함수**를 하나 만든다.

```c
double add<double>(double num1, double num2) {
  return num1 + num2;
}
```

# 둘 이상의 자료형에 대한 템플릿 선언

템플릿 함수의 문법은 다음과 같다

```c
template <templateArgs>
returnType functionName(ParameterList) { ... }
```
templateArgs에 여러개의 자료형을 넣어주면 된다.

```c
#include <iostream>
using namespace std;

template <class T1, class T2>
void showData(double num) {
  cout << (T1)num << " : " << (T2)num << endl;
}

int main() {
  showData<char, int>(65);
  showData<char, int>(67);
  showData<char, double>(68.5);
  showData<short, double>(68.5);
  return 0;
}
```

# 함수 템플릿의 다중정의

함수 템플릿도 함수와 마찬가지로 다중정의를 허용한다.  
먼저 함수 이름과 인수들의 자료형이 정확히 일치하는 함수가 호출되고 그러한 함수가 없을때 변환이 가능한 함수템플릿이 호출된다.

```c
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T max(T a, T b) {
  cout << "T max()" << endl;
  return a > b ? a : b;
}

char* max(char* a, char* b) {
  cout << "char* max()" << endl;
  return (strlen(a) > strlen(b)) ? a : b;
}

const char* max(const char* a, const char* b) {
  cout << "const char* max()" << endl;
  return strcmp(a, b) > 0 ? a : b;
}

int main() {
  cout << max(11, 15) << endl << endl;
  cout << max(6.5, 2.1) << endl << endl;
  char str1[] = "hello";
  char str2[] = "C++ Porogramming";
  cout << max(str1, str2) << endl << endl;
  cout << max("hello", "C++ Porogramming") << endl << endl;
  return 0;
}
```

