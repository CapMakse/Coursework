#include <iostream>
#include <ctime>


using namespace std;

class Line {
public:
        Line();
        void add(int);
        int get_score();
private:
        int line[5];
};

Line::Line() {
        for (int i = 0; i < 5; i++) {
                line[i] = 0;
        }
}

void Line::add(int value) {
        for (int i = 0; value != 0; i++) {
                if (line[i] < value) swap(line[i], value);
        }
}

int Line::get_score() {

}

class Board {
public:
        Board();
        int get_score();
        bool add(int, int, int);
private:
        Line horizontal[5];
        Line vertical[5];
        Line diagonal;
        int board[5][5];
};

Board::Board() {
        for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                        board[i][j] = 0;
                }
        }
}

int Board::get_score() {
        int score = 0;
        score += diagonal.get_score();
        if (score) score += 10;
        for (int i = 0; i < 5; i++) {
                score += horizontal[i].get_score();
                score += vertical[i].get_score();
        }
        return score;
}

bool Board::add(int value, int x, int y) {
        if (board[x][y]) return false;
        else {
                vertical[x].add(value);
                horizontal[y].add(value);
                if (x = y) diagonal.add(value);
                return true;
        }
}

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
                swap(Arr[i], Arr[rand() % 52]);
        }
        for (int i = 0; i < 25; i++) {
                Deck[i] = Arr[i];
        }
        return Deck;
}
