#include "../include/game.h"

void start_window(t_game *a)
{
    a->window.pos_window.x = 0;
    a->window.pos_window.y = 0;
    sfVideoMode video_mode = {1920, 1080, 32};
    a->window.window = sfRenderWindow_create(video_mode, "Find Andy", sfFullscreen, NULL);
    sfWindowStyle(sfFullscreen);
    sfRenderWindow_setFramerateLimit(a->window.window, 59);
    sfRenderWindow_setPosition(a->window.window, a->window.pos_window);

    while (sfRenderWindow_isOpen(a->window.window)) {
        if (a->game_status == 0)
            menu(a);
        if (a->game_status == 1)
            game(a);
        if (a->game_status == 2)
            end_menu(a);

    }
    sfView_destroy(a->camera.camera);
    sfRenderWindow_destroy(a->window.window);
}

void game_init(t_game *a)
{
    a->game_status = 1;
    a->canInput = 0;
    a->win = 0;
    player_init(a);
    levels_init(a);
    camera_init(a);
    menu_init(a);
}

int main()
{
    srand(time(0)); 
    t_game *a = malloc(sizeof(t_game));
    game_init(a);
    start_window(a);

    return 0;
}