#pragma once

template<typename T>
class myShared_ptr
{
private:
	T* _ptr = nullptr;
	int* count;
public:

	myShared_ptr()
	{
		count = new int(0);
	}

	myShared_ptr(T* ptr)
	{
		if (ptr)
		{
			_ptr = ptr;
			count = new int(1);
		}
	}

	myShared_ptr(myShared_ptr& other)
	{
		this->_ptr = other._ptr;
		this->count = other.count;
		(*count)++;
	}

	myShared_ptr(myShared_ptr&& other)
	{
		this->_ptr = other._ptr;
		this->count = other.count;
		other.count = nullptr;
		other._ptr = nullptr;
	}

	T getData()
	{
		return *_ptr;
	}

	int GetCount()
	{
		return *count;
	}

	T operator*(myShared_ptr& other)
	{
		return *other._ptr;
	}

	operator bool()
	{
		if (*count)return 1;
		return 0;
	}

	template<typename T>
	friend ostream& operator<<(ostream& cout, myShared_ptr<T>& other);

	void reset()
	{
		if ((*count) > 1)
		{
			this->_ptr = nullptr;
			*count -= 1;
		}
		else if ((*count) == 1)
			relase();
	}

	void relase()
	{
		if (_ptr != nullptr)
			delete _ptr;
		_ptr = nullptr;
		*count = 0;
	}

	~myShared_ptr()
	{
		reset();
	}

};

template<typename T>
ostream& operator<<(ostream& cout, myShared_ptr<T>& other)
{
	T data = other.getData();
	if (data)
		cout << data << endl;
	else
		cout << "NULL" << endl;
	return cout;
}
