#ifndef CHESS_OVERLAP_EXCEPTION_H
#define CHESS_OVERLAP_EXCEPTION_H

#include <exception>

class ChessOverlapException :public std::exception
{
public:
	virtual const char* what() const;

public:
	ChessOverlapException(int x, int y);
	ChessOverlapException();

private:
	int x_;
	int y_;
};

#endif
