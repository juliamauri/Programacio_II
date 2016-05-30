#include "list.h"

int main(){



	List<int> listTest(nullptr);
	bool emptyTest = listTest.empty();
	unsigned int sizeTest = listTest.size();
	List<int>::Node* endTest = listTest.end();

	listTest.pushfront(4);
	listTest.pushback(6);

	bool testinsert = listTest.insert(listTest.first, 3);


	return 0;
}