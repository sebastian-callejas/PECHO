#pragma once
#include <array>
#include "Bitboard.h"

class StandardGameboard {
public:
    StandardGameboard() {
        InitializePieces();
    }

    const std::array<Bitboard, 12>& GetValue() const {
        return value;
    }

    void PrintValue() const {
        for (const auto& piece : value) {
			piece.PrintValue();
		}
	}

private:
    void InitializePieces() {
        value = {
            Pawn(),   // Initialize with a white pawn.
            Knight(), // Initialize with a white knight.
            Bishop(), // Initialize with a white bishop.
            Rook(),   // Initialize with a white rook.
            Queen(),  // Initialize with a white queen.
            King(),   // Initialize with a white king.

            Pawn(),   // Initialize with a black pawn.
            Knight(), // Initialize with a black knight.
            Bishop(), // Initialize with a black bishop.
            Rook(),   // Initialize with a black rook.
            Queen(),  // Initialize with a black queen.
            King()    // Initialize with a black king.
        };
    }

private:
    std::array<Bitboard, 12> value;
};
