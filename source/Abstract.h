#ifndef KOLKO_I_KRZYZYK_ABSTRACT_H
#define KOLKO_I_KRZYZYK_ABSTRACT_H

#include <QDebug>

class Abstract
{
public:
    enum Class
    {
        circle,
        cross,
        null,
    };

    Abstract();
    [[nodiscard]] Class checkForWinner() const;
    [[nodiscard]] bool move(Class cl , int positionX , int positionY) const;
    [[nodiscard]] Class** getBoard() const;
    void reset() const;

    Class currentRound = Abstract::circle;
    Class** board;
};

#endif //KOLKO_I_KRZYZYK_ABSTRACT_H
