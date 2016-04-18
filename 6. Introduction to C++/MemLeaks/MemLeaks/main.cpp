#include "MemLeaks.h"
#include "My_String.h"

int main()
{

	ReportMemoryLeaks();

	Vector<My_String*> commands(true);

	

	commands.push_back(new My_String);

	printf("Write the command: ");
	commands[0]->write();

	commands[0]->tokens(" ", commands);
	
	
	
	unsigned int size = NULL;
	size = commands.size();
	for (unsigned int i = 0; i < size; i++)
		delete commands[i];

	return 0;
}