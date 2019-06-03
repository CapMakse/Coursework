#include "player.h"
#include "QTime"

Player::Player() {
    board = new int*[5];
    for (int i = 0; i < 5; i++) {
    board[i] = new int[5];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = 0;
        }
    }
}

bool Player::add(int value, int x, int y) {
    if (board[x][y]) return false;
    else {
        board[x][y] = value;
        return true;
    }
}

int Player::get_score() {
    int score = 0;
    score += get_line_score(new int[5] { board[0][0], board[1][1], board[2][2], board[3][3], board[4][4] });
    if (score) score += 10;
    for (int i = 0; i < 5; i++) {
        score += get_line_score(new int[5] { board[i][0], board[i][1], board[i][2], board[i][3], board[i][4] });
        score += get_line_score(new int[5] { board[0][i], board[1][i], board[2][i], board[3][i], board[4][i] });
    }
    return score;
}

int Player::get_line_score(int *line) {
    int sum = line[0] + line[1] + line[2] + line[3] + line[4];
    int multiply = line[0] * line[1] * line[2] * line[3] * line[4];
    if (sum == 47 && multiply == 17160) return 150; // 13 + 12 + 11 + 10 + 1 = 47, 13 * 12 * 11 * 10 * 1 = 17160
    if (check(sum,multiply)) return 50;
    int couple=0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (line[i] == line[j]) couple++;
        }
    }
    if (couple == 1) return 10;
    if (couple == 2) return 20;
    if (couple == 3) return 40;
    if (couple == 4) return (multiply == 169 ) ? 100 : 80; // 169 можно получить только 13 * 13 * 1 * 1 * 1 т.к. 13 простое число
    if (couple == 6) return (multiply == sum - 4)? 200 : 160; // Т.к. Х * 1 * 1 * 1 * 1 = Х + 1 + 1 + 1 + 1 - 4
    return 0;
}

bool Player::check(int sum, int multiply) {
    if (sum == 15 && multiply == 120) return true;
    if (sum == 20 && multiply == 720) return true;
    if (sum == 25 && multiply == 2520) return true;
    if (sum == 30 && multiply == 6720) return true;
    if (sum == 35 && multiply == 15120) return true;
    if (sum == 40 && multiply == 30240) return true;
    if (sum == 45 && multiply == 55440) return true;
    if (sum == 50 && multiply == 95040) return true;
    if (sum == 55 && multiply == 154440) return true;
    return false;
}

void Player::clear(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = 0;
        }
    }
}

int AI::choose(int value, int x, int y){
    if (board[x][y] != 0) return -1;
    int priority_x = 0, priority_y = 0;
    for (int i = 0; i < 5; i++) {
        if (board[x][i] == value) priority_x+=10;
        if (board[i][y] == value) priority_y+=10;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j){
                if (board[x][i] == value && board[x][j] == value) priority_x+=20;
                if (board[i][y] == value && board[i][y] == value) priority_y+=20;
            }
        }
    }
    return priority_x + priority_y + 1;
}

int AI::choose_and_add(int value){
    int x = 0, y = 0, priority = 0, buff;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            buff = choose(value,i,j);
            if (buff > priority){
                priority = buff;
                x = i;
                y = j;
            }
        }
    }
    board[x][y] = value;
    return x + 5 * y;
}

int *set_deck_of_card() {
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    int Arr[52];
    int *Deck = new int[25];
    for (int i = 0; i < 13; i++) {
        Arr[4 * i] = Arr[4 * i + 1] = Arr[4 * i + 2] = Arr[4 * i + 3] = i + 1;
    }
    for (int i = 0; i < 52; i++) {
        std::swap(Arr[i], Arr[qrand() % 52]);
    }
    for (int i = 0; i < 25; i++) {
        Deck[i] = Arr[i];
    }
    return Deck;
}
