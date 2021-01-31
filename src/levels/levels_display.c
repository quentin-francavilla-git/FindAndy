#include "../../include/game.h"

void levels_display(t_game *a)
{
    sfRenderWindow_drawSprite(a->window.window, a->levels.s_map, NULL);
    for (int i = 0; i < a->levels.n_plats; i++)
        sfRenderWindow_drawSprite(a->window.window, a->levels.plat[i].s_platform, NULL);
    for (int i = 0; i < a->player.nb_enemis; i++) {
        if (a->player.enemis[i].destroyed == 0)
            sfRenderWindow_drawSprite(a->window.window, a->player.enemis[i].s_enemi, NULL);
    }
    for (int i = 0; i < a->player.nb_power_up; i++) {
        if (a->player.power_up[i].destroyed == 0 && a->player.dino == 0)
            sfRenderWindow_drawSprite(a->window.window, a->player.power_up[i].s_power_up, NULL);
    }
    for (int i = 0; i < a->player.nb_life; i++) {
        if (a->player.life[i].destroyed == 0)
            sfRenderWindow_drawSprite(a->window.window, a->player.life[i].s_life, NULL);
    }
    sfRenderWindow_drawSprite(a->window.window, a->levels.alien, NULL);
}