# string 클래스

C++ 표준 라이브러리에는 string 이라는 클래스가 정의되어 있다.  
string 클래스는 문자열의 처리를 목적으로 정의된 클래스이면 이 클래스를 사용하기 위해서는 헤더파일 `<string>`을 포함해야 한다.

다음은 string 객체의 사용 예제이다.

```c
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str1 = "I like ";
  string str2 = "string class";
  string str3 = str1 + str2;

  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;

  str1 += str2;
  if (str1 == str3) {
    cout << "동일한 문자열" << endl;
  }
  else {
    cout << "다른 문자열" << endl;
  }

  string str4;
  cout << "문자열 입력 : ";
  cin >> str4;
  cout << "입력한 문자열 : " << str4 << endl;
  return 0;
}
```



# String 클래스 
연산자 다중정의를 통해 string과 유사한 클래스를 정의해 보자

### String 클래스의 속성
속성 | 설명
---|---
int len | 문자열의 길이 저장
char *buf | 문자열 저장 공간

### String 클래스의 메서드
메서드 | 설명
---|---
String() | 생성자, 복사생성자
~String() | 소멸자
length() | 문자열의 길이 반환
= | 대입연산
+ | 문자열 연결을 하여 반환
+= | 문자열을 뒤에 추가한다.
==, >, < | 관계연산
<< | 스트림으로 출력한다.
[] | 문자열내의 개별 문자 접근


`String.h`
```
#ifndef __MY_STRING__
#define __MY_STRING__

#include <iostream>
using namespace std;

class String
{
  int len;
  char * buf;
public:
  String(); 
  String(const char*str); 
  String(const String &s); 
  ~String();
  int length() const;
  String& operator=(const String &s);
  String operator+(const String &s);
  String& operator+=(const String &s);
  bool operator==(const String &s);
  bool operator>(const String &s);
  bool operator<(const String &s);
  friend ostream& operator<<(ostream& os, const String& s);
  char& operator[](int idx);
  const char& operator[](int idx) const;
};

/* 문자열 길이 반환 */
inline int String::length() const {
  return len;
}

/* 스트림 출력 */ 
inline ostream& operator<<(ostream& os, const String& s) {
  os << s.buf;
  return os;
}
#endif
```

`String.cpp`

```
#include <cstring>
#include "String.h"


/* 생성자 빈객체 생성*/
String::String() 
  : len(0)
{
  buf = new char[1];
  buf[0] = '\0';
}

/* 생성자 문자열을 받아서 생성 */
String::String(const char*str) {
  len = strlen(str);
  buf = new char[len + 1];
  strcpy(buf, str);
}

/* 복사생성자 */
String::String(const String &s) 
  :len(s.len)
{
  buf = new char[len + 1];
  strcpy(buf, s.buf);
}

/* 소멸자 */
String::~String() {
  delete[] buf;
}

/* 대입 연산자 */
String& String::operator=(const String &s) {
  len = s.len;
  delete[] buf;
  buf = new char[len + 1];
  strcpy(buf, s.buf);
  return *this;
}

String String::operator+(const String &s) {

}

String& String::operator+=(const String &s) {

}

bool String::operator==(const String &s) {

}

bool String::operator>(const String &s) {

}

bool String::operator<(const String &s) {

}

char& String::operator[](int idx) {

}

const char& String::operator[](int idx) const {

}
```




