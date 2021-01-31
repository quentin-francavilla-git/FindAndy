#include "../../include/game.h"

void clocks_player_init(t_game *a)
{
    a->player.clocks_p.clock1 = sfClock_create();
    a->player.clocks_p.clock2 = sfClock_create();
    a->player.clocks_p.clock3 = sfClock_create();
    a->player.clocks_p.clock4 = sfClock_create();
}

void textures_player_init(t_game *a)
{
    a->t.player_walk_right = sfTexture_createFromFile("./img/player/run_right.png", NULL);
    a->t.player_walk_left = sfTexture_createFromFile("./img/player/run_left.png", NULL);
    a->t.player_idle = sfTexture_createFromFile("./img/player/idle.png", NULL);
    a->t.player_idle_left = sfTexture_createFromFile("./img/player/idle_left.png", NULL);

    a->t.enemis = sfTexture_createFromFile("./img/player/enemi.png", NULL);

    a->t.power_up = sfTexture_createFromFile("./img/player/power_up.png", NULL);

    a->t.dino = sfTexture_createFromFile("./img/player/dino.png", NULL);

    a->t.life = sfTexture_createFromFile("./img/player/life.png", NULL);
}

void variables_player(t_game *a)
{
    a->player.speed = 1000;
    a->player.moving = 0;
    a->player.direction = 1;
    a->player.dino = 0;
    a->player.score = 0;
    a->player.enemis_killed_dino = 0;
    a->player.nb_life = 1;

    a->player.can_jump = 1;
    a->player.going_up = 0;
    a->player.going_down = 0;
    a->player.jumping = 0;

    a->player.pos.x = 80;
    a->player.pos.y = 1000;
    a->player.tmp_pos.x = a->player.pos.x;
    a->player.tmp_pos.y = a->player.pos.y;

    a->t.rect_walk_right.top = 0;
    a->t.rect_walk_right.left = 0;
    a->t.rect_walk_right.width = 83;
    a->t.rect_walk_right.height = 107;

    a->t.rect_idle.top = 0;
    a->t.rect_idle.left = 0;
    a->t.rect_idle.width = 83;
    a->t.rect_idle.height = 107;

    a->t.rect_dino.top = 0;
    a->t.rect_dino.left = 0;
    a->t.rect_dino.width = 200;
    a->t.rect_dino.height = 150;

    a->player.scale.x = 1;
    a->player.scale.y = 1;
}

void fill_player(t_game *a)
{
    a->player.s_player = sfSprite_create();
    sfSprite_setScale(a->player.s_player, a->player.scale);
    sfSprite_setTexture(a->player.s_player, a->t.player_walk_right, sfTrue);
    sfSprite_setPosition(a->player.s_player, a->player.pos);
}

void fill_enemis(t_game *a)
{
    a->player.nb_enemis = 300;
    a->player.collision = 0;
    int i = 0;

    while (i < a->player.nb_enemis) {
        a->player.enemis[i].destroyed = 0;
        a->player.enemis[i].pos.x =(i + 2) * 900 + ((rand() % (1000 - 300 + 1)) + 300);
        a->player.enemis[i].pos.y = 1010;

        a->player.enemis[i].scale.x = 1;
        a->player.enemis[i].scale.y = 1;

        a->player.enemis[i].s_enemi = sfSprite_create();
        sfSprite_setTexture(a->player.enemis[i].s_enemi, a->t.enemis, sfTrue);
        sfSprite_setPosition(a->player.enemis[i].s_enemi, a->player.enemis[i].pos);
        sfSprite_setScale(a->player.enemis[i].s_enemi, a->player.enemis[i].scale);
        i++;
    }
}

void fill_power_up(t_game *a)
{
    int i = 0;
    a->player.nb_power_up = 5;

    while (i < a->player.nb_power_up) {
        a->player.power_up[i].destroyed = 0;
        a->player.power_up[i].pos.x = (i + 2) * 4000 + ((rand() % (3000 - 1500 + 1)) + 1500);
        a->player.power_up[i].pos.y = 900;

        a->player.power_up[i].scale.x = 1;
        a->player.power_up[i].scale.y = 1;

        a->player.power_up[i].s_power_up = sfSprite_create();
        sfSprite_setTexture(a->player.power_up[i].s_power_up, a->t.power_up, sfTrue);
        sfSprite_setPosition(a->player.power_up[i].s_power_up, a->player.power_up[i].pos);
        sfSprite_setScale(a->player.power_up[i].s_power_up, a->player.power_up[i].scale);
        i++;
    }
}

void fill_life(t_game *a)
{
    int i = 0;

    while (i < a->player.nb_life) {
        a->player.life[i].destroyed = 0;
        a->player.life[i].pos.x = i * 130 + 100;
        a->player.life[i].pos.y = 300;

        a->player.life[i].scale.x = 1;
        a->player.life[i].scale.y = 1;

        a->player.life[i].s_life = sfSprite_create();
        sfSprite_setTexture(a->player.life[i].s_life, a->t.life, sfTrue);
        sfSprite_setPosition(a->player.life[i].s_life, a->player.life[i].pos);
        sfSprite_setScale(a->player.life[i].s_life, a->player.life[i].scale);
        i++;
    }
}

void player_init(t_game *a)
{
    a->player.enemis = malloc(sizeof(t_enemis) * 500);
    a->player.power_up = malloc(sizeof(t_power_up) * 30);
    a->player.life = malloc(sizeof(t_life) * 30);
    variables_player(a);   
    textures_player_init(a);
    clocks_player_init(a);
    fill_player(a);
    fill_enemis(a);
    fill_power_up(a);
    fill_life(a);
}