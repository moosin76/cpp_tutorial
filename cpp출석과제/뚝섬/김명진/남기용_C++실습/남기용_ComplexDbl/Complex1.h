#ifndef COMPLEX1_H_INCLUDED     // COMPLEX1_H_INCLUDED �� ���ǵ��� �ʾ����� #endif ���� ������.
#define COMPLEX1_H_INCLUDED		// �ߺ��Ͽ� ������ ���� �ʰ� �ϱ� ���� COMPLEX1_H_INCLUDED�� ����

// Ŭ���� Complex1 ����
class Complex1					
{
	// �Ǽ��� �� ����� 
	double rPart, iPart;		
public:	// �Ʒ��� ����� ���ü� ���þ� public���� ����
	// ������ �Ǽ��θ� r ����θ� i�� �ʱ�ȭ
	Complex1(double r = 0, double i = 0) :rPart(r), iPart(i) {} 
	// ������� ��ȣ�� �ٲٴ� �Լ�
	Complex1 conj() const						
	{
		// ������� ��ȣ�� �ٲ� ��ü�� ���� �����Ͽ� ��ȯ
		return Complex1(rPart, -iPart);			
	}
	// ���Ҽ��� ���ϱ� ������ �ϴ� �Լ�
	Complex1 add(const Complex1 &c) const		
	{
		// ���Ҽ��� ���ϱ� ������ ������ ������ ��ü�� �����Ͽ� ��ȯ
		return Complex1(rPart + c.rPart, iPart + c.iPart);	
	}
	// ���Ҽ��� ���� ������ �ϴ� �Լ�
	Complex1 sub(const Complex1 &c) const		
	{
		// ���Ҽ��� ���� ������ ������ ������ ��ü�� �����Ͽ� ��ȯ
		return Complex1(rPart - c.rPart, iPart - c.iPart);	
	}
	// �������� ���ϱ� ������ �ϴ� �Լ� mul�� ���� ����
	Complex1 mul(const Complex1 &c) const;
	// ���Ҽ��� ������ ������ �ϴ� �Լ� div�� ���� ����
	Complex1 div(const Complex1 &c) const;
	// ���Ҽ� ���� ����ϴ� �Լ� display�� ���� ����
	void display() const;						
};
#endif