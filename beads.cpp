/*
ID: amarpra1
PROG: beads
LANG: C++
*/

# define DEBUG if(1)

#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>

using namespace std;

int main()
{
		ifstream fin("beads.in");
		ofstream fout ("beads.out");
    int nobeads =0;
		std::string nacklace;
		int maxbeads =0;
		int preventloop = 0;

		fin >> nobeads;
		fin >> nacklace;
    
		int i =0;
		while( i < nobeads)
		{
				cout << i <<endl;
				int temp =i;
				int rightindex = temp;
				int leftindex = temp? --temp:nobeads-1;
				int nextindex = rightindex+1;

				if (rightindex == nobeads-1)
				{
						nextindex = 0;
				}
				preventloop = rightindex;
        int x =1,y =1;
				char right = nacklace[rightindex];
				while((right == nacklace[nextindex] or (nacklace[rightindex]=='w'and nacklace[nextindex]==right))or nacklace[nextindex] =='w')
				{
						y++;
						rightindex = (rightindex+1)%nobeads;
						if(right == 'w')
						{
								right = nacklace[rightindex];
						}
						nextindex = (nextindex+1)%nobeads;
						if(preventloop == nextindex)
						{
								fout << nobeads  <<endl;
								fout.close();
								fin.close();
								return 0;
						}
				}

				
				char left = nacklace[leftindex];
				
				if (leftindex ==0)
				{
						leftindex = nobeads-1;
				}else
				{
						leftindex--;
				}
				while((nacklace[leftindex] == left or left=='w') or nacklace[leftindex] == 'w')
				{
						x++;
						if(left == 'w')
						{
								left = nacklace[leftindex];
						}
						if(leftindex ==0)
						{
								leftindex = nobeads -1;
						}else
						{
								leftindex--;
						}
				}

        
				cout <<"loop: "<<i <<":"<<x <<" "<<y<<endl;

				if (maxbeads < x+y)
				{
						if(x+y <= nobeads)
						  maxbeads = x+y;
				}
				i++;
		}

		fout << maxbeads <<endl;
		fout.close();
		fin.close();



		return 0;
}


