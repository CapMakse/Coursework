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
