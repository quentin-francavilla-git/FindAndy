#include "../../include/game.h"

void menu_events(t_game *a)
{
    while (sfRenderWindow_pollEvent(a->window.window, &a->window.event)) {
        if (a->window.event.type == sfEvtClosed)
            sfRenderWindow_close(a->window.window);
        if (a->window.event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(a->window.window);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        a->game_status = 1;
}

void end_menu_events(t_game *a)
{
    while (sfRenderWindow_pollEvent(a->window.window, &a->window.event)) {
        if (a->window.event.type == sfEvtClosed)
            sfRenderWindow_close(a->window.window);
        if (a->window.event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(a->window.window);
        }
    }
}