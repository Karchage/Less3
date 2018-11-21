#include <iostream>

unsigned int CovNum(unsigned int num,int cval)
{
	unsigned int newnum;
	
	for(int i=0;i<cval;i++)
	{
		num = num >> 1;
		newnum = num<<32-i;
		num = num | newnum;
	}
	return num;
}
int main() 
{
	unsigned int num;
	int cval;
	std::cin>>num;
	std::cin>>cval;
	//Question: Why is it don't work ?
	//CovNum(num,cval);
	//std::cout<<"\n"<<"New Number :"<< num <<"\n";
	std::cout<<"\n"<<"New Number :"<< CovNum(num,cval) <<"\n";
	return 0;
}
