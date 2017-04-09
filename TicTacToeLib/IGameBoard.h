#ifndef IGAMEBOARD_H
#define IGAMEBOARD_H

class IGameBoard
{
public:
	virtual void PutChess(int x, int y, char chess) = 0;
	virtual char GetChess(int x, int y) = 0;
	virtual bool CheckWinOut(char chess) = 0;
};

#endif
