#include "../../include/game.h"

void game_display(t_game *a)
{
    sfRenderWindow_clear(a->window.window, sfBlack);
    levels_display(a);
    player_display(a);
    sfRenderWindow_display(a->window.window);
}