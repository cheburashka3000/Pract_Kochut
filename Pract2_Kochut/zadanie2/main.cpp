#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;
int RandomGenerator()
{
	static mt19937 rnd((uint64_t)&rnd);
	uniform_int_distribution<int> d(-1000000000,1000000000);
	return d(rnd);
}
int main()
{
	vector<int> v1;
	for (int i = 0; i < 10000000; i++)
		v1.push_back(RandomGenerator());
	vector<int> v2(10000000);
	generate(v2.begin(),v2.end(),RandomGenerator);
	vector<int> v3(v2);
}
