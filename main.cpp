#include "Game.hpp"

int main()
{
    Game<EnemyAmount<1, 2, 3>, ItemAmount<3, 2, 1>, EnemyGoal<1>, NeedKey<true>> game;
    game.startGame();
    return 0;
}
