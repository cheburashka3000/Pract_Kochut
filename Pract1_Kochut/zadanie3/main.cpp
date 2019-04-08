#include <iostream>
using namespace std;
float *Norma(float *a);
int main()
{
	cout << "Введите значения от 0 до 1!!!\n";
	float * star = new float[5];
	for (int i = 0; i < 5; i++) {
		cin >> star[i];
		if (star[i] < 0 || star[i] > 1) {
			cout << "ПРЕДУПРЕЖДАЛИ!!! ОТ 0 ДО 1!!!\n";
			return 0;
		}
	}
	float * novizna = Norma(star);
	cout << "Новый массив: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << novizna[i]<< endl;
	}
	delete[] novizna;
	delete[] star;
	return 0;
}
float *Norma(float *a)
{
	float max = 0, min = 1;
	float*q = new float[5];
	for(int i = 0; i < 5; i++) {
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	for (int i = 0; i < 5; i++) {
		q[i]= (a[i] - min)/(max - min);
	}
	return q;
}
