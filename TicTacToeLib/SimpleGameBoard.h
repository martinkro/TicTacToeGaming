#ifndef SIMPLE_GAMEBOARD_H
#define SIMPLE_GAMEBOARD_H

#include "IGameBoard.h"
#include <vector>
using namespace std;
class SimpleGameBoard :public IGameBoard
{
public:
	SimpleGameBoard(const char* name);

public:
	virtual void PutChess(int x, int y, char chess);
	virtual char GetChess(int x, int y);
	virtual bool CheckWinOut(char chess);

protected:
	void initboard_();
	bool IsThreeLine_(char chess);
private:
	vector<char> data_;
};

#endif
