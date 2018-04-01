#include "zorkhome.h"
#include "ui_zorkhome.h"
#include "newGame.h"
#include "settings.h"
#include <QPixmap>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QtCore>

zorkHome::zorkHome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zorkHome)
{
    ui->setupUi(this);

    QMediaPlaylist *gameMusic = new QMediaPlaylist();
    gameMusic->addMedia(QUrl("qrc:/sounds/gameMusic_Power Core.mp3"));
    gameMusic->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *soundtrack = new QMediaPlayer();
    soundtrack->setPlaylist(gameMusic);
    soundtrack->setVolume(50);
    soundtrack->play();
    // Bug: bg music plays multiple times when returning from main menu

    button = new QMediaPlayer();
    button->setMedia(QUrl("qrc:/sounds/buttonClick.mp3"));
    button->setVolume(50);
    // Looking at efficient ways to duplicate across whole game


    QPixmap zork (":/zorkLogo.png");
    QPixmap csis(":/CSIS.png");
    ui->zorkLogo->setPixmap(zork);
    ui->csisLogo->setPixmap(csis);
}

zorkHome::~zorkHome()
{
    delete ui;
}

void zorkHome::on_newGameButton_clicked()
{
    button->play();
    close();
    newGame ng;
    ng.setModal(true);
    ng.exec();
}

void zorkHome::on_exitButton_clicked()
{
    button->play();
    close();
}

void zorkHome::on_settingsButton_clicked()
{
    button->play();
    settings s;
    s.setModal(true);
    s.exec();
}

void zorkHome::on_leaderboardButton_clicked()
{
    button->play();
}
