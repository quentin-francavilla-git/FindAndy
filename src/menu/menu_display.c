#include "../../include/game.h"

void menu_display(t_game *a)
{
    sfRenderWindow_clear(a->window.window, sfBlack);
    sfRenderWindow_drawSprite(a->window.window, a->menu.s_back_menu, NULL);
    sfRenderWindow_drawSprite(a->window.window, a->menu.s_space, NULL);
    sfRenderWindow_drawSprite(a->window.window, a->menu.s_logo, NULL);
    sfRenderWindow_display(a->window.window);
}

void end_menu_display(t_game *a)
{
    sfRenderWindow_clear(a->window.window, sfBlack);
    a->camera.pos.x =  960;
    a->camera.pos.y = 540;
    sfView_setCenter(a->camera.camera, a->camera.pos);
    sfRenderWindow_setView(a->window.window, a->camera.camera);
    if (a->win == 2)
        sfSprite_setTexture(a->menu.s_back_menu, a->t.back_game_over, sfTrue);
    if (a->win == 1)
        sfSprite_setTexture(a->menu.s_back_menu, a->t.back_win, sfTrue);
    sfRenderWindow_drawSprite(a->window.window, a->menu.s_back_menu, NULL);
    sfRenderWindow_display(a->window.window);
}