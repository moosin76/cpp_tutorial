#ifndef CHARSTACK_H_INCLUDED	// CHARSTACK_H_INCLUDED �� ���ǵ��� �ʾ����� #endif ���� ������.
#define CHARSTACK_H_INCLUDED	// �ߺ��Ͽ� ������ ���� �ʰ� �ϱ� ���� CHARSTACK_H_INCLUDED�� ����

class CharStackEx4 {			// CharStack Ŭ���� ����
  const int size;	// ������ ũ�⸦ ���� �� ��� size�� ����
  int top;					  // ������ ������ ��ġ�� ����Ű�� ���� top ����
  char* buf;			// ������ ��������� �����Ҵ��ϱ� ���� ������ ���� ����
public:
  // �����ڷμ� Ŭ������� ���� ��ȯ���� ����.
  CharStackEx4(int s=20) : size(s), top(s)	// �ʱ�ȭ��Ͽ��� size�� top�� ���޹��� ������ �ʱ�ȭ ���޹޴� ���� ���ٸ� �⺻�� 20���� �ʱ�ȭ
  {
    buf = new char[size]; // size�� ũ��� �����Ҵ�
  }
  ~CharStackEx4() // �Ҹ��� Ŭ������� ���� ��ȯ���� ������ �Լ��տ� ~�� ���� �Ű������� �ü� ����
  {
    delete[] buf; // �����Ҵ�� ������ ��������� ������Ŵ
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