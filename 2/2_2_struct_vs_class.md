# 구조체와 클래스의 차이점

- struct 대신 class 키워드를 사용
- 가시정지시어가 기본적으로 private이다(구조체는 public)

가시성 지시어(접근제어 레이블)

| 가시성지시어 | 설명 |
|---|---|
|public|어디서든 접근 허용|
|protected|상속 관계에 놓였을때 파생클래스에서 접근 허용|
|private|클래스 내부에 정의된 함수, 친구 함수, 친구 클래스의 멤버 함수 에서 접근 허용 |

---
먼저 지난 시간에 작성한 카운터 구조체를 클래스로 변경해 보겠습니다.

`Counter.h`

```c
#ifndef __COUNTER_H__
#define __COUNTER_H__

class Counter{
private: // 가시성지시어 기본값이므로 생략 가능
  int value;

public: // 가시성 지시어 지금부터 선언되는 것은 모두 public
  void reset();
  void count();
  int getValue();
  void initialize(); // 초기화 함수 추가
};

#endif
```

클래스의 멤버 변수 value는 private 이기 때문에 외부에서 접을을 할 수가 없으므로 `void initialize()` 함수를 만들어 값을 초기화 할 수 있게 합니다.

`Counter.cpp`

기존 내용 하단에 다음과 같이 초기화 함수를 추가 하세요.

```c
(...)

void Counter::initialize() {
  value = 0;
}
```

`main.cpp`

메인 함수에서 `Counter counter = { 0 };` 코드를 다음과 같이 변경하세요.  

```c
(...)
int main() {
  Counter counter; // 생성
  counter.initialize(); // 초기화 함수 실행
(...)
```

## 인라인 함수는 헤더파일에 작성해야 합니다

예제의 함수들이 모두 간단하여 전부 인라인 함수로 작성을 해도 되겠지만  
대표적으로 `reset()` 함수와 `initialize()`함수를 인라인 함수로 변경합시다.

`Couner.h`

```c
#ifndef __COUNTER_H__
#define __COUNTER_H__

class Counter{
private:
  int value;

public: 
  void reset();
  void count();
  int getValue();
  void initialize(); 
};

// 인라인 함수는 헤더파일에 작성합니다.
inline void Counter::reset() {
  value = 0;
}

inline void Counter::initialize() {
  value = 0;
}

#endif
```

그리고 `Counter.cpp` 파일에서 `reset()`, `initialize()` 함수 관련 코드를 삭제합니다.

---
[목록으로](https://github.com/moosin76/cpp_tutorial)