#include "Abstract.h"

Abstract::Abstract()
{
    board = new Class*[3];

    for(int i = 0; i < 3; i++)  board[i] = new Class[3];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = null;
}

bool Abstract::move(Abstract::Class cl, int positionX, int positionY) const
{
    if(board[positionY][positionX] == null)
    {
        board[positionY][positionX] = cl;
        return true;
    }else      return false;
}
Abstract::Class Abstract::checkForWinner() const
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][2] != null)    return board[i][2];
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != null)    return board[0][i];
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[2][2] != null)    return board[2][2];
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[2][0] != null)    return board[2][0];
    return null;
}

Abstract::Class **Abstract::getBoard() const {
    return board;
}

void Abstract::reset() const
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j <3; j++)
            board[i][j] = null;
}
