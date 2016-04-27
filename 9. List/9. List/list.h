
template<class TYPE>
struct node
{
public:
	TYPE data;
	node* next = nullptr;

public:
	node(const TYPE& data) : data(data){}

	~node(){}
};


template<class TYPE>
class list
{
private:
	node<TYPE>* first = nullptr;

public:
	list(){}

	//list(node& first): first(first){}

	~list(){}

	bool empty() const
	{
		return first == nullptr;
	}

	unsigned int size() const
	{
		unsigned int ret = 0;
		node<TYPE>* temp = first;
		while (temp != nullptr)
		{
			temp = temp->next;
			ret++;
		}
		return ret;
	}
	
	node<TYPE>* end()
	{
		node<TYPE>* temp = first;
		if (temp != nullptr)
		{
			while (temp != nullptr)
			{
				temp = temp->next;
			}
			return temp;
		}
		return temp;
	}

	//push_back()
	//push_front()
	
};