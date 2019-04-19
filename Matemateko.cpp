#include <iostream>
#include <ctime>


using namespace std;

int *set_deck_of_card();

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int *cards = new int[25]; 
	cards = set_deck_of_card();
	for (int i = 0; i < 25; i++) {
		cout << cards[i] << " ";
	}
	system("pause");
	return 0;
}

int *set_deck_of_card() {
	int Arr[52];
	int *Deck = new int[25];
	for (int i = 0; i < 13; i++) {
		Arr[4 * i] = Arr[4 * i + 1] = Arr[4 * i + 2] = Arr[4 * i + 3] = i + 1;
	}
	for (int i = 0; i < 52; i++) {
			swap(Arr[i],Arr[rand() % 52]);
	}
	for (int i = 0; i < 25; i++) {
		Deck[i] = Arr[i];
	}
	return Deck;
}