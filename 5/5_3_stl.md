# 표준 템플릿 라이브러리

STL(Standard Template Library)은 C++ 언어가 제공하는 템플릿을 사용한 컨테이너 클래스를 제공하는 라이브러리 이다.

STL의 구성요소는 **컨테이너**, **반복자**, **알고리즘**이다.

## 컨테이너(container)

컨테이너는 순차 컨테이너와 연상 컨테이너가 있다.

### 순차 컨테이너(sequences container)
종류 | 특성
---|---
vector | <ul><li>**확장가능한 배열**</li><li>첨자를 이용한 빠른접근</li><li>끝에서 삽입(삭제)은 빠르나 그외의 위치에서의 삽입(삭제)은 느리다</li></ul>
list| <ul><li>이중 연결리스트</li><li>어느위치든 삽입(삭제)가 효율적이다</li><li>직접 접근이 어렵다</li></ul>
deque| <ul><li>vector와 동일하나 앞에서도 효율적으로 삽입(삭제)할 수 있다</li></ul>

### 연관 컨테이너(associative container)
종류 | 특성
---|---
set | 키만 저장하면 키값의 중복을 허용하지 않음
multiset | 키값의 중복을 허용하는 set
map | 키에 대응되는 값까지 같이 보관하며 키의 중복을 허용하지 않음
multimap | 키의 중복을 허용하는 map

## 반복자(iterator)

반복자는 포인터의 개념을 일반화 한것으로 컨테이너에 저장된 원소를 순회하고 접근하는 일반화된 방법을 제공한다.
반복자는 컨테이너와 알고리즘을 하나로 동작하게 묶어주는 인터페이스 역활을 한다.

반복자 | 설명
---|---
순방향 반복자<br>(forward iterator) | 입력, 출력 반복자 기능에 순방향으로 이동(++)이 가능한 재할당될 수 있는 반복자
양방향 반복자<br>(bidirectional iterator) | 순방향 반복자 기능에 역방향으로 이동(--)이 가능한 반복자 ( list, set, mulitset, map, multimap)
임의 접근 반복자<br>(random access iterator) | 양방향 반복자 기능에 +, -, += , -=, [] 연산이 가능한 반복자 (vector, deque)

## 알고리즘

알고리즘은 반복자를 사용하여 컨테이너의 원소에 대해 적용할 수 있는 여러가지 연산을 제공한다.

### 대표적인 STL 알고리즘
알고리즘 | 설명
---|---
search | 주어진 값과 동일한 첫버째 요소를 반환
count | 주어진 값과 일치하는 요소의 수를 반환
swap | 컨테이너 안의 값을 교환
sort | 컨테이너의 값들을 지정된 순서에 따라 정렬
merge | 정렬된 두 영역의 원소들을 병합
reverse | list의 원소들을 역순으로 나열
remove | 컨테이너에서 지정된 값을 제거
replace | 지정된 값은 다른 값으로 대체 
unique | 인접 위치에 있는 중복된 값을 제거
for_each | 지정된 함수를 컨테이너의 모든 원소에 적용


# Vector 클래스 
vector 클래스 템플릿은 배열개념을 구현한 클래스이다.  
vertor는 크기가 고정되지 않고 필요에 따라 공간이 확장 될 수 있다.

### vertor의 크기 확장 및 데이터조작 관련 메서드
메서드| 설명
---|---
push_back(value) | 끝에 데이터 추가
pop_back | 끝에 데이터를 꺼내오고 제거
size() | 논리적 크기 반환
resize(n) | 논리적 크기 변경
capacity() | 물리적 크기 반환
reserve(n) | capacity()가 최소한 n을 반환하도록 확장
empty() | 비어있는 벡터의 경우 true반환
erase(it) | 반복자(it)가 가리키는 위치 삭제
erase(it1, it2) | it1 ~ it2 범위의 데이터 삭제
insert(it, value) | 반복자가 가리키는 위치에 value 삽입

`<vector>`를 포함해야 한다.

```c
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec(5);

  for (int i = 0; i < vec.size(); i++) {
    vec[i] = i + 1;
  }

  cout << "백터의 논리적 크기 : " << vec.size() << endl;
  cout << "백터의 물리적 크기 : " << vec.capacity() << endl;
  cout << endl;

  vec.push_back(11);
  cout << "백터의 논리적 크기 : " << vec.size() << endl;
  cout << "백터의 물리적 크기 : " << vec.capacity() << endl;

  cout << "저장된 데이터 : ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
  return 0;
}
```

## 반복자 사용
반복자는 마치 포인터와 같은 방식으로 접근할 수 있도록 한다.
vertor 객체의 `begin()`은 첫번째 원소를 가리키며, `end()-1` 는 마지막 원소를 가리킨다.

```c
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec(5);

  for (int i = 0; i < vec.size(); i++) {
    vec[i] = i + 1;
  }

  vector<int>::iterator it;
  cout << "저장된 데이터 : ";
  for (it = vec.begin(); it < vec.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  auto it2 = vec.begin();
  cout << "3번째 데이터 : " << *(it2+2) << endl;
  
  it2 = vec.end()-1;
  cout << "마지막 데이터 : " << *it2 << endl;
  return 0;
}
```

## 알고리즘 사용

알고리즘을 사용하기 위해서는 `<algorithm>`을 포함해야 한다.

난수를 사용해 두개의 vector를 생성하고 정렬한 다음 하나로 병합해보자.

```c
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime> // time 함수사용
#include <cstdlib> // rand 함수사용
using namespace std;

int main() {
  vector<int> vec1(5);
  vector<int> vec2(7);
  vector<int>::iterator it;

  srand((unsigned int)time(NULL)); // 시드 초기화

  // 첫번째 백터에 난수 입력
  for (it = vec1.begin(); it < vec1.end(); it++) {
    *it = rand() % 100;
  }

  // 두번째 백터에 난수 입력
  for (it = vec2.begin(); it < vec2.end(); it++) {
    *it = rand() % 100;
  }

  cout << "첫번째 백터 : ";
  for (it = vec1.begin(); it < vec1.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "두번째 백터 : ";
  for (it = vec2.begin(); it < vec2.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // 백터 정렬
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());

  cout << endl << "정렬된 후 데이터" << endl;
  cout << "첫번째 백터 : ";
  for (it = vec1.begin(); it < vec1.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "두번째 백터 : ";
  for (it = vec2.begin(); it < vec2.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // 백터 병합
  vector<int> vec3(vec1.size() + vec2.size()); // 병합할 벡터
  merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());

  cout << endl << "두 벡터의 병합 결과 : ";
  for (it = vec3.begin(); it < vec3.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
```
