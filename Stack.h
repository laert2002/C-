#pragma once
#include <iostream>
#include <assert.h>

template <typename T>
class Stack
{
	friend std::ostream& operator<<(std::ostream&, const Stack<T>&);

public:
	Stack();
	Stack(const size_t&);
	Stack(const Stack<T>&);
	~Stack();
	T& top() const;
	void push(const T&);
	void pop();
	bool isEmpty() const;
	size_t Size() const;


private:
	T* arr;
	int top_index;
	size_t size;
};

template <typename T>
Stack<T>::Stack()
{
	arr = new T[10];
	top_index = -1;
	size = 10;
}

template <typename T>
Stack<T>::Stack(const size_t& s)
{
	size = s;
	top_index = -1;
	arr = new T[size];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& st)
{
	size = st.size();
	top_index = 0;
	arr = new T[size];

	while (top_index <= st.top_index)
		arr[top_index] = st.arr[top_index++];

	--top_index;
}

template <typename T>
Stack<T>::~Stack() { delete[] arr; }

template <typename T>
T& Stack<T>::top() const
{
	assert(top_index != -1);
	return arr[top_index];
}

template <typename T>
void Stack<T>::push(const T& val)
{
	if (++top_index == size)
	{
		T* tmp = arr;
		arr = new T[size * 2];
		top_index = 0;

		assert(arr != nullptr);

		for (top_index; top_index < size; top_index++)
			arr[top_index] = tmp[top_index];

		size *= 2;
		arr[top_index] = val;

		delete[] tmp;
	}

	else
		arr[top_index] = val;

}

template <typename T>
void Stack<T>::pop()
{
	assert(top_index != -1);
	--top_index;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return top_index == -1;
}

template<typename T>
size_t Stack<T>::Size() const
{
	return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& stk)
{
	for (int i = 0; i <= stk.top_idnex; i++)
		out << stk.arr[i];

	return out;
}