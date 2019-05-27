#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
struct List {
	string Surname;
	string Name;
	string Patronymic;
	friend bool operator < (const List &l1, const List &l2) {
		if(l1.Surname != l2.Surname) {
			return l1.Surname < l2.Surname;
		} else {
			if(l1.Name != l2.Name) {
				return l1.Name < l2.Name;
			} else {
				if(l1.Patronymic != l2.Patronymic) {
					return l1.Patronymic < l2.Patronymic;
				}
			}

		}
	};
	friend ostream& operator << (ostream &conclusion, const List &list) {
		return conclusion << list.Surname << " " << list.Name << " " << list.Patronymic << endl;
	}
};
int main()
{
	ifstream Spisok ("/home/user/spisok.txt");
	string bar;
	int NumberOfFullNames = 0;
	while (getline(Spisok, bar)) {
		stringstream lineStream(bar);
		while (getline(lineStream, bar, ' '))
			NumberOfFullNames++;
	}
	Spisok.clear();
	Spisok.seekg(ios::beg);
	List listing;
	vector<List> FullNames;
	NumberOfFullNames = NumberOfFullNames / 3;
	for (int i = 0; i < NumberOfFullNames; i++) {
		Spisok >> listing.Surname;
		Spisok >> listing.Name;
		Spisok >> listing.Patronymic;
		FullNames.push_back(listing);
	}
	sort(FullNames.begin(),FullNames.end());
	cout << "Список, отсортированный по фамилиям:\n" << endl;
	for (int i = 0; i < NumberOfFullNames; i++)
		cout << FullNames[i];
	bool flag = false;
	for (int i = 0; i < NumberOfFullNames; i++)
		if (FullNames[i].Surname == FullNames[i+1].Surname) {
			if (!flag) {
				cout << "\nОднофамильцы: \n" << endl;
				flag = true;
			}
			string homonyms = FullNames[i].Surname;
			while (FullNames[i].Surname == homonyms) {
				cout << FullNames[i];
				i++;
			}
			i--;
		}
	map<string, int> NameAllocator;
	map<string, int>::iterator iter;
	for (int i = 0; i < NumberOfFullNames; i++)
		NameAllocator[FullNames[i].Name]++;
	auto max = std::max_element(NameAllocator.begin(), NameAllocator.end(), [](const pair< string, int>& p1, const pair<string, int>& p2) {
		return p1.second < p2.second;
	});
	auto min = std::min_element(NameAllocator.begin(), NameAllocator.end(), [](const pair< string, int>& p1, const pair<string, int>& p2) {
		return p1.second < p2.second;
	});
	cout << "\nПопулярные имена: \n"<<endl;
	for (iter = NameAllocator.begin(); iter != NameAllocator.end(); iter++)
		if (iter->second == max->second)
			cout << iter->first << endl;
	cout << "\nНепопулярные имена: \n" << endl;
	for (iter = NameAllocator.begin(); iter != NameAllocator.end(); iter++)
		if (iter->second == min->second)
			cout << iter->first << endl;
	cout << endl;
	Spisok.close();
	return 0;
}
