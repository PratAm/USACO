/*
ID: amarpra1
PROG: transform
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<cassert>

# define DEBUG if(1)
using namespace std;
	
typedef std::vector<std::vector<char> > matrix ;

bool rotate_ninty(matrix &original,matrix &transform)
{
	int size = original.size();
	for(int i = 0;i< size;i++)
	{
			for(int j=0;j<size;j++)
			{
					if(original[i][j] != transform[j][size-1-i])
							return false;
			}
	}
	return true;
}

bool rotate_one_eighty(matrix &original,matrix &transform)
{
	int size = original.size();
	for(int i = 0;i< size;i++)
	{
			for(int j=0;j<size;j++)
			{
					if(original[i][j] != transform[size-1-i][size-1-j])
							return false;
			}
	}
	return true;
}

bool rotate_two_seventy(matrix &original,matrix &transform)
{
	int size = original.size();
	for(int i = 0;i< size;i++)
	{
			for(int j=0;j<size;j++)
			{
					if(original[i][j] != transform[size-1-j][i])
							return false;
			}
	}
	return true;
}

bool rotate_reflex(matrix &original,matrix &transform)
{
	int size = original.size();
	for(int i = 0;i< size;i++)
	{
			for(int j=0;j<size;j++)
			{
					if(original[i][j] != transform[i][size-1-j])
							return false;
			}
	}
	return true;
}

bool combination(matrix &original,matrix &transform)
{
	int size = original.size();
	matrix temp = original;

	for(int i = 0;i< size;i++)
	{
			for(int j=0;j<size/2;j++)
			{
					char tempchar;
					tempchar = temp[i][j];
					temp[i][j] = temp[i][size-1-j];
					temp[i][size-1-j] = tempchar;
			}
	}

	if(rotate_ninty(temp,transform) || rotate_one_eighty(temp,transform) || rotate_two_seventy(temp,transform))
	{
			return true;
	}
	return false;
}

int check_transform(matrix &original,matrix &transform)
{
	if(rotate_ninty(original,transform))
			return 1;
	if(rotate_one_eighty(original,transform))
			return 2;
	if(rotate_two_seventy(original,transform))
			return 3;
	if(rotate_reflex(original,transform))
			return 4;
	if(combination(original,transform))
			return 5;
	if (std::equal(original.begin(),original.end(), transform.begin()))
			return 6;
	return 7;
}
int main(int argc,char **argv)
{
	ofstream fout("transform.out");
	ifstream fin("transform.in");

	int N=0;

	matrix original,transform;

	fin >> N;

	DEBUG cout << N << endl;

	for(int i =0;i<N;i++)
	{
			char input ='\0';
			original.push_back(std::vector<char>());
			for(int j=0;j<N;j++)
			{
					fin >> input;
					original[i].push_back(input);
			}
	}

	for(int i =0;i<N;i++)
	{
			char input ='\0';
			transform.push_back( std::vector<char>());
			for(int j=0;j<N;j++)
			{
					fin >> input;
					transform[i].push_back(input);
			}
	}


	int result = check_transform(original,transform);
	DEBUG cout<< result<<endl;

	fout<< result<<endl;
	fout.close();
	fin.close();

	return 0;

}
	
