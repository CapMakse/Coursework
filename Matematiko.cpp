#include <iostream>
#include <ctime>


using namespace std;

/*class Line {
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
        if (line[0] == line[1] + 1 && line[1] == line[2] + 1 && line[2] == line[3] + 1) {
                if (line[3] == line[4] + 1) return 50;
                if (line[0] == 13 && line[4] == 1) return 150;
        }
        int couple=0;
        for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 5; j++) {
                        if (line[i] == line[j]) couple++;
                        else break;
                }
        }
        if (couple == 1) return 10;
        if (couple == 2) return 20;
        if (couple == 3) return 40;
        if (couple == 4) return (line[0] == 13 && line[2] == 1) ? 100 : 80;
        if (couple == 6) return (line[4] == 1)? 200 : 160;
        return 0;
}*/

class Board {
public:
        Board();
        int get_score();
        bool add(int, int, int);
private:
        int get_line_score(int*);
        int* line_sort(int*);
        int board[5][5];
};

Board::Board() {
        for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                        board[i][j] = 0;
                }
        }
}

bool Board::add(int value, int x, int y) {
        if (board[x][y]) return true;
        else {
                board[x][y] = value;
                return false;
        }
}

int* Board::line_sort(int* line) {
        int j;
        for (int i = 1; i < 5; i++) {
                int value = line[i];
                for (j = i - 1; j >= 0 && line[j] < value; j--)
                        line[j + 1] = line[j];
                line[j + 1] = value;
        }
        return line;
}

int Board::get_score() {
        int score = 0;
        score += get_line_score(line_sort(new int[5] { board[0][0], board[1][1], board[2][2], board[3][3], board[4][4] }));
        if (score) score += 10;
        for (int i = 0; i < 5; i++) {
                score += get_line_score(line_sort(new int[5] { board[i][0], board[i][1], board[i][2], board[i][3], board[i][4] }));
                score += get_line_score(line_sort(new int[5] { board[0][i], board[1][i], board[2][i], board[3][i], board[4][i] }));
        }
        return score;
}

int Board::get_line_score(int *line) {
        if (line[0] == line[1] + 1 && line[1] == line[2] + 1 && line[2] == line[3] + 1) {
                if (line[3] == line[4] + 1) return 50;
                if (line[0] == 13 && line[4] == 1) return 150;
        }
        int couple=0;
        for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 5; j++) {
                        if (line[i] == line[j]) couple++;
                        else break;
                }
        }
        if (couple == 1) return 10;
        if (couple == 2) return 20;
        if (couple == 3) return 40;
        if (couple == 4) return (line[0] == 13 && line[2] == 1) ? 100 : 80;
        if (couple == 6) return (line[4] == 1)? 200 : 160;
        return 0;
}

int *set_deck_of_card();

int main() {
        srand(time(NULL));
        setlocale(LC_ALL, "Russian");
        int *cards = new int[25];
        cards = set_deck_of_card();
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
