#include "winnerWindow.h"


WinnerWindow::WinnerWindow(const QString& text , Abstract* abstract)  : abstract(abstract)
{
    this->show();
    resize(470 , 200);
    label = new QLabel(text , this);
    button = new QPushButton("Reset" , this);

    connect(button , &QPushButton::clicked , this , &WinnerWindow::resetButtonClicked);

    setAppearance();
}
void WinnerWindow::setAppearance()
{
    QFont font;
    font.setPointSize(25);

    label->setFont(font);
    label->setFont(font);
    label->setMinimumSize(500 , 200);
    label->show();

    button->move(190 , 150);
    button->move(190 , 150);
    button->show();
}
void WinnerWindow::resetButtonClicked()
{
    abstract->reset();
    abstract->currentRound = Abstract::circle;

    delete this;
}
void WinnerWindow::closeEvent(QCloseEvent *event)
{
    QApplication::quit();
}
