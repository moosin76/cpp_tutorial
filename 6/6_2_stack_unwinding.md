# 스택 풀기 (Stack Unwinding)

어떤 함수를 호출 했는데 그 함수안에서 `throw`절이 실행되어 예외가 발생했다.
그런데 이 함수내에는 예외처리를 위한 try~catch 블럭이 존재하지 않는다면 **예외처리는 그 함수를 호출한 영역으로 넘어가게 된다**.

```c
#include <iostream>
using namespace std;

void divide(int num1, int num2) {
  if (num2 == 0) {
    throw num2; // 예외 발생 
  }
  cout << "몫 : " << num1 / num2 << endl;
  cout << "나머지 : " << num1 % num2 << endl;
}

int main() {
  int num1, num2;

  cout << "두개의 수를 입력 : ";
  cin >> num1 >> num2;

  try { // 예외 상황이 발생할수 있는 부분
    divide(num1, num2);
    cout << "나눗셈 완료" << endl;
  }
  catch (int err) { // int 자료형을 받아서 처리한다.
    cout << "나누는 수는 " << err << "이 될 수 없습니다." << endl;
    cout << "프로그램을 다시 시작하세요." << endl;
  }
  cout << "프로그램을 종료합니다." << endl;
  return 0;
}
```

예외처리가 되지 않아서 함수를 호출한 영역으로 예외 데이터가 전달되는 현상을 "스택 풀기"라고 한다. 

# 하나의 try블럭과 다수의 catch블럭

```c
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char* str) throw(int, char) {
  int len = strlen(str);
  int num = 0;

  if (len != 0 && str[0] == '0') {
    throw 0; // int 자료형 throw
  }

  for (int i = 0; i < len; i++) {
    if (str[i] <'0' || str[i]> '9') {
      throw str[i]; // char 자료형 throw
    }
    num += (int)(pow((double)10, (len - 1) - i) * (str[i] - '0'));
  }
  return num;
}

int main() {
  char str1[100];
  char str2[100];

  while (1) {
    cout << "두개의 숫자 입력 : ";
    cin >> str1 >> str2;

    try {
      int num1 = StoI(str1);
      int num2 = StoI(str2);
      cout << str1 << " + " << str2 << " = " << num1 + num2 << endl;
      break;
    }
    catch (int errNum) {
      cout << errNum << "으로 시작하는 숫자는 입력 불가" << endl;
    }
    catch (char errCh) {
      cout << "문자 " << errCh << "가 입력되었습니다." << endl;
    }
    cout << "재입력을 진행합니다." << endl << endl;
  }
  cout << "프로그램을 종료합니다." << endl;
  return 0;
}
```
## 전달되는 예외 명시

예제에서 `int StoI(char* str) throw(int, char)` 처럼 함수의 원형에는 반환자료형, 함수이름, 매개변수 정보에 더해서 함수 내에서 전달될 수 있는 예외의 종류를 명시할 수 있다. 

`throw(int, char)`와 같이 예외 정보를 명시했을 때에는 int와 char자료형 외의 다른 예외 데이터가 전달되면 terminate 함수의 호출로 인해 프로그램이 종료되고 만다.

`throw()` 전달되는 자료형을 명시하는 부분이 비어 있는 경우에는 어떠한 예외도 전달하지 않음을 의미한다. 그러므로 어떠한 예외라도 발생하면 프로그램은 종료된다.

## 모든 예외 검출

catch의 매개변수를 엘립스(...) 으로 표현하면 모든 종류의 예외를 포착할 수 있다.

```c
try {
  // 예외가 발생할 가능성 있는 문장
}
catch(exptype1 e) {
  // exptype1 자료형 예외 처리
}
catch(exptype2 e) {
  // exptype2 자료형 예외 처리
}
catch(...) {
  // 위에서 처리가 안된 모든 유형의 예외 처리
}
```