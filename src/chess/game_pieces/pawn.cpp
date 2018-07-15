#include "chess/game_pieces/game_piece.h"
#include "chess/game_pieces/pawn.h"

Pawn::Pawn(const Player& owner) : GamePiece(owner, PieceType::PAWN), moved(false) {}
