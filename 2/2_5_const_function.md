# const 함수
cosnt 함수는 함수 내부에서 멤버변수의 값을 변경하지 않겠다 라는 의미를 갖습니다.

`void Seller::showStatus()` 함수와 `void Buyer::showStatus()` 함수 모두 함수 내부에서 멤버 변수의 값을 변경하지 않으므로 다음과 같이 const 함수로 작성할 수 있습니다.

`Buyer.h`와 `Seller.h`의 showStatus()를 다음과 같이 수정합니다.
```c
(...)

void showStatus() const;

(...)
```
`Buyer.cpp`와 `Seller.cpp`의 showStatus()를 다음과 같이 수정합니다.

```c
void Buyer::showStatus() const {
  (...)
}
```

```c
void Seller::showStatus() const {
  (...)
}
```

이렇게 const 키워드를 사용하면 함수 내부에서 멤버변수의 값을 변경할때 컴파일 에러가 발생합니다.

---
[목록으로](https://github.com/moosin76/cpp_tutorial)