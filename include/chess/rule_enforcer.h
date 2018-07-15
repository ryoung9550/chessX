#ifndef _RULE_ENFORCER_H
#define _RULE_ENFORCER_H

#include <memory>

#include "chess/game_board.h"
#include "chess/board_square.h"
#include "common/globals.h"

/*
 * This class will enforce rules an return suggestions
 * of what moves can be made. Any move that is made
 * must go through this object.
 */
class RuleEnforcer
{
	GameBoard& board;
public:
	RuleEnforcer(GameBoard&);
	BoardRep getMoves(const GamePiece& srcPiece);
	void movePiece(std::shared_ptr<GamePiece> gamepiece, std::shared_ptr<BoardSquare> dest);
};

#endif // _RULE_ENFORCER_H
