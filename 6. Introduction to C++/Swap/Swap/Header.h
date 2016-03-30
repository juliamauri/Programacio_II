class SwapCase
{
public:
	int num;
	float fnum;
	char lett;
	bool yep;
};


template<class Hi>
void swap(Hi &num1, Hi &num2)
{
	Hi temp = num2;
	num2 = num1;
	num1 = temp;
}