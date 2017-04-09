#include "TicTacToeTestFixture.h"

#include "../TicTacToeLib/IGameBoard.h"
#include "../TicTacToeLib/SimpleGameBoard.h"
#include "../TicTacToeLib/ChessOverlapException.h"

#include <gtest/gtest.h>


TEST_F(TicTacToeTestFixture, IWantAGameBoard)
{
	
	IGameBoard* gameBoard = NULL;
	EXPECT_NO_THROW({ gameBoard = new SimpleGameBoard("simpleGame"); });
	EXPECT_TRUE(gameBoard != NULL);
	EXPECT_NO_THROW(delete gameBoard);
	
}

TEST_F(TicTacToeTestFixture, PutAndGetChess)
{
	char xChess = 'x';
	char yChess = 'y';
	IGameBoard* gameBoard = new SimpleGameBoard("simpleGame");
	gameBoard->PutChess(0, 0, xChess);
	gameBoard->PutChess(2, 2, yChess);
	EXPECT_EQ(xChess, gameBoard->GetChess(0, 0));
	EXPECT_EQ(yChess, gameBoard->GetChess(2, 2));
	delete gameBoard;
}

TEST_F(TicTacToeTestFixture, JugeThreeInLine)
{
	IGameBoard *gameBoard = new SimpleGameBoard("simpleBoard");
	IGameBoard *gameBoard2 = new SimpleGameBoard("simpleboard2");
	char xChess = 'x', yChess = 'o';
	gameBoard->PutChess(0, 0, xChess); gameBoard2->PutChess(0, 1, yChess);
	gameBoard->PutChess(1, 1, xChess); gameBoard2->PutChess(1, 1, yChess);
	gameBoard->PutChess(2, 2, xChess); gameBoard2->PutChess(2, 1, yChess);
	EXPECT_TRUE(gameBoard->CheckWinOut(xChess));
	EXPECT_TRUE(gameBoard2->CheckWinOut(yChess));
	EXPECT_FALSE(gameBoard->CheckWinOut(yChess));
	EXPECT_FALSE(gameBoard2->CheckWinOut(xChess));
	delete gameBoard;
	delete gameBoard2;
}

TEST_F(TicTacToeTestFixture, BizException_Occupied) {

	IGameBoard *gameBoard = new SimpleGameBoard("simple board");
	char xChar = 'X', yChar = '0';
	EXPECT_NO_THROW(gameBoard->PutChess(0, 0, xChar));
	EXPECT_THROW(gameBoard->PutChess(0, 0, xChar), ChessOverlapException);
	EXPECT_NO_THROW(gameBoard->PutChess(2, 2, yChar));
	EXPECT_THROW(gameBoard->PutChess(2, 2, yChar), ChessOverlapException);
	delete gameBoard;
}