#include "util.h"

typedef enum Move_t {
    Move_Rock,
    Move_Paper,
    Move_Scissors,
} Move_t;

typedef enum Outcome_t {
    Outcome_Lose,
    Outcome_Draw,
    Outcome_Win,
} Outcome_t;

static const uint32_t PointsPerOutcome[3] = { 0, 3, 6 };
static const uint32_t PointsPerMove[3]    = { 1, 2, 3 };
static const Move_t OutcomeTable[3][3]    = {
    { Move_Scissors,   Move_Rock,      Move_Paper      }, // Outcome_Lose
    { Move_Rock,       Move_Paper,     Move_Scissors   }, // Outcome_Draw
    { Move_Paper,      Move_Scissors,  Move_Rock       }, // Outcome_Win
};

Move_t parseMove(const char c) {
    if (c == 'A') return Move_Rock;
    if (c == 'B') return Move_Paper;
    if (c == 'C') return Move_Scissors;
    return Move_Rock; // shouldn't get here
}

Outcome_t parseOutcome(const char c) {
    if (c == 'X') return Outcome_Lose;
    if (c == 'Y') return Outcome_Draw;
    if (c == 'Z') return Outcome_Win;
    return Move_Rock; // shouldn't get here
}

int main() {
    StringArr_t lines = NULL;
    ReadLines("input.txt", &lines);

    uint32_t pointTotal = 0;
    for (size_t i = 0; i < arrlen(lines); i++) {
        Move_t theirs = parseMove(lines[i][0]);
        Outcome_t expectedOutcome = parseOutcome(lines[i][2]);
        Move_t yours = OutcomeTable[expectedOutcome][theirs];

        pointTotal += PointsPerMove[yours] + PointsPerOutcome[expectedOutcome];
    }

    printf("Point total: %d\n", pointTotal);

    return 0;
}