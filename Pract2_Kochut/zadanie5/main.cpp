#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
struct Cards {
	int par;
	int suit;
	Cards(int p,int s) {
		par = p;
		suit = s;
	}
	friend ostream& operator << (ostream &conclusion,  Cards &first) {
		return conclusion << "PAR: " << first.par << " SUIT: " << first.suit;
	}
	friend bool operator == ( Cards &first,  Cards &second) {
		return (first.par == second.par && first.suit== second.suit);
	}
};
int main(int argc, char **argv)
{
	enum par {six = 0, seven = 1, eight = 2, nine = 3, ten = 4, Jack = 5, Queen = 6, King = 7, Ace = 8};
	enum suit {Hearts = 0, Diamonds = 1, Clubs = 2, Spades = 3};
	Cards card(0,0);
	vector <Cards> Deck;
	for (int s = 0; s < 4; s++)
		for(int p = 0; p < 9; p++) {
			Cards card(p,s);
			Deck.push_back(card);
		}
	shuffle(Deck.begin(),Deck.end(),mt19937(time(NULL)));
	cout << "Две подряд карты красного цвета под номерами:\n";
	for (int i = 0; i < 35; i++)
		if ((Deck[i].suit == Hearts || Deck[i].suit == Diamonds) && (Deck[i+1].suit == Hearts || Deck[i+1].suit == Diamonds))
			cout << i + 1 << " и " << i + 2 << endl;
	cout << "Две подряд карты чёрного цвета под номерами:\n";
	for (int i = 0; i < 35; i++)
		if ((Deck[i].suit == Clubs || Deck[i].suit == Spades) && (Deck[i+1].suit == Clubs || Deck[i+1].suit == Spades))
			cout << i + 1 << " и " << i + 2 << endl;
	cout << "Две подряд карты с одинаковым номиналом под номерами:\n";
	for (int i = 0; i < 35; i++)
		if (Deck[i].par == Deck[i+1].par)
			cout << "" << i + 1 << " и " << i + 2 << endl;
	for (int i = 0; i < 36; i++)
		if (Deck[i].par == Queen && Deck[i].suit == Spades)
			cout << "Дамма Пик под номером " << i + 1 << endl;
	int nomer = 1;
	for (int i = 0; i < 36; i++)
		if (Deck[i].par == Ace) {
			cout << "Туз №" << nomer << " под номером " << i + 1 << endl;
			nomer++;
		}
	for (int i = 0; i < 36; i++) {
		if (i < 9)
			cout << " ";
		cout << i + 1 << ") " << Deck[i] << endl;
	}
	return 0;
}
