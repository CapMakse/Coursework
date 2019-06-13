#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <QMessageBox>
#include <QDebug>

void MainWindow::AI_buttons(){
    ai = new QPushButton*[25];
    ai[0] = ui->pushButton_AI0;
    ai[1] = ui->pushButton_AI1;
    ai[2] = ui->pushButton_AI2;
    ai[3] = ui->pushButton_AI3;
    ai[4] = ui->pushButton_AI4;
    ai[5] = ui->pushButton_AI5;
    ai[6] = ui->pushButton_AI6;
    ai[7] = ui->pushButton_AI7;
    ai[8] = ui->pushButton_AI8;
    ai[9] = ui->pushButton_AI9;
    ai[10] = ui->pushButton_AI10;
    ai[11] = ui->pushButton_AI11;
    ai[12] = ui->pushButton_AI12;
    ai[13] = ui->pushButton_AI13;
    ai[14] = ui->pushButton_AI14;
    ai[15] = ui->pushButton_AI15;
    ai[16] = ui->pushButton_AI16;
    ai[17] = ui->pushButton_AI17;
    ai[18] = ui->pushButton_AI18;
    ai[19] = ui->pushButton_AI19;
    ai[20] = ui->pushButton_AI20;
    ai[21] = ui->pushButton_AI21;
    ai[22] = ui->pushButton_AI22;
    ai[23] = ui->pushButton_AI23;
    ai[24] = ui->pushButton_AI24;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AI_buttons();
    cards = new int[25];
    cards = set_deck_of_card();
    i = 0;
    ui->label_4->setText(QString::number(cards[i]));

    connect(ui->pushButton_p0, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p1, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p2, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p3, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p4, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p5, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p6, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p7, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p8, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p9, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p10, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p11, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p12, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p13, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p14, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p15, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p16, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p17, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p18, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p19, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p20, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p21, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p22, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p23, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p24, SIGNAL(clicked()), this, SLOT(turn()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_game(){
    First.clear();
    Ai.clear();
    for (int i = 0; i < 25; i++) {
        ai[i]->setText("");
    }
    ui->pushButton_p0->setText("");
    ui->pushButton_p1->setText("");
    ui->pushButton_p2->setText("");
    ui->pushButton_p3->setText("");
    ui->pushButton_p4->setText("");
    ui->pushButton_p5->setText("");
    ui->pushButton_p6->setText("");
    ui->pushButton_p7->setText("");
    ui->pushButton_p8->setText("");
    ui->pushButton_p9->setText("");
    ui->pushButton_p10->setText("");
    ui->pushButton_p11->setText("");
    ui->pushButton_p12->setText("");
    ui->pushButton_p13->setText("");
    ui->pushButton_p14->setText("");
    ui->pushButton_p15->setText("");
    ui->pushButton_p16->setText("");
    ui->pushButton_p17->setText("");
    ui->pushButton_p18->setText("");
    ui->pushButton_p19->setText("");
    ui->pushButton_p20->setText("");
    ui->pushButton_p21->setText("");
    ui->pushButton_p22->setText("");
    ui->pushButton_p23->setText("");
    ui->pushButton_p24->setText("");
    cards = set_deck_of_card();
    i = 0;
    ui->label_4->setText(QString::number(cards[i]));
}

void MainWindow::turn(){
    QPushButton *button = (QPushButton *)sender();
    QVariant X = button->property("pos-x");
    QVariant Y = button->property("pos-y");
    if (!First.add(cards[i],X.toInt(),Y.toInt())) return;
    button->setText(QString::number(cards[i]));
    ai[Ai.choose_and_add(cards[i])]->setText(QString::number(cards[i]));
    i++;
    if (i < 25 ) ui->label_4->setText(QString::number(cards[i]));
    else {
        ui->label_4->setText("");
        int P_score = First.get_score();
        int Ai_score = Ai.get_score();
        QString str;
        if (P_score < Ai_score) {
            str = "Вы проиграли. \nЖелаете повторить?"; }
        else if (P_score > Ai_score) {
            str = "Вы победили. \nЖелаете повторить?"; }
        else { str = "Ничья. \nЖелаете повторить?"; }
        QMessageBox::StandardButton question = QMessageBox::question(this, "", str, QMessageBox::Yes | QMessageBox::No);
        if (question == QMessageBox::Yes) new_game();
        else QApplication::quit();
    }
}

void MainWindow::on_actionNew_game_triggered()
{
    QMessageBox::StandardButton question = QMessageBox::question(this, "", "Вы уверены, что хотите начать заново?", QMessageBox::Yes | QMessageBox::No);
    if (question == QMessageBox::Yes) new_game();
}

void MainWindow::on_actionQuit_triggered()
{

    QMessageBox::StandardButton question = QMessageBox::question(this, "", "Вы уверены, что хотите выйти?", QMessageBox::Yes | QMessageBox::No);
    if (question == QMessageBox::Yes) QApplication::quit();
}

void MainWindow::on_action_triggered()
{
    QMessageBox::information(this, "" ,"Правила игры следующие: Имеется набор из 52 карточек, на которых записаны числа от 1 до 13, причем карточки с каждым из этих чисел встречаются четырежды. "
                             "Имеется квадратное поле с 25 клетками. Случайным образом извлекается какая-либо из имеющихся карточек. "
                             "Игрок заносит число из извлеченной карточки в одну из клеток квадрата. "
                             "Так продолжается до тех пор, пока не будут заполнены все клетки квадрата. "
                             "\n\nПо окончанию игры заполнение соответствующего квадрата оценивается определенным количеством очков."
                             "\nЦель игры – разместить числа в клетках так, чтобы набрать наибольшее количество очков в соответствии с таблицей:"
                             "\nКомбинации чисел                                       В ряду или столбце / По диагонали"
                             "\nЗа 2 одинаковых числа                                                             10 очков    20 очков"
                             "\nЗа 2 пары одинаковых чисел                                                  20 очков    30 очков"
                             "\nЗа 3 одинаковых числа                                                             40 очков    50 очков"
                             "\nЗа 3 одинаковых числа и два других одинаковых числа   80 очков    90 очков"
                             "\nЗа 4 одинаковых числа                                                              160 очков  170 очков"
                             "\nЗа 5 последовательных чисел, в произвольном порядке 50 очков    60 очков"
                             "\nЗа три раза по 1 и два раза по 13                                             100 очков  110 очков"
                             "\nЗа числа 1, 13, 12, 11 и 10, в произвольном порядке          150 очков  160 очков"
                             "\nЗа 4 единицы                                                                               200 очков  210 очков" );
}
