#include <stdexcept>
#include "../include/Game.h"
#include "gtest/gtest.h"

class GameTest : public testing::Test
{
  protected:
    double initialEloA;
    double initialEloB;
    Elo::Player playerA;
    Elo::Player playerB;
    Elo::Game game0;
    Elo::Game game1;

    GameTest() : initialEloA(2840.),
                 initialEloB(2786.),
                 playerA("Magnus Carlsen", initialEloA),
                 playerB("Viswanathan Anand", initialEloB),
                 game0(playerA, playerB),
                 game1(playerA, playerB)
    {
    }

    virtual ~GameTest()
    {
    }
};

TEST_F(GameTest, NoNegativeHardness)
{
    ASSERT_THROW(Elo::Game game2(playerA, playerB, -1), std::invalid_argument) << "HARDNESS can't be negative.";
}

TEST_F(GameTest, IsComparable)
{
    EXPECT_TRUE(game0 == game1) << "Equality operator doesn't work.";
    EXPECT_FALSE(game0 != game1) << "Unequality operator doesn't work.";
    ASSERT_EQ(game0, game1) << "Game objects should be comparable.";
}

TEST_F(GameTest, UpdatesEloOnWin)
{
    game0.updateElo(Elo::WIN);
    EXPECT_GT(playerA.getElo(), initialEloA) << "playerA's elo rating should be higher.";
    ASSERT_LT(playerB.getElo(), initialEloB) << "playerB's elo rating should be lower.";
}

TEST_F(GameTest, UpdatesEloOnDraw)
{
    game0.updateElo(Elo::DRAW);
    EXPECT_LT(playerA.getElo(), initialEloA) << "playerA's elo rating should be lower.";
    ASSERT_GT(playerB.getElo(), initialEloB) << "playerB's elo rating should be higher.";
}

TEST_F(GameTest, UpdatesEloOnLose)
{
    game0.updateElo(Elo::LOSE);
    EXPECT_LT(playerA.getElo(), initialEloA) << "playerA's elo rating should be lower.";
    ASSERT_GT(playerB.getElo(), initialEloB) << "playerB's elo rating should be higher.";
}
