#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cards = new int[25];
    cards = set_deck_of_card();
    i = 0;
    ui->label_4->setText(QString::number(cards[i]));

    connect(ui->pushButton_p11, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p12, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p13, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p14, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p15, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p21, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p22, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p23, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p24, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p25, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p31, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p32, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p33, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p34, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p35, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p41, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p42, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p43, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p44, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p45, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p51, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p52, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p53, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p54, SIGNAL(clicked()), this, SLOT(turn()));
    connect(ui->pushButton_p55, SIGNAL(clicked()), this, SLOT(turn()));
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
    Ai.choose_and_add(cards[i]);
    button->setText(QString::number(cards[i]));
    i++;
    if (i < 25 ) ui->label_4->setText(QString::number(cards[i]));
    else {
        ui->label_4->setText("");
        int P_score = First.get_score();
        int Ai_score = Ai.get_score();
    }
}
