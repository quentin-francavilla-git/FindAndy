#include "../../include/game.h"

void collisions_enemis(t_game *a)
{
    int collisionX = 0;
    int collisionY = 0;
    for (int i = 0; i < a->player.nb_enemis; i++)
    {
        a->player.enemis[i].pos = sfSprite_getPosition(a->player.enemis[i].s_enemi);
        if (a->player.pos.x + 70 + (a->player.dino * 80) >= a->player.enemis[i].pos.x && a->player.pos.x <= a->player.enemis[i].pos.x + 40)
        {
            //a->player.enemis[i].destroyed = 1;
            //my_putchar('a');
            collisionX = 1;
        }
        if (a->player.pos.y <= a->player.enemis[i].pos.y && a->player.pos.y >= a->player.enemis[i].pos.y - 50)
        {
            //a->player.enemis[i].destroyed = 1;
            collisionY = 1;
        }
        if (collisionX == 1 && collisionY == 1)
        {
            if (a->player.dino == 1)
            {
                a->player.score += 500;
                a->player.enemis[i].destroyed = 1;
            }
            else
            {
                if (a->player.nb_life == 3)
                    a->player.nb_life = 2;
                else if (a->player.nb_life == 2)
                    a->player.nb_life = 1;
                if (a->player.nb_life == 1)
                    a->player.nb_life = 0;
            }
            //a->player.collision = 1;
            //a->game_status = 0;
        }
        else
        {
            a->player.score += 100;
        }
        collisionX = 0;
        collisionY = 0;
    }
}

void collisions_power_up(t_game *a)
{
    int collisionX = 0;
    int collisionY = 0;
    for (int i = 0; i < a->player.nb_power_up; i++)
    {
        a->player.power_up[i].pos = sfSprite_getPosition(a->player.power_up[i].s_power_up);
        if (a->player.pos.x + 70 >= a->player.power_up[i].pos.x && a->player.pos.x <= a->player.power_up[i].pos.x + 40)
        {
            collisionX = 1;
        }
        if (a->player.pos.y <= a->player.power_up[i].pos.y + 100 && a->player.pos.y >= a->player.power_up[i].pos.y - 50)
        {
            collisionY = 1;
        }
        if (collisionX == 1 && collisionY == 1 && a->player.dino == 0)
        {
            a->player.power_up[i].destroyed = 1;
            a->player.dino = 1;
            a->player.pos.y = 970;
            sfSprite_setPosition(a->player.s_player, a->player.pos);
            //a->game_status = 0;
        }
        collisionX = 0;
    }
}

void collisions_win(t_game *a)
{
    int collisionX = 0;
    int collisionY = 0;

    a->levels.pos_alien = sfSprite_getPosition(a->levels.alien);
    if (a->player.pos.x + 70 >= a->levels.pos_alien.x)
    {
        collisionX = 1;
    }
    if (collisionX == 1)
    {
        a->game_status = 2;
        a->win = 1;
    }
    collisionX = 0;
}

void sprite_gestion(t_game *a)
{
    player_move(a);

    collisions_enemis(a);
    collisions_power_up(a);
    collisions_win(a);
}

void dino_transfo(t_game *a)
{
    if (a->player.dino == 1)
    {
        a->player.clocks_p.frametime4 = a->player.clocks_p.time4.microseconds / 1000000.0;
        a->player.clocks_p.time4 = sfClock_getElapsedTime(a->player.clocks_p.clock4);
        if (a->player.clocks_p.frametime4 > 10)
        {
            a->player.dino = 0;
            a->player.pos.y = 1000;
            sfSprite_setPosition(a->player.s_player, a->player.pos);
            sfClock_restart(a->player.clocks_p.clock4);
        }
    }
}

void lose(t_game *a)
{
    if (a->player.nb_life <= 0)
    {
        a->win = 2;
        a->game_status = 2;
    }
}

void game(t_game *a)
{
    a->player.pos = sfSprite_getPosition(a->player.s_player);
    camera(a);
    dino_transfo(a);
    game_events(a);
    sprite_gestion(a);
    game_display(a);
    lose(a);
}