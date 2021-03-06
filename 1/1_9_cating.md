# 명시적 형변환 type cast
C언어에서 명시적 형변환은 다음과 같이 사용했다
```c
(자료형) 형변환대상
```
C++ 에서는 4가지의 형변환 연산자가 존재하며 형식은 다음과 같다
```c
형변환_연산자<자료형>(형변환대상)
```
형변환 연산자의 종류

| 형변환연산자 | 설명 |
|---|:---|
| `dynamic_cast` | 상속관계에서 안전한 형변환 `안전하지 않다면 NULL을 반환`한다. |
| `static_cast` | 컴파일과정에서 형변환대상을 자료형으로 그대로 변환 |
| `reinterpret_cast` | 주어진 내용과 관계없이 bit 수준에서 형변환 |
| `const_cast` | 포인터와 참조자의 const 성향을 제거하는 형변환 |

---
[목록으로](https://github.com/moosin76/cpp_tutorial)