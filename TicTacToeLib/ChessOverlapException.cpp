#include "ChessOverlapException.h"

#include <stdio.h>


const char* ChessOverlapException::what()const
{
	static char msg[1024] = { 0 };
	snprintf(msg, sizeof(msg), "ChessOverlapException:[%d,%d]", x_, y_);
	return msg;
}

ChessOverlapException::ChessOverlapException(int x, int y) :
	std::exception(),
	x_(x),
	y_(y)
{

}

ChessOverlapException::ChessOverlapException() :
	ChessOverlapException(0, 0)
{

}