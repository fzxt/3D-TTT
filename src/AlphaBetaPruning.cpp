#include <stdio.h>
#include "Player.hpp"
#include "ScoreKeeper.hpp"
#include "GameBoard.hpp"

/**
 * This class contains the logic for AlphaBetaPruning, takes into account depth with
 * `currentPly` variable.
 */

class AlphaBetaPruning {
public:
  /**
   * Method to run alphaBetaPruning.
   * @param gb GameBoard to work with.
   */
    static void run(GameBoard *gb) {
        alphaBetaPruning(gb->getCurrentTurn(), gb, __DBL_MIN__, __DBL_MAX__, 0);
    }
private:

  /**
   * Determine best move using AlphaBetaPruning.
   * @param  p          Current player.
   * @param  gb         GameBoard.
   * @param  alpha      Alpha value.
   * @param  beta       Beta value.
   * @param  currentPly currentPly.
   * @return            Score value.
   */
    static int alphaBetaPruning(Player p, GameBoard *gb, double alpha, double beta, int currentPly) {
        if (currentPly++ == 6 || gb->isFull()) {
            ScoreKeeper::calcScoreForPlayer(*gb, &p);
            return p.getScore();
        }

        if (gb->getCurrentTurn() == p) {
            return getMax(p, gb, alpha, beta, currentPly);
        } else {
            return getMin(p, gb, alpha, beta, currentPly);
        }
    }

    /**
     * Play the move with the max score.
     * @param p             the player that the AI will identify as
     * @param gb            the GameBoard
     * @param alpha         the alpha value
     * @param beta          the beta value
     * @param currentPly    the current depth
     * @return              the score of the board
     */
    static int getMax(Player p, GameBoard *gb, double alpha, double beta, int currentPly) {
        char indexOfBestMove = 'N';
        for (char theMove : gb->getAvailableMoves()) {
            GameBoard modifiedBoard = *gb;
            modifiedBoard.addBead(Bead(p.getColor()), theMove);
            int score = alphaBetaPruning(p, &modifiedBoard, alpha, beta, currentPly);

            if (score > alpha) {
                alpha = score;
                indexOfBestMove = theMove;
            }

            if (alpha >= beta) {
                break;
            }
        }

        if (indexOfBestMove != 'N') {
            gb->addBead(Bead(p.getColor()), indexOfBestMove);
        }

        return (int) alpha;
    }

    /**
     * Play the move with the lowest score.
     * @param p        the player that the AI will identify as
     * @param gb       the GameBoard
     * @param alpha         the alpha value
     * @param beta          the beta value
     * @param currentPly    the current depth
     * @return              the score of the board
     */
    static int getMin(Player p, GameBoard *gb, double alpha, double beta, int currentPly) {
        char indexOfBestMove = 'N';

        for (char theMove : gb->getAvailableMoves()) {
            GameBoard modifiedBoard = *gb;
            modifiedBoard.addBead(Bead(p.getColor()), theMove);

            int score = alphaBetaPruning(p, &modifiedBoard, alpha, beta, currentPly);

            if (score < beta) {
                beta = score;
                indexOfBestMove = theMove;
            }

            if (alpha >= beta) {
                break;
            }
        }

        if (indexOfBestMove != 'N') {
            gb->addBead(Bead(p.getColor()), indexOfBestMove);
        }

        return (int) beta;
    }
};
