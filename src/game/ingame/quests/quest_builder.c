/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Quest builder
*/

#include "my_rpg.h"

void set_nb_quests(quest_t *new_quest, all_quest_t tab)
{
    new_quest->sprite = sfRectangleShape_create();
    sfRectangleShape_setTexture(new_quest->sprite, get_objects(), 0);
    sfRectangleShape_setTextureRect(new_quest->sprite, tab.rect);
    sfRectangleShape_setSize(new_quest->sprite, tab.scale);
    new_quest->accomplish = 0;
    new_quest->nb = 0;
    new_quest->type = tab.type;
    new_quest->total = tab.total;
    new_quest->item[0] = tab.item[0];
    new_quest->item[1] = tab.item[1];
    new_quest->scale = tab.scale;
    new_quest->getItem = build_item_quest(new_quest);
}

quest_t *new_quest(quest_t *quest, all_quest_t tab)
{
    quest_t *new_quest = malloc(sizeof(quest_t));
    sfVector2f pos = {0, 0};

    set_nb_quests(new_quest, tab);
    new_quest->earned = my_strdup(tab.sentence);
    new_quest->text = create_text(tab.str, 30, pos);
    new_quest->desc = create_text(tab.desc, 30, pos);
    new_quest->sentence = create_text(tab.sentence, 30, pos);
    new_quest->mandatory = tab.mandatory;
    new_quest->next = NULL;
    if (quest == NULL)
        new_quest->prev = NULL;
    else {
        new_quest->prev = quest;
        new_quest->prev->next = new_quest;
    }
    return new_quest;
}
