#include "chess/rule_enforcer.h"
#include "chess/game_pieces/pawn.h"
#include "chess/game_pieces/rook.h"
#include "chess/game_pieces/knight.h"
#include "chess/game_pieces/bishop.h"
#include "chess/game_pieces/queen.h"
#include "chess/game_pieces/king.h"
#include "common/pos.h"
#include "common/globals.h"

RuleEnforcer::RuleEnforcer(GameBoard& board) : board(board) {}

BoardRep RuleEnforcer::getMoves(const Pos& pos)
{
	GamePiece piece = board.getSquare(pos).getPiece();
	
	switch(piece.getType()) {
	case PAWN:
		return getPawnMoves(pos);
	case ROOK:
		return getRookMoves(pos);
	case KNIGHT:
		return getKnightMoves(pos);
	case BISHOP:
		return getBishopMoves(pos);
	case QUEEN:
		return getQueenMoves(pos);
	case KING:
		return getKingMoves(pos);
	default:
		break;
	}
	return {0};
}

BoardRep RuleEnforcer::getPawnMoves(const Pos& pos) 
{
	BoardRep retBoard;
	initBoardRep(retBoard);

	Pawn piece = static_cast<Pawn&>(board.getSquare(pos).getPiece());
	Player owner = board.getSquare(pos).getPiece().getPlayer();
	switch(owner) {
	case Player::BLACK_PLAYER: { // Black player moves down the ranks
		Pos move = pos;
		move.rank--;

		// Standard Move 1 square
		if(isInBounds(move)) {
			retBoard[Pos::posToIndex(move)] = MoveType::VALID_MOVE;
		}

		// Move 2 if not moved
		if(!piece.hasMoved()) {
			move.rank--;
			if(isInBounds(move)) {
				retBoard[Pos::posToIndex(move)] = MoveType::VALID_MOVE;
			}
		}

		// Attack move if enemy at lower file diag
		Pos lwfDiag = Pos(pos.file - 1, pos.rank - 1);
		if(isInBounds(lwfDiag)) {
			GamePiece enemy = board.getSquare(lwfDiag).getPiece();
			if(enemy.getPlayer() == Player::WHITE_PLAYER) {
				retBoard[Pos::posToIndex(lwfDiag)] = MoveType::VALID_MOVE;
			}
		}

		// Attack move if enemy at higher file diag
		Pos hifDiag = Pos(pos.file + 1, pos.rank - 1);
		if(isInBounds(hifDiag)) {
			GamePiece enemy = board.getSquare(hifDiag).getPiece();
			if(enemy.getPlayer() == Player::WHITE_PLAYER) {
				retBoard[Pos::posToIndex(hifDiag)] = MoveType::VALID_MOVE;
			}
		}

		return retBoard;
		}
	case Player::WHITE_PLAYER: { // White player moves up the ranks
		Pos move = pos;
		move.rank++;

		// Standard Move 1 square
		if(isInBounds(move)) {
			retBoard[Pos::posToIndex(move)] = MoveType::VALID_MOVE;
		}

		// Move 2 if not moved
		if(!piece.hasMoved()) {
			move.rank++;
			if(isInBounds(move)) {
				retBoard[Pos::posToIndex(move)] = MoveType::VALID_MOVE;
			}
		}

		// Attack move if enemy at lower file diag
		Pos lwfDiag = Pos(pos.file - 1, pos.rank + 1);
		if(isInBounds(lwfDiag)) {
			GamePiece enemy = board.getSquare(lwfDiag).getPiece();
			if(enemy.getPlayer() == Player::BLACK_PLAYER) {
				retBoard[Pos::posToIndex(lwfDiag)] = MoveType::VALID_MOVE;
			}
		}

		// Attack move if enemy at higher file diag
		Pos hifDiag = Pos(pos.file + 1, pos.rank + 1);
		if(isInBounds(hifDiag)) {
			GamePiece enemy = board.getSquare(hifDiag).getPiece();
			if(enemy.getPlayer() == Player::BLACK_PLAYER) {
				retBoard[Pos::posToIndex(hifDiag)] = MoveType::VALID_MOVE;
			}
		}
		//TODO: Add en passant move

		return retBoard;
		}
	default:
		break;
	}

	return {0};
}

BoardRep RuleEnforcer::getRookMoves(const Pos& pos) 
{ 
	BoardRep retBoard;
	initBoardRep(retBoard);

	Player player = board.getSquare(pos).getPiece().getPlayer();
	Pos refPos = pos;

	// Rank+ movement
	refPos = pos;
	for(;;) {
		refPos.rank++;
		if(isInBounds(refPos)) {
			retBoard[Pos::posToIndex(refPos)] = MoveType::VALID_MOVE;
			GamePiece refPiece = board.getSquare(refPos).getPiece();
			if(refPiece.getType() != PieceType::EMPTY) {
				if(refPiece.getPlayer() == opponent(player)) {
					break;
				} else { // Same color piece
					retBoard[Pos::posToIndex(refPos)] = MoveType::INVALID_MOVE;
				}
			} 
		} else {
			break;
		}
	}
	
	// Rank- movement
	refPos = pos;
	for(;;) {
		refPos.rank--;
		if(isInBounds(refPos)) {
			retBoard[Pos::posToIndex(refPos)] = MoveType::VALID_MOVE;
			GamePiece refPiece = board.getSquare(refPos).getPiece();
			if(refPiece.getType() != PieceType::EMPTY) {
				if(refPiece.getPlayer() == opponent(player)) {
					break;
				} else { // Same color piece
					retBoard[Pos::posToIndex(refPos)] = MoveType::INVALID_MOVE;
				}
			} 
		} else {
			break;
		}
	}

	// File+ movement
	refPos = pos;
	for(;;) {
		refPos.file++;
		if(isInBounds(refPos)) {
			retBoard[Pos::posToIndex(refPos)] = MoveType::VALID_MOVE;
			GamePiece refPiece = board.getSquare(refPos).getPiece();
			if(refPiece.getType() != PieceType::EMPTY) {
				if(refPiece.getPlayer() == opponent(player)) {
					break;
				} else { // Same color piece
					retBoard[Pos::posToIndex(refPos)] = MoveType::INVALID_MOVE;
				}
			} 
		} else {
			break;
		}
	}

	// File- movement
	refPos = pos;
	for(;;) {
		refPos.file--;
		if(isInBounds(refPos)) {
			retBoard[Pos::posToIndex(refPos)] = MoveType::VALID_MOVE;
			GamePiece refPiece = board.getSquare(refPos).getPiece();
			if(refPiece.getType() != PieceType::EMPTY) {
				if(refPiece.getPlayer() == opponent(player)) {
					break;
				} else { // Same color piece
					retBoard[Pos::posToIndex(refPos)] = MoveType::INVALID_MOVE;
				}
			} 
		} else {
			break;
		}
	}

	return {0}; 
}
BoardRep RuleEnforcer::getKnightMoves(const Pos& /*pos*/) { return {0}; }
BoardRep RuleEnforcer::getBishopMoves(const Pos& /*pos*/) { return {0}; }
BoardRep RuleEnforcer::getQueenMoves(const Pos& /*pos*/) { return {0}; }
BoardRep RuleEnforcer::getKingMoves(const Pos& /*pos*/) { return {0}; }

bool RuleEnforcer::isInBounds(const Pos& pos)
{
	if(pos.file > globals::BOARD_SIZE || pos.rank > globals::BOARD_SIZE) {
		return false;
	}
	return true;
}

void RuleEnforcer::initBoardRep(BoardRep& board)
{
	for(size_t i = 0; i < globals::BOARD_SIZE * globals::BOARD_SIZE; ++i) {
		board[i] = MoveType::INVALID_MOVE;
	}
}

Player RuleEnforcer::opponent(const Player& player)
{
	switch(player) {
	case Player::BLACK_PLAYER:
		return Player::WHITE_PLAYER;
	case Player::WHITE_PLAYER:
		return Player::BLACK_PLAYER;
	default:
		return Player::NOT_A_PLAYER;
	}
}
