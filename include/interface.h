/*
** EPITECH PROJECT, 2022
** B-MUL-200-LIL-2-1-myrpg-william.stoops
** File description:
** interface
*/

#ifndef INTERFACE_H_
    #define INTERFACE_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>

enum INTERFACE_E {IN_SAVED, IN_NOT_SAVED, IN_SELECTOR, IN_INVENTORY, IN_QUEST,
IN_HUD, IN_QUEST_ACCOMPLISH, IN_SIDEBAR, IN_TEXTBOX};

static const sfIntRect INTERFACE_SPRITE[] = {
    {0, 740, 400, 700}, {400, 740, 400, 700}, {800, 740, 401, 701},
    {0, 1440, 1688, 937}, {1686, 1440, 1814, 976}, {0, 2414, 1332, 740},
    {1243, 3371, 601, 100}, {0, 3298, 738, 167}, {739, 3299, 489, 171}
};

#endif/* !INTERFACE_H_ */
