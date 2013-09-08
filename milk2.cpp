/*
ID: amarpra1
PROG: milk2
LANG: C++
*/

# define DEBUG if(1)

#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>
#include <algorithm>
#include <climits>

using namespace std;
#if 0
struct farmer
{
		int start;
		int end;
		farmer():start(0),end(0){}
};

inline bool operator<(const farmer& a, const farmer& b)
{
	return a.start < b.start;
}

typedef struct farmer farmer;
#endif

int main(int argc,char **argv)
{
		ifstream fin("milk2.in");
		ofstream fout("milk2.out");
    
		int nofarmers = 0;
		int maxidle=0;
    int maxactive =0;
		bool timeslot[1000001]={false};

		fin >> nofarmers;
    int start =0,end =0;
		int min =INT_MAX,max =0;

		for(int i =0;i<nofarmers;i++)
		{
				fin >> start >> end;
				if(start < min) min = start;
				if(end > max) max = end;

				for(int i =start;i<end;i++)
				{
						timeslot[i] = true;
				}
		}
    int i = min;
		while(i<max)
		{
				int tempactive =0,tempidle=0;
				while(timeslot[i] and i<max)
				{
						tempactive++;
						i++;
				}
				if(tempactive > maxactive) maxactive = tempactive;
        while(not timeslot[i]and i<max)
				{
						tempidle++;
						i++;
				}
				if(tempidle > maxidle) maxidle = tempidle;
		}

    
		DEBUG cout << maxactive << endl;
		DEBUG cout << maxidle << endl;

		fout << maxactive << " "<<maxidle <<endl;
		fin.close();
		fout.close();


   return 0;
}


