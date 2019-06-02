#ifndef PLAYER_H
#define PLAYER_H


class Player {
public:
    Player();
    int get_score();
    bool add(int, int, int);
private:
    bool check(int, int);
    int get_line_score(int*);
    int board[5][5];
};

class AI : public Player {
public:
    AI() : Player() {}
    void choose_and_add(int);
};

int *set_deck_of_card();

#endif // PLAYER_H
