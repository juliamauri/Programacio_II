#include "MemLeaks.h"
#include "My_String.h"

int main()
{
	ReportMemoryLeaks();
	My_String * hello = new My_String("hello");
	

	delete hello;
	


	return 0;
}