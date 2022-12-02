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

static const uint32_t PointsPerOutcome[] = { 0, 3, 6 };
static const uint32_t PointsPerMove[] = { 1, 2, 3 };
static const Outcome_t GameOutcome[3][3] = {
    { Outcome_Draw, Outcome_Win,    Outcome_Lose    },
    { Outcome_Lose, Outcome_Draw,   Outcome_Win     },
    { Outcome_Win,  Outcome_Lose,   Outcome_Draw    },
};

Move_t parseMove(const char c) {
    if (c == 'A' || c == 'X') return Move_Rock;
    if (c == 'B' || c == 'Y') return Move_Paper;
    if (c == 'C' || c == 'Z') return Move_Scissors;
    return Move_Rock; // shouldn't get here
}

int main() {
    StringArr_t lines = NULL;
    ReadLines("input.txt", &lines);

    uint32_t pointTotal = 0;
    for (size_t i = 0; i < arrlen(lines); i++) {
        Move_t theirs = parseMove(lines[i][0]);
        Move_t yours = parseMove(lines[i][2]);
        Outcome_t outcome = GameOutcome[theirs][yours];

        pointTotal += PointsPerMove[yours] + PointsPerOutcome[outcome];
    }

    printf("Point total: %d\n", pointTotal);

    return 0;
}
