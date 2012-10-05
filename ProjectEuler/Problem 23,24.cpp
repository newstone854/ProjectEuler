#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef unsigned int uint;

bool IsAbundant(unsigned int n)
{
	uint sum = 1;
	uint i;
	for(i = 2; i*i < n; ++i)
	{
		if(n%i == 0)
		{
			sum += i;
			sum += n/i;
		}
	}
	if(i*i == n)
		sum += i;
	if(sum > n)
		return true;
	return false;

}

uint Problem23(uint nMax)
{
	vector<uint> abundants;
	for(uint i = 12; i < nMax; ++i)
	{
		if(IsAbundant(i))
		{
			abundants.push_back(i);
		}
	}

/*	set<uint> setSum2;
	for(uint i = 0; i < abundants.size(); ++i)
	{
		for(uint j = 0; j < abundants.size(); ++j)
		{
			uint nSum2 =abundants[i] + abundants[j];
			if(nSum2 <= nMax)
			{
				setSum2.insert(nSum2);
			}
		}
	}

	uint nRet = 0;
	for(uint i = 1; i <= nMax; ++i)
	{
		if(setSum2.end() == setSum2.find(i))
		{
			nRet += i;
		}
	}
	return nRet;*/
	bool sum_of_abundants[28123*2+1]={false};
  
  for(int i=0;i<abundants.size();++i)
    for(int j=0;j<=i;++j)
      sum_of_abundants[abundants[i]+abundants[j]]=true;
  
  int sum=0;
  
  for(int i=1;i<30000;++i)
    if(!sum_of_abundants[i])
      sum+=i;

  return sum;
}

uint Factorial(uint N)
{
	uint ret = 1;
	for(uint i = 1; i <= N; ++i)
	{
		ret *= i;
	}
	return ret;
}
uint Power(uint nBase, uint nCount)
{
	uint nRet = 1;
	for(uint i = 0; i < nCount; ++i)
	{
		nRet *= nBase;
	}
	return nRet;
}
uint Problem24(uint Nth, uint numCount)
{
	if(Factorial(numCount) < Nth)
		return 0;
	uint nRet = 0;
	uint nPoint = numCount - 1;
	uint nFact = 1;
	while((nFact = Factorial(nPoint)) > Nth)
	{
		nPoint--;
	}
	vector<uint> vNums;
	for(uint i = 0; i < numCount; ++i)
	{
		vNums.push_back(i);
	}
	Nth -= 1;
	while(Nth > 0 && nPoint > 0)
	{
		uint n = Nth/nFact;
		Nth = Nth%nFact;
		nRet += vNums[n]*Power(10, nPoint);
		vNums.erase(vNums.begin()+n);
		nFact /= (nPoint--);
	}
	return nRet;
}
int main()
{
	//uint n = Problem23(28123);
	uint n = Problem24(1000000,10);
	std::cout<<n<<std::endl;
	return 0;
}