#ifndef WINNER_WINDOW_H
#define WINNER_WINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QCloseEvent>

#include "../source/Abstract.h"

class WinnerWindow : public QMainWindow
{
Q_OBJECT

public:
    WinnerWindow(const QString& text , Abstract* abstract);

protected:
    void closeEvent(QCloseEvent* event) override;

protected slots:
    void resetButtonClicked();

private:
    void setAppearance();

private:
    Abstract* abstract;
    QLabel* label;
    QPushButton* button;
};


#endif //WINNER_WINDOW_H
