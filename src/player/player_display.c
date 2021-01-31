#include "../../include/game.h"

void player_display(t_game *a)
{
    /*if (a->player.moving == 1) {
        sfSprite_setTextureRect(a->player.s_player, a->t.rect_walk_right);
        sfRenderWindow_drawSprite(a->window.window, a->player.s_player, NULL);
    }
    else {
        if (a->player.direction == 1)
            sfSprite_setTexture(a->player.s_player, a->t.player_idle, sfTrue);
        else if (a->player.direction == 2)
            sfSprite_setTexture(a->player.s_player, a->t.player_idle_left, sfTrue);
        sfSprite_setTextureRect(a->player.s_player, a->t.rect_idle);
    }*/
    if (a->player.dino == 0) {
        sfSprite_setTexture(a->player.s_player, a->t.player_walk_right, sfTrue);
        sfSprite_setTextureRect(a->player.s_player, a->t.rect_walk_right);
    }
    else if (a->player.dino == 1) {
        sfSprite_setTexture(a->player.s_player, a->t.dino, sfTrue);
        sfSprite_setTextureRect(a->player.s_player, a->t.rect_dino);  
    }
    sfRenderWindow_drawSprite(a->window.window, a->player.s_player, NULL);
}