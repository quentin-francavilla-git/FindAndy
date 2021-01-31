#ifndef PLAYER_H__
#define PLAYER_H__

#include "lib.h"

typedef struct s_clocks_players
{
    sfClock *clock1;
    sfTime time;
    float frametime;

    sfClock *clock2;
    sfTime time2;
    float frametime2;

    sfClock *clock3;
    sfTime time3;
    float frametime3;

    sfClock *clock4;
    sfTime time4;
    float frametime4;
} t_clocks_players;

typedef struct s_enemis
{
    sfVector2f pos;
    sfVector2f scale;
    sfSprite *s_enemi;
    int destroyed;
} t_enemis;

typedef struct s_power_up
{
    sfVector2f pos;
    sfVector2f scale;
    sfSprite *s_power_up;
    int destroyed;
} t_power_up;

typedef struct s_life
{
    sfVector2f pos;
    sfVector2f scale;
    sfSprite *s_life;
    int destroyed;
} t_life;

typedef struct s_player
{
    float speed;
    int moving;
    int direction;
    int can_jump;
    int jumping;
    int dino;
    int score;
    int enemis_killed_dino;

    int going_up;
    int going_down;

    int nb_life;

    sfVector2f offset;
    sfVector2f offset_enemis;

    sfVector2f pos;
    sfVector2f tmp_pos;
    sfVector2f scale;
    sfFloatRect rect;
    
    sfSprite *s_player;

    int nb_power_up;
    int nb_enemis;

    t_enemis *enemis;
    t_power_up *power_up;
    t_life *life;
    t_clocks_players clocks_p;
    int collision;
} t_player;

#endif