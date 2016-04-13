#ifndef __VECTOR__
#define __VECTOR__

template<class TYPE>
class Vector{
private:
	TYPE* buffer;
	unsigned int capacity = 10;
	unsigned int num_elements = 0;

public:
	Vector()
	{
		buffer = new TYPE[capacity];
	}

	Vector(const Vector& copy)
	{
		capacity = num_elements = copy.num_elements;
		buffer = new TYPE[capacity];
		//intentar amb memcpy
		for (unsigned int i = 0; i < num_elements; ++i)
			buffer[i] = copy.buffer[i];
	}
	
	~Vector()
	{
		delete[] buffer;
	}
	//fer metode push_back(principi) i push_front(al principi)
};

#endif