#include "../../include/game.h"

void camera_init(t_game *a)
{
    a->camera.pos.x = 0;
    a->camera.pos.y = 0;
    a->camera.rect_camera.top = 0;
    a->camera.rect_camera.left = 0;
    a->camera.rect_camera.width = 1920;
    a->camera.rect_camera.height = 1080;
    a->camera.camera = sfView_createFromRect(a->camera.rect_camera);
}

void camera(t_game *a)
{
    a->camera.pos.x = a->player.pos.x;
    a->camera.pos.y = a->player.pos.y - 200;
    if (a->camera.pos.x < 960)
        a->camera.pos.x = 960;
    if (a->camera.pos.x > 4800)
        a->camera.pos.x = 4800;
    sfView_setCenter(a->camera.camera, a->camera.pos);
    sfRenderWindow_setView(a->window.window, a->camera.camera);
}