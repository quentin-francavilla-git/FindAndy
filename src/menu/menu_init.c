#include "../../include/game.h"

void texture_menu(t_game *a)
{
    a->t.logo = sfTexture_createFromFile("./img/menu/logo.png", NULL);
    a->t.space = sfTexture_createFromFile("./img/menu/space.png", NULL);
    a->t.back_menu = sfTexture_createFromFile("./img/menu/back.png", NULL);
    a->t.back_game_over = sfTexture_createFromFile("./img/menu/game_over.jpg", NULL);
    a->t.back_menu = sfTexture_createFromFile("./img/menu/win.jpg", NULL);
}

void fill_menu(t_game *a)
{
    a->menu.s_logo = sfSprite_create();
    sfSprite_setTexture(a->menu.s_logo, a->t.logo, sfTrue);
    sfSprite_setPosition(a->menu.s_logo, a->menu.pos_logo);

    a->menu.s_back_menu = sfSprite_create();
    sfSprite_setTexture(a->menu.s_back_menu, a->t.back_menu, sfTrue);
    sfSprite_setPosition(a->menu.s_back_menu, a->menu.pos_back);

    a->menu.s_space = sfSprite_create();
    sfSprite_setTexture(a->menu.s_space, a->t.space, sfTrue);
    sfSprite_setPosition(a->menu.s_space, a->menu.pos_space);
}

void variables_menu(t_game *a)
{
    a->menu.pos_back.x = 0;
    a->menu.pos_back.y = 0;

    a->menu.pos_logo.x = 700;
    a->menu.pos_logo.y = 250;

    a->menu.pos_space.x = 720;
    a->menu.pos_space.y = 500;
}

void menu_init(t_game *a)
{
    texture_menu(a);
    variables_menu(a);
    fill_menu(a);
}