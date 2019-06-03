#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int *cards;
    int i;
    Player First;
    AI Ai;
    QPushButton **ai;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void AI_buttons();
    void new_game();

private slots :
    void turn();
};

#endif // MAINWINDOW_H
