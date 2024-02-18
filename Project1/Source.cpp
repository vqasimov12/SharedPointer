#include<iostream>
using namespace std;
#include"classes.h"

void main()
{
	myShared_ptr<int>ptr1(new int(5));
	myShared_ptr<int>ptr2(ptr1);
	myShared_ptr<int>ptr3(ptr2);
	myShared_ptr<int>ptr4(ptr2);
	cout << ptr4.GetCount() << endl;
	ptr4.reset();
	ptr2.reset();
	ptr1.reset();
	cout << ptr3.GetCount() << endl;
	myShared_ptr<int>ptr5(new int(7));
	myShared_ptr<int>ptr6(ptr5);
	cout << ptr6.GetCount() << endl;
}