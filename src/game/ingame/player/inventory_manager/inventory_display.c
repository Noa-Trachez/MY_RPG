/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** Inventory display
*/

#include "my_rpg.h"

void display_inventory_items(items_t *inventory, window_t *window,
sfVector2i size)
{
    items_t *head = inventory;
    sfVector2i offset = {0, 0};
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};
    sfVector2f pos = {234 * mode.x, 191 * mode.y};

    while (head) {
        sfRectangleShape_setPosition(head->sprite, (sfVector2f){pos.x + (108 *
        offset.x * mode.x), (pos.y + (116 * offset.y * mode.y))});
        sfRectangleShape_setScale(head->sprite, (sfVector2f){1, 1});
        sfRectangleShape_setSize(head->sprite,
        (sfVector2f){60 * mode.x, 60 * mode.y});
        sfRenderWindow_drawRectangleShape(window->screen, head->sprite, NULL);
        offset.x += 1;
        if (offset.x == size.x)
            offset = (sfVector2i){0, offset.y + 1};
        head = head->next;
    }
}

void display_slot_selector(equipedItems_t *equiped_items, window_t *window)
{
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    sfRectangleShape_setPosition(equiped_items->equipmentSlotRect,
    (sfVector2f){EQUIPMENT_SLOTS[equiped_items->equipmentSlot].left * mode.x,
    EQUIPMENT_SLOTS[equiped_items->equipmentSlot].top * mode.y});
    sfRectangleShape_setSize(equiped_items->equipmentSlotRect,
    (sfVector2f){130 * mode.x, 130 * mode.y});
    sfRenderWindow_drawRectangleShape(window->screen,
    equiped_items->equipmentSlotRect, 0);
}

void display_equiped_items(equipedItems_t *equiped_items, window_t *window)
{
    sfVector2f mode = {(float)window->mode.width / 1920,
    (float)window->mode.height / 1080};

    for (int i = 0; i < 4; i++) {
        if (!equiped_items->slots[i])
            continue;
        sfRectangleShape_setPosition(equiped_items->slots[i]->sprite,
        (sfVector2f){(float)(EQUIPMENT_SLOTS[i].left + 8) * mode.x,
        (float)(EQUIPMENT_SLOTS[i].top + 8) * mode.y});
        sfRectangleShape_setSize(equiped_items->slots[i]->sprite,
        (sfVector2f){110 * mode.x, 110 * mode.y});
        sfRenderWindow_drawRectangleShape(window->screen,
        equiped_items->slots[i]->sprite, 0);
    }
    display_slot_selector(equiped_items, window);
}

void inventory_display(player_t *player, items_t *inventory, window_t *window,
sfVector2i size)
{
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (!texture) {
        texture = sfTexture_createFromFile("assets/inventory/inventory.png",
        NULL);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
    }
    sfRenderWindow_setView(window->screen, window->menuView);
    resize_inventory(window, sprite);
    display_inventory_items(inventory, window, size);
    display_equiped_items(player->equipedItems, window);
    display_inventory_ammo(window, player->ammo);
    sfRenderWindow_setView(window->screen, window->gameView);
}
