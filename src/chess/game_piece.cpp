#include <memory>

#include "chess/game_pieces/game_piece.h"
#include "chess/game_pieces/pawn.h"
#include "chess/game_pieces/bishop.h"
#include "chess/game_pieces/knight.h"
#include "chess/game_pieces/rook.h"
#include "chess/game_pieces/queen.h"
#include "chess/game_pieces/king.h"
#include "chess/game_pieces/null_piece.h"
#include "chess/board_square.h"
#include "common/globals.h"

GamePiece::GamePiece(const Player& p, const PieceType& type) : player(p), type(type) {}

PieceType GamePiece::getType()
{
	return this->type;
}

Player GamePiece::getPlayer()
{
	return this->player;
}

void GamePiece::setType(const PieceType& type)
{
	this->type = type;
}

void GamePiece::setPlayer(const Player& player)
{
	this->player = player;
}

Pawn::Pawn(const Player& player) : GamePiece(player, PieceType::PAWN) {}
Bishop::Bishop(const Player& player) : GamePiece(player, PieceType::BISHOP) {}
Rook::Rook(const Player& player) : GamePiece(player, PieceType::ROOK) {}
Knight::Knight(const Player& player) : GamePiece(player, PieceType::KNIGHT) {}
Queen::Queen(const Player& player) : GamePiece(player, PieceType::QUEEN) {}
King::King(const Player& player) : GamePiece(player, PieceType::KING) {}
NullPiece::NullPiece() : GamePiece(Player::NOT_A_PLAYER, PieceType::EMPTY) {}
