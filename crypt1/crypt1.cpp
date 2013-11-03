/*
ID: amarpra1
PROG: crypt1
LANG: C++
*/

#include<cstring>
#include<iostream>
#include<fstream>
#include<set>
#include<cstdlib>
#include<sstream>

# define DEBUG if(1)

using namespace std;

set< int > digits;

string toString(int num)
{	
 stringstream ss;
 ss << num;
 string str = ss.str();
 return str;
}

bool valid(int num,int size=3)
{
  string snum = toString(num);
	if( size != snum.length())
		return false;

	for(int i=0;i<snum.length();i++)
	{
		if( digits.end() == digits.find(snum[i] -'0') )
		{
      return false;
		}
	}
	return true;
}

int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int num =0;
	int no = 0;
	int count = 0;

	fin >> num;
	for(int i=0;i<num;i++)
	{
		fin >> no;
		digits.insert(no);
	}

	int pp1=0,pp2=0,sum=0;
	for(int m1=111;m1<1000;++m1)
	{
    if(!valid(m1))
      continue;
		for(int m2=11;m2<100;++m2)
		{
       if(!valid(m2,2))
          continue;
       pp1 = m1 * (m2%10);
		   pp2 = m1 * (m2/10);
			 sum = pp1 + (pp2*10);
			 if(valid(pp1) and valid(pp2) and valid(sum,4))
				  count++;
		}
	}
	fout<<count<<endl;
	fin.close();
	fout.close();
	return 0;
}

      
