/*
ID: amarpra1
PROG: palsquare
LANG: C++
*/

# define DEBUG if(1)

#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<cassert>

using namespace std;

string convertNo(int value,int base)
{
	int num;
	char temp;
	string inbase;

 	while(value)
	{
    num = value % base;
	  value = value/base;

		if(num <=9){
				temp = (char)(((int)'0')+num);
		}else{
				temp = (num-10) + 'A';
		}
		inbase +=temp;
	}
	return inbase;
	
}



void isPalindrom(int value, int base,ofstream& fout)
{

  string orig(convertNo(value,base));
  std::reverse(orig.begin(),orig.end());

  string square(convertNo(value*value,base));
	string square_rev(square);
  std::reverse(square.begin(),square.end());
	
	if(square == square_rev)
	{
			cout << orig <<" " << square_rev << endl;
			fout << orig <<" " << square_rev << endl;
	}
	 
}


int main()
{
		ifstream fin("palsquare.in");
	  ofstream fout("palsquare.out");

		int base;
		
		fin >> base;

		for(int i =1 ; i< 300;i++)
		{
				isPalindrom(i,base,fout);
		}

    fin.close();
		fout.close();
		return 0;
}
