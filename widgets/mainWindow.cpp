#include "mainWindow.h"
#include "winnerWindow.h"

MainWindow::MainWindow()
{
    show();
    resize(700 , 700);

    abstract = new Abstract;
}

void MainWindow::paintEvent(QPaintEvent *event) {

    Q_UNUSED(event)
    auto* centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    board = abstract->getBoard();

    drawBoard();
    drawPawns();
}
void MainWindow::drawBoard()
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black , 5));

    painter.drawLine(250 , 50 , 250 , 650);
    painter.drawLine(450 , 50 , 450 , 650);
    painter.drawLine(50 , 250 , 650 , 250);
    painter.drawLine(50 , 450 , 650 , 450);

    painter.setPen(QPen(Qt::black , 5));
}
void MainWindow::drawPawns()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black , 5));

    int centerPosition[2][3][3] = {
            {{150, 350, 550} , {150, 350, 550} , {150, 350, 550}},
            {{150, 150, 150} , {350, 350, 350}, {550, 550, 550} }
    };

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == Abstract::circle)
            {
                painter.drawEllipse(centerPosition[0][i][j] - 50 , centerPosition[1][i][j] - 50 , 100 , 100);
            }else if(board[i][j] == Abstract::cross)
            {
                painter.drawLine(centerPosition[0][i][j] - 50 , centerPosition[1][i][j] - 50 , centerPosition[0][i][j] + 50 , centerPosition[1][i][j] + 50);
                painter.drawLine(centerPosition[0][i][j] + 50 , centerPosition[1][i][j] - 50 , centerPosition[0][i][j] - 50 , centerPosition[1][i][j] + 50);
            }
        }
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    positionX = event->x();
    positionY = event->y();

    if(estimatePositions())
    {
        if (abstract->move(abstract->currentRound, positionX, positionY)) {
            if (abstract->currentRound == Abstract::circle) abstract->currentRound = Abstract::cross;
            else if (abstract->currentRound == Abstract::cross) abstract->currentRound = Abstract::circle;
        }
        update();

        QString winner = getWinnerName();
        if(winner != "")    new WinnerWindow(winner , abstract);
    }

}
bool MainWindow::estimatePositions()
{
    if(positionX > 50 && positionY > 50) {
        if (positionX < 250) positionX = 0;
        else if (positionX < 450) positionX = 1;
        else if (positionX < 650) positionX = 2;

        if (positionY < 250) positionY = 0;
        else if (positionY < 450) positionY = 1;
        else if (positionY < 650) positionY = 2;

        return true;
    }
    return false;
}
QString MainWindow::getWinnerName()
{
    if(abstract->checkForWinner() == Abstract::circle)          return "Gratulacje! Wygrał gracz kółek";
    else if(abstract->checkForWinner() == Abstract::cross)      return "Gratulacje! Wygrał gracz Krzyżków";

    return "";
}