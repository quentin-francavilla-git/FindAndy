#include "../../include/game.h"

void menu(t_game *a)
{
    menu_events(a);
    menu_display(a);
}

void end_menu(t_game *a)
{
    end_menu_events(a);
    end_menu_display(a);
}