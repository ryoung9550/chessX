#ifndef _RULE_ENFORCER_H
#define _RULE_ENFORCER_H

#include <memory>

#include "chess/game_board.h"
#include "chess/board_square.h"
#include "common/pos.h"
#include "common/globals.h"

/*
 * This class will enforce rules an return suggestions
 * of what moves can be made. Any move that is made
 * must go through this object.
 */
class RuleEnforcer
{
	GameBoard& board;
	BoardRep getPawnMoves(const Pos&);
	BoardRep getRookMoves(const Pos&);
	BoardRep getKnightMoves(const Pos&);
	BoardRep getBishopMoves(const Pos&);
	BoardRep getQueenMoves(const Pos&);
	BoardRep getKingMoves(const Pos&);
public:
	RuleEnforcer(GameBoard&);
	BoardRep getMoves(const Pos& pos);
	void movePiece(std::shared_ptr<GamePiece> gamepiece, std::shared_ptr<BoardSquare> dest);
};

#endif // _RULE_ENFORCER_H
