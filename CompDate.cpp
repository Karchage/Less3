#include <iostream>

typedef unsigned short datec_t;

typedef enum Month {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG,
	SEP, OCT, NOV, DEC, MONTHS = 12} Month;

typedef struct Date
{
	int dd;
	Month mm;
	int yy;
} Date;

datec_t compressDate(Date d);

Date uncompressDate(datec_t dc);

datec_t setDay(datec_t dc, int newDay);

datec_t setMonth(datec_t dc, Month newMonth);

datec_t setYear(datec_t dc, int newYear);

void printDate(Date d); 

void printCompressedDate(datec_t dc); 


int main()
{
	Date d={1,JAN,1};
	int newDay,newYear,mon;
	Month newMonth;
	datec_t dc = compressDate(d);
	std::cout<<"This is default Date";
	printDate(d);
	std::cout<<"\nPlease set new Day: ";
	std::cin>>newDay;
	d.dd=setDay(dc,newDay);
	std::cout<<"\nPlease set new Month: ";
	std::cin>>mon;
	newMonth=(Month)mon;
	d.mm=(Month)setMonth(dc,newMonth);
	std::cout<<"\nPlease set new Year: ";
	std::cin>>newYear;
	d.yy=setYear(dc,newYear);
	std::cout<<"\nYou have compressed this Date ?";
	printDate(d);
	std::cout<<"\n1)Yes\n2)No\n";
	int count;
	std::cin>>count;
	if(count == 1)
	{
		datec_t dc = compressDate(d);
		printCompressedDate(dc);
		std::cout<<"\nThis is uncompressed your Date: ";
		uncompressDate(dc);
	}
	else return 0;
	
}
datec_t compressDate(Date d)
{
	datec_t CompDate;
	datec_t m; 
	d.yy = d.yy<<9;
	m = d.mm;
	m=m<<5;
	CompDate = (((CompDate | d.yy)|m)|d.dd);
	return CompDate;
}
Date uncompressDate(datec_t dc)
{
	short int a;
	a=dc>>9;
	std::cout<<"\nYear: "<<a;
	a=dc<<7;
	a=a>>12;
	std::cout<<"\nMonth: "<<a;
	a=dc<<12;
	a=a>>12;
	std::cout<<"\nDay: "<<a;
}
datec_t setDay(datec_t dc, int newDay)
{
	dc=dc>>5;
	dc=dc<<5;
	dc=dc| newDay;
	return newDay;
}
datec_t setMonth(datec_t dc, Month newMonth)
{
	dc=(dc&65055)|(newMonth<<5);
	return (Month)newMonth;
}
datec_t setYear(datec_t dc, int newYear)
{
	dc=dc<<7;
	dc=dc>>7;
	dc=dc|newYear;
	return newYear;
}
void printDate(Date d)
{
	std::cout<<"\nDay: "<<d.dd;
	std::cout<<"\nMonth: "<<d.mm;
	std::cout<<"\nYear: "<<d.yy;	
} 
void printCompressedDate(datec_t dc) //datec_t dc ?
{
	std::cout<<"\nThis is compressed Date D|M|Y: "<<dc;
}
