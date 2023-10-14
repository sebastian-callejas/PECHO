#pragma once
#include <cstdint>
#include <iostream>
#include <bitset>

class Bitboard {
public:
    Bitboard() : value(0ULL) {}  // Initialize with all bits set to 0.

    // Constructor to initialize with a specific value.
    Bitboard(uint64_t initValue) : value(initValue) {}

    void FlipBoard() {
		value = value >> 56;
	}

    // Set the bitboard to a specific value.
    void SetValue(uint64_t newValue) {
        value = newValue;
    }

    // Get the current value of the bitboard.
    uint64_t GetValue() const {
        return value;
    }

    void PrintValue() const {
        std::cout << "Board value:" << std::endl;
        for (int rank = 7; rank >= 0; --rank) {
            std::bitset<8> row(value >> (rank * 8) & 0xFF);
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }

private:
    uint64_t value;
};

class Pawn : public Bitboard {
public:
    Pawn() : Bitboard(0x00FF000000000000ULL) {} // Represents the initial position of white pawns.
};

class Knight : public Bitboard {
public:
    Knight() : Bitboard(0x4200000000000000ULL) {} // Represents the initial position of white knights.
};

class Bishop : public Bitboard {
public:
    Bishop() : Bitboard(0x2400000000000000ULL) {} // Represents the initial position of white bishops.
};

class Rook : public Bitboard {
public:
    Rook() : Bitboard(0x8100000000000000ULL) {} // Represents the initial position of white rooks.
};

class Queen : public Bitboard {
public:
    Queen() : Bitboard(0x1000000000000000ULL) {} // Represents the initial position of white queens.
};

class King : public Bitboard {
public:
    King() : Bitboard(0x0800000000000000ULL) {} // Represents the initial position of white kings.
};
