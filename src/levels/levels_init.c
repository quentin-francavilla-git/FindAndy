#include "../../include/game.h"

void textures_levels_init(t_game *a)
{
    a->t.level1 = sfTexture_createFromFile("./img/levels/level1_back.jpg", NULL);
    a->t.platform = sfTexture_createFromFile("./img/levels/platform.png", NULL);
    a->t.alien = sfTexture_createFromFile("./img/levels/alien.png", NULL);
}

void fill_levels(t_game *a)
{
    a->levels.s_map = sfSprite_create();
    sfSprite_setTexture(a->levels.s_map, a->t.level1, sfTrue);
    sfSprite_setPosition(a->levels.s_map, a->levels.pos);
    sfSprite_setScale(a->levels.s_map, a->levels.scale);
}

void variables_levels(t_game *a)
{
    a->levels.do_collision = 0;
    a->levels.pos.x = 0;
    a->levels.pos.y = -800;

    a->levels.i_tmp = 0;

    a->levels.scale.x = 2;
    a->levels.scale.y = 2;

    a->levels.n_plats = 300;

    a->levels.offset.x = 0;
    a->levels.offset.y = 0;

    a->levels.plat = malloc(sizeof(t_platforms) * a->levels.n_plats + 1);
}

void platforms_init(t_game *a)
{
    int i = 0;

    while (i < a->levels.n_plats) {

        if (i < 150) {
            a->levels.plat[i].pos.x = i * 150;
            a->levels.plat[i].pos.y = 1070;
        }
        else {
            a->levels.plat[i].pos.x = (i-80) * (rand() % (1000 - 500 + 1)) + 500;
            a->levels.plat[i].pos.y = (rand() % (600 - 200 + 1)) + 300;
        }

        a->levels.plat[i].scale.x = 1;
        a->levels.plat[i].scale.y = 1;

        a->levels.plat[i].s_platform = sfSprite_create();
        sfSprite_setTexture(a->levels.plat[i].s_platform, a->t.platform, sfTrue);
        sfSprite_setPosition(a->levels.plat[i].s_platform, a->levels.plat[i].pos);
        sfSprite_setScale(a->levels.plat[i].s_platform, a->levels.plat[i].scale);
        i++;
    }
}

void levels_init(t_game *a)
{
    variables_levels(a);
    textures_levels_init(a);
    platforms_init(a);
    fill_levels(a);


    //alien
    a->levels.pos_alien.x = 21000; //21000
    a->levels.pos_alien.y = 1000;
    a->levels.alien = sfSprite_create();
    sfSprite_setTexture(a->levels.alien, a->t.alien, sfTrue);
    sfSprite_setPosition(a->levels.alien, a->levels.pos_alien);
}