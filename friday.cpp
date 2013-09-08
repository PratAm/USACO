/*
ID: amarpra1
PROG: friday
LANG: C++
*/

# define DEBUG if(1)

#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>

using namespace std;

int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int weekday[7]={0};


void display()
{
		for(int i=0;i<7;i++)
		{
				cout << weekday[i] <<" ";
		}
}

int main()
{
		ifstream fin("friday.in");
		ofstream fout("friday.out");
    int N = 0;
    int startyear = 1900;
		int firstday = 0;
    int starting = 2; // monday


		fin >> N;
		DEBUG cout << N <<endl;

    int endyear = startyear+N-1;

    for(int year = startyear;year <=  endyear;++year)
		{
				if ( ((year%4==0) and (year%100!=0)) or (year%400==0) )
				{
						month[2]=29;
				}else
				{
						month[2]=28;
				}

				for(int i =1;i<=12;i++)
				{
						int temp = 0;
						if(starting == 0)
						{
								temp = 6;
						}else
						{
							temp = starting -1;
						}
						weekday[temp] +=1;
						firstday = month[i]%7;
						starting = (starting+firstday)%7;
				}
				display();
				cout <<endl;
		}
		for(int i=1;i<7;i++)
		{
				fout << weekday[i] <<" ";
		}
		fout << weekday[0];
		fout <<endl;
		fout.close();
		fin.close();
		return 0;
}





