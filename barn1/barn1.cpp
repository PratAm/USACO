/*
ID: amarpra1
PROG: barn1
LANG: C++
*/

# define DEBUG if(1)

#include<iostream>
#include<fstream>
#include<queue>
#include<cassert>
#include <algorithm>
#include <climits>
#include<stdint.h>

using namespace std;

typedef struct block{
		int start;
		int end;
		int size;
		block():start(0),end(0),size(0){}
}block;


bool *stall;
std::vector<block> blocklist;



block findlargestspace(int &index)
{
		block space;
		for(unsigned int i=0;i<blocklist.size();i++)
		{
				block temp = blocklist[i]; 
				int j = temp.start;
				while (j<temp.end)
				{
           {
				    block tempspace;
						while(stall[j] and j < temp.end) j++;
						if(j< temp.end) tempspace.start = j;
						while(not stall[j] and j< temp.end) j++;
						tempspace.end = j-1;
            
            if(tempspace.start and tempspace.end){
						  tempspace.size = tempspace.end - tempspace.start +1;
            }
						if(tempspace.size > space.size)
						{
								space = tempspace;
								index = i;
						}
           }
				}
		}
		DEBUG cout << "free found size : "<< space.size <<endl;
		return space;
}


int main(int argc,char **argv)
{
		ifstream fin("barn1.in");
		ofstream fout("barn1.out");
   

		int M=0,S=0,C=0;
		fin >> M >>S>>C;
    stall = new bool[S+1]();

		int no;
		for(int i =1;i<=C;++i)
		{
				fin >> no;
				stall[no]=true;
		}
    
		block first;
		int i =1;
		while(not stall[i]){
      i++;
    }
		first.start = i;
		
    i = S;
		while(not stall[i]){ 
     i--;
    }
		first.end =i;
    first.size = first.end - first.start +1;

		blocklist.push_back(first);

		while(blocklist.size()<M)
		{
			 int index = -1;
			 block free =	findlargestspace(index);

			 if(free.size)
			 {
					 block tobreak = blocklist[index];
					 blocklist.erase(blocklist.begin()+index);

					 block fpart;
					 fpart.start = tobreak.start;
					 fpart.end = free.start -1;
					 fpart.size = fpart.end - fpart.start +1;
					 blocklist.push_back(fpart);

					 block spart;
					 spart.start = free.end+1;
					 spart.end = tobreak.end;
					 spart.size = spart.end - spart.start +1;
					 blocklist.push_back(spart);
			 }else
			 {
					 break;
			 }
		}

		 int total =0;
     for(unsigned int i =0;i<blocklist.size();++i)
		 {
				 total+=blocklist[i].size;
		 }
		 DEBUG cout << "RESULT : "<< total <<endl;
		 fout << total <<endl;
     fout.close();
     fin.close();
		
		 return 0;

}
