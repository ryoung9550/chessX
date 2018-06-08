#include <component/game_board.h>
#include <common/globals.h>

#include <memory>
#include <array>

#define WHITE_ROOK_1 0
#define WHITE_KNIGHT_1 1
#define WHITE_BISHOP_1 2
#define WHITE_QUEEN 3
#define WHITE_KING 4
#define WHITE_BISHOP_2 5
#define WHITE_KNIGHT_2 6
#define WHITE_ROOK_2 7
#define W_PAWN_1 8
#define W_PAWN_2 9
#define W_PAWN_3 10
#define W_PAWN_4 11
#define W_PAWN_5 12
#define W_PAWN_6 13
#define W_PAWN_7 14
#define W_PAWN_8 15

#define BLACK_ROOK_1 63
#define BLACK_KNIGHT_1 62
#define BLACK_BISHOP_1 61
#define BLACK_KING 60
#define BLACK_QUEEN 59
#define BLACK_BISHOP_2 58
#define BLACK_KNIGHT_2 57
#define BLACK_ROOK_2 56
#define B_PAWN_1 55
#define B_PAWN_2 54
#define B_PAWN_3 53
#define B_PAWN_4 52
#define B_PAWN_5 51
#define B_PAWN_6 50
#define B_PAWN_7 49
#define B_PAWN_8 48

GameBoard::GameBoard()
{
	constexpr int NUM_OF_SQUARES = globals::BOARD_SIZE * globals::BOARD_SIZE;

	for (int i = 0; i < NUM_OF_SQUARES; ++i) {
		//TODO: Create square creation with game pieces
		switch (i) {
		case W_PAWN_1:
		case W_PAWN_2:
		case W_PAWN_3:
		case W_PAWN_4:
		case W_PAWN_5:
		case W_PAWN_6:
		case W_PAWN_7:
		case W_PAWN_8:
			break;
		case WHITE_ROOK_1:
		case WHITE_ROOK_2:
			break;
		case WHITE_KNIGHT_1:
		case WHITE_KNIGHT_2:
			break;
		case WHITE_BISHOP_1:
		case WHITE_BISHOP_2:
			break;
		case WHITE_QUEEN:
			break;
		case WHITE_KING:
			break;
		case B_PAWN_1:
		case B_PAWN_2:
		case B_PAWN_3:
		case B_PAWN_4:
		case B_PAWN_5:
		case B_PAWN_6:
		case B_PAWN_7:
		case B_PAWN_8:
			break;
		case BLACK_ROOK_1:
		case BLACK_ROOK_2:
			break;
		case BLACK_KNIGHT_1:
		case BLACK_KNIGHT_2:
			break;
		case BLACK_BISHOP_1:
		case BLACK_BISHOP_2:
			break;
		case BLACK_QUEEN:
			break;
		case BLACK_KING:
			break;
		default:
			gameSquares[i] = std::make_shared<BoardSquare>(*this);
		}
	}
}

std::shared_ptr<BoardSquare> GameBoard::getSquare(const size_t& row, const size_t& col)
{
	return gameSquares[ (col - 1) + ((row - 1) * 8) ];
}
