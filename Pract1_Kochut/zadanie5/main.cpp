#include <iostream>
#include <string>
using namespace std;
string secretik(string stroka, int kluch);
string nesecretik(string stroka, int kluch);
int main()
{
	string stroka, rejim;
	int kluch, simvoly;
	cout << "В каком режиме работаем (cod, decod)?\n";
	cin >> rejim;
	if (rejim == "cod" || rejim == "decod");
	else {
		cout << "ERROR\n";
		return 0;
	}
	cout << "Введите строку: ";
	cin >> stroka;
	simvoly = stroka.size();
	for (int i = 0; i < simvoly; i++) {
		if (stroka[i] < 'A' || stroka[i] > 'Z') {
			cout << "ERROR\n";
			return 0;
		}
	}
	cout << "Введите ключ Скиталла: ";
	cin >> kluch;
	if ((kluch > (simvoly / 2)) || (kluch <= 0)) {
		cout << "ERROR\n";
		return 0;
	}
	if (rejim == "cod")
		secretik(stroka,kluch);
	else nesecretik(stroka,kluch);
}

string secretik(string stroka, int kluch)
{
	int simvoly, strok, nomer;
	string secret;
	simvoly = stroka.size();
	strok = simvoly / kluch;
	for (int i = 0; i < simvoly; i++) {
		nomer = kluch * (i % strok) + (i / strok);
		secret[nomer] = stroka[i];
	}
	for (int i = 0; i < simvoly; i++)
		cout << secret[i];
	cout << endl;
	return secret;
}

string nesecretik(string stroka, int kluch)
{
	int simvoly, nomer;
	string nesecret;
	simvoly = stroka.size();
	for (int i = 0; i < simvoly; i++) {
		nomer = kluch * (i % kluch) + (i / kluch);
		nesecret[nomer] = stroka[i];
	}
	for (int i = 0; i < simvoly; i++)
		cout << nesecret[i];
	cout << endl;
	return nesecret;
}
