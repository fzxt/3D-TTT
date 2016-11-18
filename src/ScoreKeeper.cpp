#include "ScoreKeeper.hpp"

int ScoreKeeper::calcScoreFullTower(GameBoard board, Player *p) {
    int score = 0;

    //Players color
    Color pC = p->getColor();

    //Check for pegs on the same tower.
    for (int i = 0; i < 8; i++) {
        Peg currPeg = board.at(i);
        Bead b1 = currPeg.getBeadAtLevel(0);
        Bead b2 = currPeg.getBeadAtLevel(1);
        Bead b3 = currPeg.getBeadAtLevel(2);

        if (b1.color == pC && b2.color == pC && b3.color == pC) {
            score++;
        }
    }

    return score;
}

int ScoreKeeper::calcScoreSingleLev(GameBoard board, Player *p) {
    int score = 0;

    Color pC = p->getColor();

    Peg p1 = board.at(0);
    Peg p2 = board.at(1);
    Peg p3 = board.at(2);
    Peg p4 = board.at(3);
    Peg p5 = board.at(4);
    Peg p6 = board.at(5);
    Peg p7 = board.at(6);
    Peg p8 = board.at(7);

    for (int i = 0; i < 3; i++) {
        Bead b1 = p1.getBeadAtLevel(i);
        Bead b2 = p2.getBeadAtLevel(i);
        Bead b3 = p3.getBeadAtLevel(i);
        Bead b4 = p4.getBeadAtLevel(i);
        Bead b5 = p5.getBeadAtLevel(i);
        Bead b6 = p6.getBeadAtLevel(i);
        Bead b7 = p7.getBeadAtLevel(i);
        Bead b8 = p8.getBeadAtLevel(i);

        bool ABC = b1.color == pC && b2.color == pC && b3.color == pC;
        bool FGH = b6.color == pC && b7.color == pC && b8.color == pC;
        bool BEH = b2.color == pC && b5.color == pC && b8.color == pC;
        bool BDF = b2.color == pC && b4.color == pC && b6.color == pC;
        bool ADG = b1.color == pC && b4.color == pC && b7.color == pC;
        bool BEG = b3.color == pC && b5.color == pC && b7.color == pC;

        if (ABC || FGH || BEH || BDF || ADG || BEG) {
            score++;
        }
    }

    return score;
}

int ScoreKeeper::calcScoreMultipleLev(GameBoard board, Player *p) {
    int score = 0;

    Peg A = board.at(0);
    Peg B = board.at(1);
    Peg C = board.at(2);
    Peg D = board.at(3);
    Peg E = board.at(4);
    Peg F = board.at(5);
    Peg G = board.at(6);
    Peg H = board.at(7);

    Color pC = p->getColor();

    //B middle
    if (B.getBeadAtLevel(1).color == pC) {
        if (A.getBeadAtLevel(0).color == pC  && C.getBeadAtLevel(2).color == pC) {
            score++;
        }
        if (C.getBeadAtLevel(0).color == pC && A.getBeadAtLevel(2).color == pC) {
            score++;
        }
    }

    //D middle
    if (D.getBeadAtLevel(1).color == pC) {
        if (A.getBeadAtLevel(0).color == pC && G.getBeadAtLevel(2).color == pC) {
            score++;
        }
        if (G.getBeadAtLevel(0).color == pC && A.getBeadAtLevel(2).color == pC) {
            score++;
        }
        if (F.getBeadAtLevel(0).color == pC && B.getBeadAtLevel(2).color == pC) {
            score++;
        }
        if (B.getBeadAtLevel(0).color == pC && F.getBeadAtLevel(2).color == pC) {
            score++;
        }
    }

    //E middle
    if (E.getBeadAtLevel(1).color == pC) {
        if (B.getBeadAtLevel(0).color == pC && H.getBeadAtLevel(2).color == pC) {
            score++;
        }
        if (H.getBeadAtLevel(0).color == pC && B.getBeadAtLevel(2).color == pC) {
            score++;
        }
        if (C.getBeadAtLevel(0).color == pC && G.getBeadAtLevel(2).color == pC) {
            score++;
        }
        if (G.getBeadAtLevel(0).color == pC && C.getBeadAtLevel(2).color == pC) {
            score++;
        }
    }

    //G middle
    if (G.getBeadAtLevel(1).color == pC) {
        if (F.getBeadAtLevel(0).color == pC && H.getBeadAtLevel(2).color == pC) {
            score++;
        }
        if (H.getBeadAtLevel(0).color == pC && F.getBeadAtLevel(2).color == pC) {
            score++;
        }
    }

    return score;
}

void ScoreKeeper::calcScoreForPlayer(GameBoard board, Player *p) {
    int calcScore = 0;
    calcScore += calcScoreFullTower(board, p);
    calcScore += calcScoreSingleLev(board, p);
    calcScore += calcScoreMultipleLev(board, p);
    p->setScore(calcScore);
}

void ScoreKeeper::printWinner(GameBoard board, std::vector<Player> players) {
    if (players.size() != 2) return;

    Color pColor = WHITE;
    int pScore = 0;
    bool tie = false;

    calcScoreForPlayer(board, &players.at(0));
    calcScoreForPlayer(board, &players.at(1));

    Player p1 = players.at(0);
    Player p2 = players.at(1);


    if (p1.getScore() == p2.getScore()) {
        tie = true;
    } else if (p1.getScore() > p2.getScore()) {
        pColor = p1.getColor();
        pScore = p1.getScore();
        std::cout << "The AI lost, their score was: " << p2.getScore() << std::endl;
    } else {
        pColor = p2.getColor();
        pScore = p2.getScore();
        std::cout << "You lose, your final score was: " << p1.getScore() << std::endl;
    }

    std::string message = pColor == WHITE ? "WHITE" : "RED";

    if (tie) {
        message = "TIE, Both RED and WHITE";
        pScore = p1.getScore();
    }

    std::cout << "The winner is: " << message << " with " << pScore << std::endl;
}
