#include <iostream>
using namespace std;
void Norma(float a[]);
int main()
{
	float a[5];
	cout << "Введите значения от 0 до 1!!!\n";
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		if (a[i] < 0 || a[i] > 1) return 0;
	}
	Norma(a);
	for (int i = 0; i < 5; i++)
		cout << a[i] << endl;
	return 0;
}
void Norma(float a[])
{
	float max = a[0], min = a[0];
	for(int i = 0; i < 5; i++) {
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	for (int j = 0; j <5; j++)
		a[j] = (a[j] - min)/(max - min);
}
