#ifndef CHARSTACK_H_INCLUDED	// CHARSTACK_H_INCLUDED �� ���ǵ��� �ʾ����� #endif ���� ������.
#define CHARSTACK_H_INCLUDED	// �ߺ��Ͽ� ������ ���� �ʰ� �ϱ� ���� CHARSTACK_H_INCLUDED�� ����

class CharStack {			// CharStack Ŭ���� ����
  enum { size = 20 };	// ������ ũ�⸦ ���� �� ��� size�� ���� �� �ʱ�ȭ
  int top;					  // ������ ������ ��ġ�� ����Ű�� ���� top ����
  char buf[size];			// ������ �����͸� ������ �迭
public:
  CharStack()					// �����ڷμ� Ŭ������� ���� ��ȯ���� ����.
  {
    top = size;				// top�� size������ �ʱ�ȭ
  }
  bool chkEmpty() const	// ������ �����Ͱ� ����ִ��� �˻��ϴ� �Լ��� ���ο��� ����� �� ������ ������� ����
  {
    return top == size;	// top�� size�� ���� ������ �����Ͱ� �������� true�� ��ȯ
  }
  bool chkFull() const  // ���ÿ� �����Ͱ� ���� ���ִ� �˻��ϴ� �Լ��� ���ο��� ����� �� ������ ������� ����
  {
    return !top;			  // ���ÿ� �����Ͱ� ������� top�� 0 �̱� ������ ! �������� true�� ��ȯ
  }
  bool push(char ch);	  // ���ÿ� ������ ������ ���� �Լ� push ���� ����
  char pop();					  // ���ÿ��� �����͸� ������ �Լ� pop�� ���� ����
};
#endif