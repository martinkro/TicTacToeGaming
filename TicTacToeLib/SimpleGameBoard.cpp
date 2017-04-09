#include "SimpleGameBoard.h"
#include "ChessOverlapException.h"

const int xMaxDim = 3;
const int yMaxDim = 3;

SimpleGameBoard::SimpleGameBoard(const char* name):
	data_(9,'\0')
{

}

void SimpleGameBoard::initboard_() 
{
	data_.clear();
	data_.resize(9, '\0');
}

void SimpleGameBoard::PutChess(int x, int y, char chess)
{
	int xy = x * 3 + y;
	if (data_.empty())
	{
		initboard_();
	}
	if (data_[xy] != '\0') 
	{
		throw ChessOverlapException(x, y);
	}
	else
	{
		data_[xy] = chess;
	}
	
}

char SimpleGameBoard::GetChess(int x, int y)
{
	return data_[x * 3 + y];
}

bool SimpleGameBoard::CheckWinOut(char chess)
{
	return IsThreeLine_(chess);
}

bool SimpleGameBoard::IsThreeLine_(char chess)
{
	int x = 0;
	int y = 0;
	bool result = false;

	// three row
	for (x = 0; x < 3; x++) {
		for (y = 0; y < 3; y++)
		{
			if (data_[x * 3 + y] == chess)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (y == 3) {
			result = true;
			break;
		}
	}

	if (result)
	{
		return result;
	}

	// three col
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (data_[y * 3 + x] == chess)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (y == 3)
		{
			result = true;
			break;
		}
	}
	if (result)
	{
		return result;
	}

	// ¶Ô½ÇÏß
	if (data_[0 * 3 + 0] == chess
		&& data_[1 * 3 + 1] == chess
		&& data_[2 * 3 + 2] == chess
		)
	{
		return true;
	}

	if (data_[0 * 3 + (2 - 0)] == chess
		&& data_[1 * 3 + (2 - 1)] == chess
		&& data_[2 * 3 + (2 - 2)] == chess)
	{
		return true;
	}
	return result;
}