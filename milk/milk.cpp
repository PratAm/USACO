/*
ID: amarpra1
PROG: milk
LANG: C++
*/

# define DEBUG if(0)

#include<iostream>
#include<fstream>
#include<queue>
#include<cassert>
#include <algorithm>
#include <climits>

using namespace std;


class farmer{
		public:
				farmer(int p,int q){
						price =p;
						quantity = q;
				}
				int price;
				int quantity;
				int getprice() const {return price;};
				int getquantity()const {return quantity;};
        bool operator <(const farmer &other) const
				{  
           return price > other.price;
        }
};

int main(int argc,char **argv)
{
		ifstream fin("milk.in");
		ofstream fout("milk.out");

		std::priority_queue<farmer> farmerlist;

		int N=0,M=0;
		fin >> N >> M ;
		{
				int price=0,quant=0;
		    for(int i =0;i< M;i++)
		    {
						fin >> price >> quant;
						farmer temp(price,quant);
						farmerlist.push(temp);
				}
		}

		DEBUG cout << "priority Queue size: "<<farmerlist.size()<<endl;
		DEBUG cout << "priority Queue top: "<<farmerlist.top().getprice() <<endl;

    int milktobuy = N;
    int price =0;

    while(milktobuy)
    {
      farmer temp = farmerlist.top();
      farmerlist.pop();
     
      if(milktobuy > temp.getquantity())
      {
        milktobuy-=temp.getquantity();
        price += temp.getprice()*temp.getquantity();
      }else
      {
        price += temp.getprice()*milktobuy;
        milktobuy = 0;
      }
    }
    fout <<price <<endl;
    fout.close();
    fin.close();

		return 0;
}
