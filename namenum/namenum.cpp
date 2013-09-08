/*
ID: amarpra1
PROG: namenum
LANG: C++
*/

# define DEBUG if(1)

#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>

using namespace std;


string getNofromName(const string &in)
{
		string ret = "";
		for(int i = 0; i < in.length(); ++i){
				if(in[i] == 'Q' || in[i] == 'Z')
						return "1";
				if(in[i] < 'Q')
						ret += ((in[i] - 'A') / 3) + '2';
				else
						ret += ((in[i] - 'Q') / 3) + '7';
		}
		return ret;
}

int main()
{
		ifstream fin("namenum.in");
		ofstream fout ("namenum.out");
		ifstream din ("dict.txt");
    
		string name("");
		string num;
		
		fin >> num;

    bool found = false; 
    while(din >> name)
    {
      if(num.length()== name.length() and getNofromName(name)== num)
			{
					found = true;
					fout << name << endl;
			}
		}
 
		if(!found)
		{
				fout <<"NONE"<<endl;
		}

		fin.close();
		fout.close();
		din.close();

		return 0;
}
