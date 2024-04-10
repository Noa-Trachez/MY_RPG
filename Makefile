##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile (Project)
##

SRC	=	src/main.c \
		src/my_rpg.c \

INIT = 	src/init/main_init.c \
		src/init/check_assets.c \
		src/init/init_window.c \
		src/init/malloc_structs.c \
		src/init/init_sound.c \
		src/game/ingame/player/init_player.c \
		src/game/ingame/player/life/init_life.c \
		src/game/ingame/entity/npc/init_npc.c \
		src/game/ingame/quests/init_quests.c \
		src/game/ingame/entity/chests/init_chests.c \
		src/game/ingame/entity/doors/init_doors.c \
		src/init/init_tp.c \
		src/init/buttons/button_manager.c \
		src/init/buttons/button_manager_func.c \
		src/init/buttons/scale_window.c\
		src/init/buttons/sound_manager.c \
		src/init/init_cinematic.c \
		src/init/init_settings.c \

MENU =  src/game/main_loop.c \
		src/game/menus/main_menu.c \
		src/game/menus/pause_menu.c \
		src/game/menus/load_menu.c \
		src/game/menus/cin_menu/draw_cin.c \
		src/game/menus/cin_menu/effects.c \
		src/game/menus/cin_menu/actions.c \
		src/game/menus/settings_menu.c \
		src/game/menus/binding_menu.c \
		src/game/menus/how_to_play.c \
		src/game/binding_key/search_and_set.c \
		src/game/goto/goto_to_how_to_play.c \
		src/game/goto/goto_ingame.c \
		src/game/goto/goto_menu.c \
		src/game/goto/goto_settings.c \
		src/game/goto/goto_bind.c \
		src/game/goto/goto_load_menu.c \
		src/game/goto/goto_pause.c \

EVENT = src/game/event/event_manager.c \
		src/game/event/how_to_play_event.c \
		src/game/event/ingame/ingame_event.c \
		src/game/event/ingame/mouse_events.c \
		src/game/event/ingame/keyboard_events.c \
		src/game/event/load_menu_event.c \
		src/game/event/main_menu_event.c \
		src/game/event/pause_menu_event.c \
		src/game/event/settings_menu_event.c \
		src/game/event/inventory_event.c \
		src/game/event/mouse_events.c \
		src/game/event/binding_event.c \
		src/game/event/cinematic_event.c \

INGAME = src/game/ingame/ingame.c \
		src/game/ingame/loading_icon.c \
		src/game/ingame/player/player.c \
		src/game/ingame/player/attack.c \
		src/game/ingame/player/reload_weapon.c \
		src/game/ingame/player/movements.c \
		src/game/ingame/player/life/draw_life.c \
		src/game/ingame/player/check_tp.c \
		src/game/ingame/player/animations.c \
		src/game/ingame/player/death.c \
		src/game/ingame/player/interaction.c \
		src/game/ingame/player/inventory_manager/inventory_manager.c \
		src/game/ingame/player/inventory_manager/inventory_display.c \
		src/game/ingame/player/inventory_manager/inventory_ammo_display.c \
		src/game/ingame/player/inventory_manager/resize_inventory.c \
		src/game/ingame/player/inventory_manager/display_sidebar.c \
		src/game/ingame/player/inventory_manager/sidebar_ammo_display.c \
		src/game/ingame/entity/projectile/enemy/build_enemy_projectile.c \
		src/game/ingame/entity/projectile/enemy/enemy_projectile.c \
		src/game/ingame/entity/projectile/enemy/enemy_projectile_state.c \
		src/game/ingame/entity/projectile/enemy/enemy_projectile_hit.c \
		src/game/ingame/entity/projectile/projectile.c \
		src/game/ingame/entity/projectile/build_projectile.c \
		src/game/ingame/entity/projectile/projectile_state.c \
		src/game/ingame/entity/projectile/projectile_hit.c \
		src/game/ingame/quests/quest_builder.c \
		src/game/ingame/quests/item_quests.c \
		src/game/ingame/quests/display_quests.c \
		src/game/ingame/quests/update_quests.c \
		src/game/ingame/quests/resize_quests.c \
		src/game/ingame/quests/is_mouse_on_quest.c \
		src/game/ingame/quests/display_quest_hud.c \
		src/game/ingame/quests/update_quest_hud.c \
		src/game/ingame/entity/enemy/enemy.c \
		src/game/ingame/entity/enemy/returned.c \
		src/game/ingame/entity/enemy/enemy_builder.c \
		src/game/ingame/entity/enemy/boss_builder.c \
		src/game/ingame/entity/enemy/enemy_general_setter.c \
		src/game/ingame/entity/enemy/enemy_texture_setter.c \
		src/game/ingame/entity/enemy/build_enemy_item.c \
		src/game/ingame/entity/enemy/destroy_enemy_id.c \
		src/game/ingame/entity/enemy/enemy_spawner.c \
		src/game/ingame/entity/enemy/enemy_state.c \
		src/game/ingame/entity/enemy/depop_inactive_enemy.c \
		src/game/ingame/entity/enemy/enemy_attack.c \
		src/game/ingame/entity/chests/chests.c \
		src/game/ingame/entity/chests/chest_collide.c \
		src/game/ingame/entity/items/on_ground/pick_up_item.c \
		src/game/ingame/entity/items/destroy_item.c \
		src/game/ingame/entity/items/on_ground/on_ground_items.c \
		src/game/ingame/entity/items/generator/build_item.c \
		src/game/ingame/entity/items/generator/drop_npc_items.c \
		src/game/ingame/entity/items/generator/randomizer.c \
		src/game/ingame/entity/items/generator/item_weapon_type.c \
		src/game/ingame/entity/items/generator/item_ammo_type.c \
		src/game/ingame/entity/items/generator/item_food_type.c \
		src/game/camera/camera.c \
		src/game/particles/particles_manager.c \
		src/game/particles/common_particles/build_common_particules.c \
		src/game/particles/common_particles/common_particles_state.c \
		src/game/particles/thruster_particles/build_thruster_particules.c \
		src/game/particles/thruster_particles/thruster_particles_state.c \
		src/game/particles/zzz_particles/build_zzz_particles.c \
		src/game/particles/zzz_particles/zzz_particles_state.c \
		src/game/ingame/entity/doors/display_doors.c \
		src/game/ingame/entity/doors/move_doors.c \
		src/game/ingame/entity/doors/toggle_doors.c \
		src/game/ingame/entity/doors/door_behaviour.c \
		src/game/ingame/entity/doors/collide_doors.c \
		src/game/ingame/entity/npc/display_npc.c \
		src/game/ingame/entity/npc/npc_builder.c \
		src/game/ingame/entity/npc/npc_check.c \
		src/game/ingame/entity/npc/handle_npc.c \
		src/game/ingame/entity/npc/resize_npc.c \
		src/game/ingame/entity/npc/check_functions/main_check.c \
		src/game/ingame/entity/npc/exec_functions/main_exec.c \
		src/game/ingame/entity/npc/exec_functions/start_clock.c \
		src/game/ingame/entity/npc/check_functions/check_clock.c \
		src/game/ingame/story/main_story.c \
		src/game/ingame/story/player_spawn.c \
		src/game/ingame/story/boss_fight.c \
		src/game/ingame/story/boss_fight_state.c \
		src/game/ingame/stats/stats.c \
		src/game/ingame/ingame_display.c \

BUILDERS = src/builders/button/button_builder.c \
		src/builders/button/button_general_setter.c \
		src/builders/button/button_state.c \
		src/builders/button/button_sound.c \
		src/builders/button/button_texture_setter.c \
		src/builders/destroy/destroy_buttons.c \
		src/builders/text/create_text.c \
		src/builders/global.c \
		src/builders/global2.c \
		src/builders/global_sound.c \
		src/builders/sprites/create_sprite.c \
		src/game/ingame/entity/chests/chest_builder.c \
		src/builders/doors/build_door.c \
		src/init/screen_load.c \

MAP =	src/game/map/map_loading/load_layers.c \
		src/game/map/map_loading/map_file.c \
		src/game/map/map_switch.c \
		src/game/map/map_check.c \
		src/game/map/pathfinder/pathfinder.c \
		src/game/map/pathfinder/pathfinding_grid.c \
		src/game/map/pathfinder/straight_moves.c \
		src/game/map/pathfinder/diagonal_moves.c \

SAVES	=	src/saves/saving/save_config.c \
		src/saves/saving/save_game.c \
		src/saves/saving/save_infos.c \
		src/saves/saving/save_player.c \
		src/saves/saving/save_items.c \
		src/saves/saving/save_npc.c \
		src/saves/saving/save_quests.c \
		src/saves/saving/save_chests.c \
		src/saves/saving/save_tp.c \
		src/saves/saving/save_story.c \
		src/saves/loading/load_game.c \
		src/saves/loading/load_infos.c \
		src/saves/loading/load_player.c \
		src/saves/loading/load_items.c \
		src/saves/loading/load_conf.c \
		src/saves/loading/load_quests.c \
		src/saves/loading/load_npc.c \
		src/saves/loading/load_chests.c \
		src/saves/loading/load_tp.c \
		src/saves/loading/load_story.c \

UTILS	=	src/utils/maths.c \
		src/utils/maths_vectors.c \
		src/utils/change_sprite.c \
		src/utils/my_stat.c \
		src/game/binding_key/bind.c \
		src/game/binding_key/malloc_and_free.c \
		src/init/buttons/full_screen.c \

OBJ	= $(SRC:.c=.o) $(UTILS:.c=.o) $(MENU:.c=.o) $(EVENT:.c=.o) $(INGAME:.c=.o)\
	  $(BUILDERS:.c=.o) $(MAP:.c=.o) $(INIT:.c=.o) $(SAVES:.c=.o)

NAME	=	my_rpg

FLAGS	=	-Wall -Wextra

CSFML	=	-lcsfml-system -lcsfml-graphics -lcsfml-window -lcsfml-audio

LIB	=	-L lib/ -l my -lm

CFLAGS	=	-I ./include -Wall -Wextra

all: build_lib compile

build_lib:
	@make --no-print-directory -C lib/my
	@echo -e "\033[44m#####= LIB COMPILED =#####\e[0m"

compile: $(OBJ)
	@echo -e "\033[1;34m#####= Compiling Project... =#####\e[0m"
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB) $(CSFML)
	@echo -e "\033[42m#####= COMPILATION FINISHED =#####\e[0m"

clean:
	@echo -e "\033[1;31m#####= Removing .o files... =#####\e[0m"
	@make clean --no-print-directory -C lib/my
	rm -f $(OBJ)

fclean: clean
	@make fclean --no-print-directory -C lib/my
	@echo -e "\033[1;31m#####= Removing binary file... =#####\e[0m"
	rm -f $(NAME) vg*
	@echo -e "\033[41m#####= CLEANING DONE =#####\e[0m"

re:	fclean all

run: all
	./$(NAME)

valgrind:
	gcc -o $(NAME) $(FLAGS) $(SRC) $(UTILS) $(MENU) $(EVENT) $(INGAME) \
	$(BUILDERS) $(MAP) $(INIT) $(SAVES) $(LIB) $(CFLAGS) $(CSFML) -g
	valgrind ./$(NAME)
