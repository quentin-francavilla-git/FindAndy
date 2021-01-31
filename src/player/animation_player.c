#include "../../include/game.h"

void move_rect_walk(t_game *a)
{
    if (a->player.dino == 0)
    {
        if (a->player.direction == 1)
        {
            if (a->t.rect_walk_right.left == 1909)
            {
                a->t.rect_walk_right.left = 0;
            }
            else
                a->t.rect_walk_right.left += a->t.rect_walk_right.width;
        }
        else
        {
            if (a->t.rect_walk_right.left == 0)
            {
                a->t.rect_walk_right.left = 1909;
            }
            else
                a->t.rect_walk_right.left -= a->t.rect_walk_right.width;
        }
    }
    if (a->player.dino == 1)
    {
        if (a->player.direction == 1)
        {
            if (a->t.rect_dino.left == 2000)
            {
                a->t.rect_dino.left = 0;
            }
            else
                a->t.rect_dino.left += a->t.rect_dino.width;
        }
        else
        {
            if (a->t.rect_dino.left == 0)
            {
                a->t.rect_dino.left = 1909;
            }
            else
                a->t.rect_dino.left -= a->t.rect_dino.width;
        }
    }
}

void player_move_rect(t_game *a)
{
    a->player.clocks_p.frametime2 = a->player.clocks_p.time2.microseconds / 1000000.0;
    a->player.clocks_p.time2 = sfClock_getElapsedTime(a->player.clocks_p.clock2);
    if (a->player.clocks_p.frametime2 > 0.01)
    {
        move_rect_walk(a);
        sfClock_restart(a->player.clocks_p.clock2);
    }
}