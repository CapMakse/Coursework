#ifndef PLAYER_H
#define PLAYER_H


class Player {
public:
    Player();
    int get_score();
    bool add(int, int, int);
    void clear();
protected:
    bool check(int, int);
    int get_line_score(int*);
    int **board;
};

class AI : public Player {
public:
    AI() : Player() {}
    int choose_and_add(int);
    int choose(int,int,int);
};

int *set_deck_of_card();

#endif // PLAYER_H
