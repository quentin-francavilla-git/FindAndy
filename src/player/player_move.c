#include "../../include/game.h"

void player_move(t_game *a)
{
    a->player.pos = sfSprite_getPosition(a->player.s_player);

    a->player.clocks_p.frametime = a->player.clocks_p.time.microseconds / 1000000.0;
    a->player.clocks_p.time = sfClock_getElapsedTime(a->player.clocks_p.clock1);

    /*if (sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyD)) {

        sfSprite_setTexture(a->player.s_player, a->t.player_walk_right, sfTrue);
        a->player.direction = 1;
        player_move_rect(a);

        if (a->player.pos.x < 5675) {
            a->player.offset.x = a->player.speed * a->player.clocks_p.frametime;
            a->player.offset.y = 0;
            sfSprite_move(a->player.s_player, a->player.offset);   
            a->player.moving = 1;
        }

    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyQ)) {
        sfSprite_setTexture(a->player.s_player, a->t.player_walk_left, sfTrue);
        a->player.direction = 2;
        player_move_rect(a);

        
        if (a->player.pos.x > 0) {
            a->player.offset.x = -a->player.speed * a->player.clocks_p.frametime;
            a->player.offset.y = 0;
            sfSprite_move(a->player.s_player, a->player.offset);
            a->player.moving = 1;
        }
    }*/

    player_move_rect(a);


    for(int i = 0; i < a->levels.n_plats; i++) {
        a->levels.offset.x = -15;
        sfSprite_move(a->levels.plat[i].s_platform, a->levels.offset);
    }


    //jump
    //--------------------------

    if (sfKeyboard_isKeyPressed(sfKeySpace) && a->player.can_jump == 1) {
        a->player.can_jump = 0;
        a->player.jumping = 1;
    }

    if (a->player.jumping == 1
    && a->player.pos.y > 1000 + (a->player.dino * 30) - 180
    && a->player.going_down == 0) {
        a->player.going_up = 1;
        a->player.offset.y = -10;
        sfSprite_move(a->player.s_player, a->player.offset);
        for (int i = 0; i < a->player.nb_life; i++) {
            sfSprite_move(a->player.life[i].s_life, a->player.offset);
        }
    }
    else if (a->player.jumping == 1
    && a->player.pos.y < 1000 - (a->player.dino * 30)) {
        a->player.going_up = 0;
        a->player.going_down = 1;
        a->player.offset.y = 10;
        sfSprite_move(a->player.s_player, a->player.offset);
        for (int i = 0; i < a->player.nb_life; i++) {
            sfSprite_move(a->player.life[i].s_life, a->player.offset);
        }
    }

    if (a->player.pos.y >= 1000 - (a->player.dino * 30) && a->player.going_down == 1) {
         a->player.going_down = 0;
        a->player.can_jump = 1;
        a->player.jumping = 0;
    }




    if (a->levels.pos.x > -1000) {
        a->levels.offset.x = -1;
        sfSprite_move(a->levels.s_map, a->levels.offset);
    }

    for(int i = 0; i < a->player.nb_enemis; i++) {
        a->player.offset_enemis.y = 0;
        a->player.offset_enemis.x = -15;
        sfSprite_move(a->player.enemis[i].s_enemi, a->player.offset_enemis);
    }

    for(int j = 0; j < a->player.nb_power_up; j++) {
        a->player.offset_enemis.y = 0;
        a->player.offset_enemis.x = -15;
        sfSprite_move(a->player.power_up[j].s_power_up, a->player.offset_enemis);
    }
    sfSprite_move(a->levels.alien, a->player.offset_enemis);
    sfClock_restart(a->player.clocks_p.clock1);
}