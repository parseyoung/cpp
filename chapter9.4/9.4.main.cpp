// �񱳿����� �����ε��ϱ�
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) { m_cents = cents; }
	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }

	friend bool operator < (const Cents& c1, const Cents& c2)
	{ // std::sort ��� �� " < " ������ ��� �ؾ� ��.

		return c1.m_cents > c2.m_cents; // > �������� < ��������
	} 

	/*friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}*/

	/*friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}*/

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}
};

int main()
{
	/*Cents cents1(6);
	Cents cents2(0);
	Cents cents3(5);
	Cents cents4(5);

	if (cents3 == cents4)
		cout << "Equal" << endl;

	if (cents1 != cents2)
		cout << "not Equal" << endl;*/

	vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; ++i)
		arr[i].getCents() = i;

	std::random_shuffle(begin(arr), end(arr));
	
	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	std::sort(begin(arr), end(arr));

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	return 0;
}