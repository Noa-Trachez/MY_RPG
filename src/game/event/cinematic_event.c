/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Cinematic events
*/

#include "my_rpg.h"

void cinematic_event(main_t *main)
{
    if (main->event.type == sfEvtKeyPressed &&
        main->event.key.code == sfKeyEnter)
        main->cinematic->go_next = 1;
    if (main->event.type == sfEvtKeyPressed &&
    main->event.key.code == sfKeyF5)
        main->cin = 1;
}
