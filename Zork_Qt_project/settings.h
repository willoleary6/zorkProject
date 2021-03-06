#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

private slots:
    void on_backButton_clicked();

    void on_debugCB_clicked();

    void on_musicCB_clicked();

    void on_soundfxCB_clicked();

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
