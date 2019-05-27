#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
int RandomGenerator()
{
	static mt19937 rnd((uint64_t)&rnd);
	uniform_int_distribution<int> d(-1000000000,1000000000);
	return d(rnd);
}
int main()
{
	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();
	vector<int> v1;
	for (int i = 0; i < 10000000; i++)
		v1.push_back(RandomGenerator());
	end = chrono::system_clock::now();
	int ExecutionTime = chrono::duration_cast<chrono::milliseconds> (end - start).count();
	cout << "Время создания и заполнения v1: " << ExecutionTime << " мсек.\n";
	start = chrono::system_clock::now();
	vector<int> v2(10000000);
	generate(v2.begin(),v2.end(),RandomGenerator);
	end = chrono::system_clock::now();
	ExecutionTime = chrono::duration_cast<chrono::milliseconds> (end - start).count();
	cout << "Время создания и заполнения v2: " << ExecutionTime << " мсек.\n";
	start = chrono::system_clock::now();
	vector<int> v3(v2);
	end = chrono::system_clock::now();
	ExecutionTime = chrono::duration_cast<chrono::milliseconds> (end - start).count();
	cout << "Время создания и заполнения v3: " << ExecutionTime << " мсек.\n";
}
