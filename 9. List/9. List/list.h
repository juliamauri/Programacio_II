
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

template<class TYPE>
struct Node
{
public:
	TYPE data;
	Node* next = nullptr;

public:
	Node(const TYPE& data) : data(data){}

	~Node(){}
};


template<class TYPE>
class list
{
private:
	Node<TYPE>* first = nullptr;

public:
	list(Node<TYPE>* first) : first(first){}

	~list(){}

	bool empty() const
	{
		return first == nullptr;
	}

	unsigned int size() const
	{
		unsigned int ret = 0;
		Node<TYPE>* temp = first;
		while (temp != nullptr)
		{
			temp = temp->next;
			ret++;
		}
		return ret;
	}
	

	Node<TYPE>* end()const
	{
		Node<TYPE>* temp = first;
		if (empty() == false){
			while (temp->next != nullptr)
				temp = temp->next;
		}
		return temp;
	}

	void pushback(const TYPE& data){
		Node<TYPE>* it = end();
		if (it != nullptr){
			it->next = new Node<TYPE>(data);
		}
		else{
			first = new Node<TYPE>(data);
		}
	}

	void pushfront(const TYPE& data){
		Node<TYPE>* temp = first;
		first = new Node<TYPE>(data);
		first->next = temp;
	}


	bool pop_back(){
		if (first != nullptr){
			Node<TYPE>* temp = first;
			Node<TYPE>* last = temp;
			while (temp->next != nullptr){
				last = temp;
				temp = temp->next;
			}
			if (last->next != nullptr)
				last->next = nullptr;
			else
				first = nullptr;

			delete temp;
			return true;
		}
		return false;
	}

	bool pop_front(){
		if (first != nullptr){
			Node<TYPE>* temp = first;
			first = first->next;
			delete temp;
			return true;
		}
		return false;
	}
	
};

#endif // !__LINKED_LIST_H__