/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Inventory events
*/

#include "my_rpg.h"

void get_equip_slot(main_t *main)
{
    sfIntRect slot;

    for (int i = 0; i < 4; i++) {
        slot = resize_mouse_slots(main->window, EQUIPMENT_SLOTS[i]);
        if (is_mouse_on_object(main->window,
        (sfVector2f){slot.left + slot.width / 2, slot.top + slot.height / 2},
        (sfVector2f){slot.width, slot.height}, (sfVector2f){1, 1}))
            main->game->player->equipedItems->equipmentSlot = i;
    }
}

int get_inv_slot(main_t *main)
{
    sfIntRect slot;

    for (int i = 0; i < 60; i++) {
        slot = resize_mouse_slots(main->window, INVENTORY_SLOTS[i]);
        if (is_mouse_on_object(main->window,
        (sfVector2f){slot.left + slot.width / 2, slot.top + slot.height / 2},
        (sfVector2f){slot.width, slot.height}, (sfVector2f){1, 1}))
            return (i);
    }
    return (-1);
}

void show_item_stats(main_t *main, int slot)
{
    int count = 0;
    items_t *head = main->game->player->inventory;

    while (head && count != slot) {
        count++;
        head = head->next;
    }
    if (!head)
        return;
}

void equip_item(main_t *main, int slot)
{
    int count = 0;
    equipedItems_t *equipedItems = main->game->player->equipedItems;
    items_t *head = main->game->player->inventory;

    while (head && count != slot) {
        count++;
        head = head->next;
    }
    if (!head)
        return;
    get_goals(main, QU_ITEM);
    equipedItems->slots[equipedItems->equipmentSlot] = head;
    equipedItems->equipmentSlot += (equipedItems->equipmentSlot == 3) ? 0 : 1;
}

void inventory_event(main_t *main)
{
    if (main->event.type == sfEvtMouseButtonPressed &&
    main->event.mouseButton.button == sfMouseLeft) {
        get_equip_slot(main);
        equip_item(main, get_inv_slot(main));
    }
    if (main->event.type == sfEvtMouseButtonPressed &&
    main->event.mouseButton.button == sfMouseRight)
        show_item_stats(main, get_inv_slot(main));
}
