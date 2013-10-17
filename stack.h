#include <cstddef>

template <class T>
struct Stack {
   T*  data;	// array of values
   int size;	// size of array
   int top;	// index of value currently at top of Stack
};

template <class T>
void initialize(Stack<T>&s)
{
	s.size = 2;
	s.data = new T [s.size];
	s.top = 0;
}

template <class T>
void destroy(Stack<T>&s)
{
	s.top = 0;
	delete []s.data;
	s.data = NULL;
}

template <class T>
bool isEmpty(Stack<T> s)
{
	return (s.top == 0);
}

template <class T>
void push(Stack<T>&s,T x)
{
	if (s.top == s.size)
	{
		s.size *= 2;
		T* tmp = new T[s.size];
		for (int i = 0; i < s.size/2; i++)
			tmp[i] = s.data[i];
		delete []s.data;
		s.data = tmp;
		tmp = NULL;
	}
	s.data[s.top] = x;
	s.top ++;
}

template <class T>
T    pop(Stack<T>&s)
{
	s.top --;
	return s.data[s.top];
}
