#ifndef LEVELS_H__
#define LEVELS_H__

#include "lib.h"

typedef struct s_plat
{
    sfSprite *s_platform;
    sfVector2f pos;
    sfVector2f scale;
}t_platforms;


typedef struct s_levels
{
    sfSprite *s_map;
    int n_plats;
    int do_collision;
    int i_tmp;

    sfVector2f offset;
    sfVector2f pos;
    sfVector2f scale;

    sfSprite *alien;
    sfVector2f pos_alien;
    t_platforms *plat;
} t_levels;

#endif