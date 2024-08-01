#ifndef KOLKO_I_KRZYZYK_MAINWINDOW_H
#define KOLKO_I_KRZYZYK_MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

#include "../source/Abstract.h"
#include "winnerWindow.h"


class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    void drawBoard();
    void drawPawns();
    bool estimatePositions();
    QString getWinnerName();

    Abstract* abstract;
    Abstract::Class** board{};

    int positionX{};
    int positionY{};
};

#endif //KOLKO_I_KRZYZYK_MAINWINDOW_H