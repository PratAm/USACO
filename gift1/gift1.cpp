/*
ID: amarpra1
PROG: gift1
LANG: C++
*/

# define DEBUG if(1)

#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>

using namespace std;

typedef struct person
{
 std::string name;
 int amount;
 person():amount(0){}
} person;

int getPersonLoc(std::vector<person> list,std::string name)
{
		for(int i =0 ;i<list.size();++i)
		{
				if(list[i].name == name){
						return i;
				}
		}
		return -1;
}

#if 0
istream& operator>>(istream& is, std::vector<person> &km) 
{
		size_t dim = 0;
		is >> dim;
		km.set_size(dim);

		for (size_t i = 0; i < km.size(); ++i)
		{   
		  os << km[i].name.c_str() << km[i].amount << endl;				
		}   
		return is; 
}


ofstream& operator<<(ofstream& os, const std::vector<person> &km)
{

		for (size_t i = 0; i < km.size(); ++i)
		{   
		  os <<km[i].name.c_str() <<" " <<km[i].amount << endl;				
		}   

   return os;
}

#endif
		
int main(int argc,char**argv)
{
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");
  int NP = 0;
  std::vector<person> personList;
  std::string name;
	int amount = 0;
	int no_person = 0;

  fin >> NP;
  if (NP > 0)
  {
    for(int i =0 ;i < NP;i++){

      fin >> name;
      person temp;
      temp.name = name;
      personList.push_back(temp);
    }
		
		while(fin >> name )
		{
      fin >> amount >>no_person;
			if(amount and no_person)
			{
					int toadd = amount/no_person;
					int remaining = amount - (toadd*no_person);
					int index = getPersonLoc(personList,name);
					if (index !=-1){
							personList[index].amount -= (amount-remaining);
					}
					for(int i =0;i<no_person;++i){
							std::string tempname;
							fin >> tempname;
							int index = getPersonLoc(personList,tempname);
							if (index !=-1){
									personList[index].amount += toadd;
							}
					}
			}
		}
	}
    
	assert(fout.is_open());
  cout << fout.is_open() << endl;
	//	DEBUG file << personList ;
	for (size_t i = 0; i < personList.size(); ++i)
	{   
			fout <<personList[i].name.c_str() <<" " <<personList[i].amount << endl;				
	} 
	fout.flush();
	fout.close();
	fin.close();

  return 0;
}

