# 참조자(Reference)

변수를 선언하면 자료형의 크기만큼 메모리 공간을 할당받고, 할당된 공간을 `변수명으로 접근`이 가능하다.  
참조자란 할당된 메모리 공간을 접근할 때 `변수명을 대신할 수 있는 또 하나의 이름`이다.  
즉, 변수에 별명을 하나 붙여 주는것 입니다.

## 참조자의 선언
참조자는 참조명 앞에 &를 붙여 선언합니다.  
참조자의 수는 제한이 없으며, 참조자를 대상으로 참조할 수 있습니다.   


```c
#include <iostream>
using namespace std;

int main(void)
{
  int num = 10;
  int &ref = num; // 참조
  int &dref = ref; // 참조
  
  cout << &num << endl; // 주소출력
  cout << &ref << endl;
  cout << &dref << endl;
  return 0;
}
```

참조자는 변수에 대해서만 선언이 가능하고, 선언과 동시에 참조를 해야만 한다.

```c
int &ref = 20; // 리터럴은 참조할 수 없다.
int &ref; // 참조자는 선언과 동시에 참조해야 한다.
int &ref = NULL // NULL은 참조할 수 없다.
```

# 참조자와 함수
이미 배웠던 것들
- Call-by-value : 값을 인자로 전달하는 호출 방식
- Call-by-reference : 주소값을 인자로 전달하는 호출방식

복습의 의미에서 다시 코드를 봅시다.

## Call-by-value
```c
#include <iostream>
using namespace std;

void swap(int a, int b);

int main(void)
{
  int num1 = 10;
  int num2 = 20;
  cout << "swap 함수 호출전 : " << num1 << ", " << num2 << endl;
  swap(num1, num2);
  cout << "swap 함수 호출후 : " << num1 << ", " << num2 << endl;
  return 0;
}

void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
  cout << "swap 함수 내  부 : " << a << ", " << b << endl;
}
```
매개변수는 복사되어 전달되므로 swap 함수내부에서 main함수의 변수에 접근할 수 없다.

## Call-by-reference
```c
#include <iostream>
using namespace std;

void swap(int *a, int *b); // 포인터로 받음

int main(void)
{
  int num1 = 10;
  int num2 = 20;
  cout << "swap 함수 호출전 : " << num1 << ", " << num2 << endl;
  swap(&num1, &num2); // 주소값 전달
  cout << "swap 함수 호출후 : " << num1 << ", " << num2 << endl;
  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  cout << "swap 함수 내  부 : " << *a << ", " << *b << endl;
}
```
주소값을 전달하므로 swap 함수 내부에서 main함수의 변수에 접근하여 두 값을 교환할 수 있다.

## 참조자를 이용한 Call-by-reference
```c
#include <iostream>
using namespace std;

void swap(int &a, int &b); // 참조자로 받음

int main(void)
{
  int num1 = 10;
  int num2 = 20;
  cout << "swap 함수 호출전 : " << num1 << ", " << num2 << endl;
  swap(num1, num2); // 변수 전달
  cout << "swap 함수 호출후 : " << num1 << ", " << num2 << endl;
  return 0;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
  cout << "swap 함수 내  부 : " << a << ", " << b << endl;
}
```
형식매개변수를 참조자로 받게되면 실매개변수의 참조자가 되므로 별칭이 생긴것과 같으므로 swap함수 내부에서 main 함수의 변수에 접근이 가능하다.

# 참조자와 const
참조자를 이용한 Call-by-reference는 포인터를 활용하는것 보다 활용하기 쉽기 때문에 참조자를 사용하는것이 좋아보인다.  
하지만 참조자를 사용하는것이 무조건 좋은것은 아니다.
다음의 코드를 예상해보자
```c
int num = 20;
func(num);
cout << num;
```
func 함수 호출후에 num값을 출력했을때 결과가 어떻게 될것인지 생각해보자.
func 함수의 원형이 다음과 같다면
```c
void func(int a); // 이렇다면 20이 출력된다.
void func(int &a); // 참조로 받는다면 a값이 변경될 수도 있다.
```

`const`를 사용하여 참조로 받지만 a값을 변경할 수 없도록 상수화 한다.

```c
void func(const int &a); 
```

# 반환형이 참조자료형인 함수
참조자도 반환할 수 있다.  
참조자도 하나의 자료형으로 생각하자!
```c
#include <iostream>
using namespace std;

int& add(int&); // 참조자를 반환

int main(void)
{
  int num1 = 10;
  int &num2 = add(num1); // 참조자로 받는다.
   
  cout << &num1 << endl;
  cout << &num2 << endl;
  return 0;
}

int& add(int &a) {
  a++;
  return a;
}
```

# 잘못된 참조 반환
```c
#include <iostream>
using namespace std;

int& add(int&);

int main(void)
{
  int num1 = 10;
  int &num2 = add(num1); // 스택에서 제거되므로 쓰레기 값이 들어가짐
   
  cout << num1 << endl;
  cout << num2 << endl; // 쓰레기값 출력
  return 0;
}

int& add(int &a) {
  int num = 20;
  num += a;
  return num; // 반환후 스택에서 제거됨
}
```

# 상수화된 변수를 참조하는 const 참조자
```c
const int num = 10; // 상수화된 변수
const int &ref1 = num; // 상수화된 변수 참조 가능
int &ref2 = num; // 컴파일 에러
const int &ref3 = 50; // 리터럴 상수도 참조 가능
```
리터럴 상수가 참조가 가능한 것은 컴파일러가 리터럴 상수를 임시 변수를 만들고 그것을 참조자가 참조하게 되는것이다.

---
[목록으로](https://github.com/moosin76/cpp_tutorial)



