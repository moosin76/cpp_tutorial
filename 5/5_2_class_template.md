# 클래스 템플릿

함수 템플릿과 마찬가지로 클래스도 템플릿으로 정의가 가능하다.

# Stack 클래스

스택은 LIFO(Last in first out) 구조로 되어 있는 자료구조 이다.

속성 | 설명
--- | ---
T* buf | 템플릿 자료형 데이터를 저장할 공간
int top | 현재 데이터의 위치를 기억
int size | 스택에 보관할 수 있는 데이터의 최대개수

메서드 | 설명
---|---
Stack()| 생성자
~Stack()| 소멸자
push()| 데이터 하나를 저장
pop() | 데이터 하나를 꺼내옴


`Stack.h`

```c
#ifndef __STACK_H__
#define __STACK_H__

template <typename T>
class Stack {
  T* buf;
  int top;
  int size;
public:
  Stack(int size);
  virtual ~Stack();
  void push(T a);
  T pop();
};

#endif
```

`Stack.cpp`
```c
#include "Stack.h"
#include <iostream>
using namespace std;

template<typename T>
Stack<T>::Stack(int size)
  : top(0), size(size)
{
  buf = new T[size];
}

template<typename T>
Stack<T>::~Stack() {
  delete[] buf;
}

template<typename T>
void Stack<T>::push(T a) {
  if (top >= size) {
    cout << "Error : Stack full" << endl;
    return;
  }
  buf[top++] = a;
}

template<typename T>
T Stack<T>::pop() {
  if (top <= 0) {
    cout << "Error : Stack empty" << endl;
    return NULL;
  }
  return buf[--top];
}
```

`main.cpp`
```c
#include <iostream>
using namespace std;
#include "Stack.h"

int main() {
  Stack<int> iStack(3);
  iStack.push(1);
  iStack.push(2);
  iStack.push(3);
  iStack.push(4);

  cout << iStack.pop() << endl;
  cout << iStack.pop() << endl;
  cout << iStack.pop() << endl;
  cout << iStack.pop() << endl;

  Stack<double> dStack(3);
  dStack.push(1.5);
  dStack.push(2.5);
  cout << dStack.pop() << endl;
  dStack.push(3.5);
  cout << dStack.pop() << endl;
  cout << dStack.pop() << endl;
  return 0;
}
```

## 템플릿 클래스의 파일 구분

예제를 실행하면 링킹과정에서 오류가 발생한다.

템플릿 클래스는 **일반적으로 하나의 헤더파일에 모든 멤버함수의 정의**를 모두 작성한다.

그것이 싫다면 **main.cpp**에 다음과 같이 `include`문을 추가 한다.

```c
(...)
#include "Stack.cpp"
(...)
```

# Linked list 템플릿

연결리스트는 노드들의 포인터로 연속적으로 연결되어 순차적으로 접근 할 수 있는 자료구조 이다.

## Node 템플릿 클래스

Node 클래스는 데이터를 저장하고 다음 노드에 대한 정보를 가지고 있다.
`Node.h`
```c
#ifndef __NODE__
#define __NODE__

template<typename D>
class Node {
public:
  D data;
  Node* next;
  Node(): next(NULL) {}
};

#endif
```

## List 템플릿 클래스

List 클래스는 더미노드 기반의 단순연결리스트를 구현하였다.  

속성 | 설명
--- | ---
Node\<T\>* head | 더미노드
Node\<T\>* cur | 현재 가리키는 노드 위치
Node\<T\>* cur | 이전 노드 위치
int count | Node의 개수

메서드 | 설명
--- | ---
List() | 생성자
~List() | 소멸자
insert() | 연결리스트의 앞에 Node를 삽입
first() |  연결리스트의 첫번째 Node로 이동
next() | 다음 Node로 이동
remove() | Node 제거
getCount()| Node의 개수 반환
 
```c
#ifndef __LIST__
#define __LIST__

#include "Node.h"

template <typename T>
class List {
  Node<T>* head;
  Node<T>* cur;
  Node<T>* before;
  int count;
public :
  List();
  ~List();
  void insert(T data);
  bool first(T& data);
  bool next(T& data);
  T remove();
  int getCount();
};

/* 생성자
 * 더미 노드를 생성
 */
template <typename T>
List<T>::List() 
  : cur(NULL), before(NULL), count(0)
{
  head = new Node<T>; // 더미노드 생성
  head->next = NULL; 
}

/* 소멸자 
* head->next 가 NULL일때까지 삭제 
*/
template <typename T>
List<T>::~List() {
  Node<T>* temp = head; // 더미노드 부터 
  while (temp) {
    head = temp->next; // temp의 다음 노드를 head로 
    delete temp; // 삭제
    temp = head; // 다음삭제할 노드를 temp로 
  }
}

/* insert()
* 값을 받아서 Node를 하나 생성
*/
template <typename T>
void List<T>::insert(T data) {
  Node<T>* newNode = new Node<T>; // 새로운 노드를 할당
  newNode->data = data; // 값을 저장

  newNode->next = head->next; // 첫번째 노드를 새노드의 다음노드로 지정
  head->next = newNode; // 첫번째 노드로 지정
  count++; // 개수를 증가
}

/* first()
* 현재 위치를 맨 처음 Node로 이동시킨다.
* 매개변수에 data값을 참조 시킨다.
* 데이터가 없으면 false 반환
*/
template <typename T>
bool List<T>::first(T& data) {
  if (head->next == NULL) { // 데이터가 없다면 
    return false; // false 반환
  }
  before = head; // 이전포인터는 헤더
  cur = head->next; // 현재 포인터는 더미노드의 next로 첫번째 노드
  data = cur->data; // 현재 데이터를 참조한다.
  return true;
}

/* next()
* 현재 위치를 다음 Node로 이동시킨다.
* 매개변수에 data값을 참조 시킨다.
* 데이터가 없으면 false 반환
*/
template <typename T>
bool List<T>::next(T& data) {
  if (cur->next == NULL) { // 다음 데이터가 없다면
    return false; // false 반환
  }

  before = cur; // 이전 위치를 현재위치로 이동
  cur = cur->next; // 현재위치를 다음위치로 이동
  data = cur->data; // 데이터 값을 참조
  return true;
}

/*
* 현재 위치의 Node를 삭제하고 데이터를 반환한다.
*/
template <typename T>
T List<T>::remove() {
  T data = cur->data; // 현재 데이터 복사
  before->next = cur->next; // 이전 위치의 다음을 현재의 다음으로 
  delete cur; // 현재 Node 삭제
  count--; // 개수 1 감소
  cur = before; // 현재 위치를 이전위치로 이동
  return data;
}

/* getCount()
* 현재 데이터의 개수 반환
*/
template <typename T>
inline int List<T>::getCount() {
  return count;
}
#endif
```

`main.cpp`
```c
#include <iostream>
using namespace std;
#include "List.h"

int main() {
  List<int> list;
  int data;
  list.insert(10);
  list.insert(20);
  list.insert(23);
  list.insert(25);
  list.insert(30);
  list.insert(34);

  cout << "현재 데이터의 개수 : " << list.getCount() << endl;
  if (list.first(data)) {
    cout << data << endl;
    while (list.next(data)) {
      cout << data << endl;
    }
  }
  cout <<endl << "20이상 30이하 삭제" << endl << endl;
  if (list.first(data)) {
    if (data >= 20 && data <= 30) {
      list.remove();
    }
    while (list.next(data)) {
      if (data >= 20 && data <= 30) {
        list.remove();
      }
    }
  }

  cout << "현재 데이터의 개수 : " << list.getCount() << endl;
  if (list.first(data)) {
    cout << data << endl;
    while (list.next(data)) {
      cout << data << endl;
    }
  }
  return 0;
}
```

## 사용자 정의 객체를 저장하는 리스트

이전에 만들었었던 String 클래스를 연결리스트에 사용해 보자.

[String Class 바로가기](https://ezcode.gitbook.io/bnb-cpp/operator-overloading/string-class)

`main.cpp`

```c
#include <iostream>
using namespace std;
#include "List.h"
#include "String.h"

int main() {
  List<String> list;
  String data;
  list.insert("안녕하세요");
  list.insert("반값습니다.");
  list.insert("안녕하세요");
  list.insert("반가워요");

  cout << "현재 데이터의 개수 : " << list.getCount() << endl;
  if (list.first(data)) {
    cout << data << endl;
    while (list.next(data)) {
      cout << data << endl;
    }
  }
  
  cout <<endl << "안녕하세요 삭제" << endl << endl;
  if (list.first(data)) {
    if (data == "안녕하세요") {
      list.remove();
    }
    while (list.next(data)) {
      if (data == "안녕하세요") {
        list.remove();
      }
    }
  }

  cout << "현재 데이터의 개수 : " << list.getCount() << endl;
  if (list.first(data)) {
    cout << data << endl;
    while (list.next(data)) {
      cout << data << endl;
    }
  }
  
  return 0;
}
```

# 템플릿 클래스를 인자로 받는 friend 함수

```c
#include <iostream>
using namespace std;

template <typename T>
class Point {
  T xpos;
  T ypos;
public :
  Point(T x, T y) : xpos(x), ypos(y) {}

  template <typename T> // 없어도 될것 같지만 있어야 함
  friend ostream& operator<<(ostream& os, Point<T>& ref);
};

template <typename T>
ostream& operator<<(ostream& os, Point<T>& ref) {
  os << "[" << ref.xpos << ", " << ref.ypos << "]";
  return os;
}

int main() {
  Point<int> pos1(10, 20);
  Point<char> pos2('G', 'X');
  Point<double> pos3(11.8, 3.14);

  cout << pos1 << endl;
  cout << pos2 << endl;
  cout << pos3 << endl;
  return 0;
}
```