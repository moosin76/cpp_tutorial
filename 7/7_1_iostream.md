# 출력스트림 함수

## 문자 및 문자열 출력

- `ostream& put(char)` 하나의 문자를 출력한다.  
- `ostream& write(const char* str, int count)` 문자열을 count 만큼 출력한다.

```c
#include <iostream>
using namespace std;

int main() {
  // put(char) 하나의 문자를 출력한다.
  cout.put('H').put('e').put('l').put(108).put('o').put('\n');

  // write(const char* str, int count) 문자열을 count 만큼 출력한다.
  char name[20] = "ezcode";
  for (int i = 1; i < 10; i++) {
    cout.put('|').write(name, i).put('|').put('\n');
  }

  return 0;
}
```

## 출력 버퍼 비우기

```c
cout << "출력 문자열" << flush;  // 강제로 버퍼를 비운다.
cout << "출력 문자열" << endl;  // 개행을 한 후 강제로 버퍼를 비운다.
```

## 문자폭 변경

- `int width()` 설정된 출력 문자폭을 반환  
- `int width(int)` 출력 문자폭을 설정, 하나의 출력에만 영향을 준다.
```c
#include <iostream>
using namespace std;

int main() {
  cout << "01234567890123456789" << endl;
  cout.width(10);
  cout << 123 << endl; // 하나의 출력만 영향이 있다
  cout << 123 << endl; 
  cout.width(10);
  cout << 123 << endl;
  return 0;
}
```
## 공백 채우기

- `char fill()` 설정된 채움문자 반환
- `char fill(char)` 채움문자를 설정

```c
#include <iostream>
using namespace std;

int main() {
  cout << "01234567890123456789" << endl;
  char ch = cout.fill('*'); // 채움문자 설정
  cout.width(10);
  cout << 123 << endl;
  cout.fill(ch); // 원래 채움문자로 설정
  cout.width(10);
  cout << 123 << endl;
  return 0;
}
```

## 소수점의 자릿수 변경

- `int precision()` 실수 표시 문자수 반환 기본값 6
- `int precision(int)` 실수 표시 문자수 설정

```c
#include <iostream>
using namespace std;

int main() {
  double num = 123.12345678901234;
  cout << "12345678901234567890" << endl;
  int p = cout.precision(15); // 표시 문자수 설정
  cout << num << endl;
  cout.precision(p); // 원래 표시 문자수로 설정
  cout << num << endl;
  return 0;
}
```

## 진법 표시 전환

- `dec(cout)` 기본값, 10진수로 표시 `cout << dec`과 동일
- `hex(cout)` 16진수로 표시  `cout << hex`과 동일
- `oct(cout)` 8진수로 표시 `cout << oct`과 동일

```c
#include <iostream>
using namespace std;

int main() {
  int num = 12345;
  cout << "기본값 : " << num << endl;
  hex(cout);
  cout << "16진수 : " << num << endl;
  cout << oct;
  cout << "8진수  : " << num << endl;
  cout << "10진수 : " << dec << num << endl;
  return 0;
}
```

# 입력 스트림 함수

## 문자 1개 입력

- `int get()` 공백을 건너뛰지 않고 문자 하나를 입력 하여 반환
- `istream& get(char&)` 공백을 건너뛰지 않고 문자 하나를 입력

```
#include <iostream>
using namespace std;

int main() {
  char a, b, c;
  cout << "문자 3개 입력" << endl;
  a = cin.get();
  cin.get(b).get(c);
  cout << endl << "입력받은 문자열" << endl;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  return 0;
}
```

## 입력 스트림 비우기
- `istream& ignore(int=1, int=EOF)` 

첫번째 매개변수는 제거할 문자의 최대 개수  
두번째 매개변수는 종료문자

## 공백을 포함한 문자열 입력

공백을 포함하는 문자열을 입력받을 때 사용

- `istream& get(char* int, char='\n')`
- `istream& getline(char* int, char='\n')`

첫번째 매개변수는 저장될 문자열의 포인터  
두번째 매개변수는 문자열의 크기  
세번째 매개변수는 라인을 구분하는 구분자로 기본값,'\n'

```c
#include <iostream>
using namespace std;

int main() {
  char str[30];
  cout << "문자열을 입력하세요 : ";
  cin >> str; 
  cout << "입력한 문자열 : " << str << endl;

  cout << "문자열을 입력하세요 : ";
  cin.ignore(80, '\n'); // 입력버퍼를 비운다.
  cin.get(str, sizeof(str)); // 공백을 포함하여 입력받는다.
  cout << "입력한 문자열 : " << str << endl;
  return 0;
}
```





