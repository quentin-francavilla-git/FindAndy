#include "../../include/game.h"

void game_events(t_game *a)
{
    while (sfRenderWindow_pollEvent(a->window.window, &a->window.event)) {
        if (a->window.event.type == sfEvtClosed)
            sfRenderWindow_close(a->window.window);
        if (a->window.event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(a->window.window);
        }

        //immobile
        if (a->window.event.type == sfEvtKeyReleased
        && !(sfKeyboard_isKeyPressed(sfKeyD))) {
            a->t.rect_walk_right.left = 0;
            a->player.moving = 0;
        }
        if (a->window.event.type == sfEvtKeyReleased
        && !(sfKeyboard_isKeyPressed(sfKeyQ))) {
            a->t.rect_walk_right.left = 0;
            a->player.moving = 0;
        }
    }
}