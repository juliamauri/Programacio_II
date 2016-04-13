#include "My_String.h"

My_String::My_String(const char* str){
			
	int len = strlen(str);

	buffer = new char[len + 1];

	strcpy_s(buffer, len+1, str);
}

My_String::My_String(const My_String& str){

	int len = strlen(str.buffer);
	
	buffer = new char[len + 1];

	strcpy_s(buffer, len+1, str.buffer);
}

My_String::~My_String(){

	delete[] buffer;

}

void My_String::write(){

	char temp[20];
	fgets(temp, 20, stdin);
	fflush(stdin);

	unsigned int num_temp = strlen(temp);

	if ((num_temp>0) && (temp[num_temp - 1] == '\n'))
		temp[num_temp - 1] = '\0';

	write(temp);

}

void My_String::write(const char* str){

	int len = strlen(str);

	buffer = new char[len + 1];

	strcpy_s(buffer, len + 1, str);
}

unsigned int My_String::lenght()const{
	return strlen(buffer);
}

const char* My_String::c_str() const{
	return buffer;
}

bool My_String::empty() const{
	return (lenght() == 0) ? 1 : 0;

}

bool My_String::operator==(const My_String str) const{
	return (strcmp(buffer, str.buffer) == 0) ? 1 : 0;
	
}

My_String My_String::operator -= (const My_String str) const{

	char* rest;

	strtok_s(buffer,str.buffer,&rest);

	My_String ret(rest);

	return ret;
}