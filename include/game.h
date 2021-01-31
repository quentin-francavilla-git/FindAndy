#ifndef GAME_H__
#define GAME_H__

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <unistd.h>
#include <time.h>
#include <SFML/Window.h>

#include "lib.h"
#include "player.h"
#include "levels.h"

typedef struct s_window
{
    sfRenderWindow *window;
    sfVector2i pos_window;

    sfEvent event;
    sfKeyEvent key;
} t_window;

typedef struct s_textures
{
    //player
    sfTexture *player_walk_right;
    sfTexture *player_walk_left;
    sfTexture *player_idle;
    sfTexture *player_idle_left;

    sfIntRect rect_walk_right;
    sfIntRect rect_idle;


    sfTexture *enemis;

    sfTexture *power_up;


    sfTexture *dino;
    sfIntRect rect_dino;

    sfTexture *life;

    sfTexture *alien;

    //map
    sfTexture *level1;
    sfTexture *platform;

    //menu
    sfTexture *logo;
    sfTexture *space;
    sfTexture *back_menu;
    sfTexture *back_game_over;
    sfTexture *back_win;

} t_textures;

typedef struct s_camera
{
    sfVector2f center_camera;
    sfFloatRect rect_camera;
    float zoom;
    sfView *camera;
    sfVector2f pos;
}t_camera;

typedef struct menu
{
    sfSprite *s_logo;
    sfSprite *s_back_menu;
    sfSprite *s_space;

    sfSprite *s_back_game_over;

    sfVector2f pos_back;
    sfVector2f pos_logo;
    sfVector2f pos_space;
}t_menu;

typedef struct s_game
{
    int game_status;
    int canInput;
    int win;

    t_window window;
    t_player player;
    t_textures t;
    t_levels levels;
    t_camera camera;
    t_menu menu;
} t_game;


//game
void game_events(t_game *a);
void game_display(t_game *a);
void game(t_game *a);

//camera
void camera(t_game *a);
void camera_init(t_game *a);

//menu
void menu_display(t_game *a);
void menu_events(t_game *a);
void menu(t_game *a);

//player
void player_init(t_game *a);
void clocks_player_init(t_game *a);
void player_move(t_game *a);
void player_display(t_game *a);
void player_move_rect(t_game *a);

//levels
void levels_display(t_game *a);
void levels_init(t_game *a);
void platforms_init(t_game *a);;

//menu
void menu_init(t_game *a);
void end_menu_display(t_game *a);
void end_menu_events(t_game *a);
void end_menu(t_game *a);

#endif