/*
** EPITECH PROJECT, 2021
** INCLUDE/LINKED_LISTS
** File description:
** Includes "linked_lists" functions
*/

#ifndef LINKED_LISTS_H
    #define LINKED_LISTS_H

//Structure template
struct linked_list_t {
    int data;
    struct linked_list_t *prev;
    struct linked_list_t *next;
};

void my_append_node(struct linked_list_t **list, int data);
void my_delete_node(struct linked_list_t **list, int n);

#endif/*LINKED_LISTS_H*/
