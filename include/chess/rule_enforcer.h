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
	BoardRep getPawnMoves(const Pos&) const;
	BoardRep getRookMoves(const Pos&) const;
	BoardRep getKnightMoves(const Pos&) const;
	BoardRep getBishopMoves(const Pos&) const;
	BoardRep getQueenMoves(const Pos&) const;
	BoardRep getKingMoves(const Pos&) const;
	Player opponent(const Player&) const;
	static BoardRep combineReps(const BoardRep&, const BoardRep&);
	static bool isInBounds(const Pos&);
	static void initBoardRep(BoardRep&);
public:
	RuleEnforcer(GameBoard&);
	BoardRep getMoves(const Pos& pos) const;
	void movePiece(std::shared_ptr<GamePiece> gamepiece, std::shared_ptr<BoardSquare> dest);
};

#endif // _RULE_ENFORCER_H
