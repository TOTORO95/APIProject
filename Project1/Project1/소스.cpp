
#include <iostream>

using namespace std;
class A
{
public:
	A();
	~A();
	void Fun()
	{
		cout << "hello" << endl;
	}
private:

};

A::A()
{
}

A::~A()
{
}

void main()
{
	A *b =nullptr;
	b->Fun();

}
