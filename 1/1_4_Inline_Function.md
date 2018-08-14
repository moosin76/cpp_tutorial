# 인라인 함수(Inline Function)

매크로 함수의 경우 `전처리 단계에서 단순 치환`하여 컴파일 되므로 일반 함수에 비해서 실행속도에 이점이 있다.  
하지만 매크로 함수의 경우 선언식이 복잡해지면 정의하기 어렵고 디버깅하기도 쉽지 않다는 단점이 있다.

간단한 식의 함수의 경우 inline 키워드를 통행 인라인 함수로 정의하여 `컴파일단계에서 인라인화`하여 성능을 끌어올린다.  
하지만 컴파일러가 인라인 함수를 인라인하는 경우 오히려 성능에 좋지 않다면 이 키워드를 무시한다.

```cpp
#include <iostream>
#define SQUARE(x) ((x)*(x)) // 매크로 함수

inline int square(int x) { // 인라인 함수
  return x * x;
}

int main(void)
{
  std::cout << SQUARE(5) << std::endl;
  std::cout << square(5) << std::endl;
  return 0;
}
```

