# 파일 입출력
C++에서는 파일 입출력을 위해 `iostream`에서 파생된 파일 입력을 위한 `ifstream` 클래스와 파일 출력을 위한 `ofstream` 클래스를 제공한다. 두 클래스를 사용하기 위해서는 `<fstream>`을 포함해야 한다.

## 파일 모드 
파일 모드는 ios클래스에 정의된 상수를 사용한다.

모드|설명
---|---
ios::trunc | 파일을 쓰기모드로 열때 기본값, 이미 존재하는 파일이면 지우고 새 파일을 생성
ios::app | 파일을 쓰기모드로 열때 파일의 끝에 추가
ios::ate | 파일 포인터를 파일 제일 마지막으로 이동
ios::binary | 이진 파일 모드로 사용
ios::in | 입력모드로 사용
ios::out | 출력모드로 사용

## 파일 쓰기

```c
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  cout << "test.txt에 저장됩니다 (종료 :ctrl+z)" << endl;
  ofstream fout;
  fout.open("test.txt"); // open으로 파일을 연다
  char ch;
  while (cin.get(ch)) {
    fout << ch;
  }

  fout.close(); // 파일 스트림을 다 쓰면 닫아야 한다.
  return 0;
}
```

## 파일 읽기

```c
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("test1.txt"); // 생성자로 파일을 연다
 
  if (!fin.is_open()) {
    cout << "파일 열기에 실패 하였습니다." << endl;
    exit(1);
  }
 
  char ch;
  while (fin.get(ch)) {
    cout << ch;
  }
  fin.close();
  return 0;
}
```

## 이진파일의 입출력

```c
#include <iostream>
#include <fstream>
using namespace std;

class Point {
  int x;
  int y;
public :
  Point(int x=0, int y=0): x(x), y(y) {}
  void showInfo() {
    cout << "[" << x << "," << y << "]" << endl;
  }
};

int main() {
  Point pos1(10, 30);
  Point pos2(40, 80);

  ofstream fout("point.bin", ios::binary);
  // pos1의 주소를 char*로 형변환 후 Point의 바이트 크기만큼 쓴다
  fout.write((char*)&pos1, sizeof(Point)); 
  fout.write((char*)&pos2, sizeof(Point));
  fout.close();

  Point pos3, pos4;
  ifstream fin("point.bin", ios::binary);
  fin.read((char*)&pos3, sizeof(Point));
  fin.read((char*)&pos4, sizeof(Point));
  fin.close();

  pos3.showInfo();
  pos4.showInfo();
  return 0;
}
```