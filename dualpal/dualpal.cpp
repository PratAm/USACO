/*
ID: amarpra1
PROG: dualpal
LANG: C++
*/

# define DEBUG if(1)

#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>
#include<climits>
#include<algorithm>

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



bool checkPalindrom(int value, int base)
{

  string reverse(convertNo(value,base));
	string orig(reverse);
  std::reverse(orig.begin(),orig.end());
	
	if(reverse == orig)
	{
			return true;
	}
	return false;
	 
}

int main()
{
		ifstream fin("dualpal.in");
		ofstream fout("dualpal.out");
		
		int N=0,S=0;

		fin >> N >> S;

		int loop =0;
		for (int i= S+1;loop < N;++i)
		{
				int count =0;
				for(int base = 2;base <=10;++base)
				{
						if(checkPalindrom(i,base))
								count++;
						if(2 == count)
						{
								loop++;
								fout << i << endl;
								cout << i << endl;
								break;
						}
				}
		}

		fout.close();
		fin.close();

		return 0;
}

