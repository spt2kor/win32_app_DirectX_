#include <iostream>
using namespace std;

class RestricCopy
{
protected:

	RestricCopy()
	{
		cout<<"\n RestricCopy::RestricCopy()";
	}

	~RestricCopy()
	{
		cout<<"\n RestricCopy::~RestricCopy()";
	}

private:
	RestricCopy& operator= (const RestricCopy&)
	{
		cout<<"\n RestricCopy::operator=()";
		return *this;
	}
	RestricCopy(const RestricCopy&)
	{
		cout<<"\n RestricCopy::RestricCopy(RestricCopy&)";
	}
};

class Type : public RestricCopy
{
public:
	Type()
	{
		cout<<"\n Type::Type()";
	}
	~Type()
	{
		cout<<"\n Type::~Type()";
	}
	/*Type& operator= (const Type&)
	{
		cout<<"\n Type::operator=()";
		return *this;
	}
	Type(const Type&)
	{
		cout<<"\n Type::Type(Type&)";
	}*/
};

void main()
{
	cout<<"\n Program Started"<<endl;
	Type t1;
	Type t2 = t1;
	t1 = t2;

	cout<<"\n Program Ended"<<endl;
}