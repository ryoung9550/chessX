#include "chess/rule_enforcer.h"
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

BoardRep RuleEnforcer::getPawnMoves(const Pos& /*pos*/) { return {0}; }
BoardRep RuleEnforcer::getRookMoves(const Pos& /*pos*/) { return {0}; }
BoardRep RuleEnforcer::getKnightMoves(const Pos& /*pos*/) { return {0}; }
BoardRep RuleEnforcer::getBishopMoves(const Pos& /*pos*/) { return {0}; }
BoardRep RuleEnforcer::getQueenMoves(const Pos& /*pos*/) { return {0}; }
BoardRep RuleEnforcer::getKingMoves(const Pos& /*pos*/) { return {0}; }
