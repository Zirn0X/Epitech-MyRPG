##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC = gcc

SRC	=	sources/my_main.c	\
		sources/my_rpg.c	\

SRC_HOME_MENU	=	sources/home_menu/page/home_page.c	\
					sources/home_menu/page/setting_page.c	\
					sources/home_menu/page/save_page.c	\
					sources/home_menu/event/home_page_event.c	\
					sources/home_menu/event/save_page_event.c	\
					sources/home_menu/utils/utils_framerate.c	\
					sources/home_menu/utils/utils_sound.c	\
					sources/home_menu/utils/utils_save.c	\
					sources/home_menu/utils/utils_name.c	\

SRC_SETS	=	sources/sets/game/set_game_scenes.c	\
				sources/sets/game/set_game.c	\
				sources/sets/menu/set_menu_scenes.c	\
				sources/sets/menu/set_menu.c	\
				sources/sets/menu/set_events.c	\
				sources/sets/menu/set_scenes.c	\
				sources/sets/player/set_player.c	\
				sources/sets/player/set_player_objects.c	\
				sources/sets/player/actions/set_player_actions.c	\
				sources/sets/set_scenes.c	\
				sources/sets/set_all.c	\
				sources/sets/manager/set_window.c	\
				sources/sets/manager/set_camera.c	\
				sources/sets/manager/set_cursor.c	\
				sources/sets/manager/set_manager.c	\
				sources/sets/manager/set_keys.c	\
				sources/sets/manager/set_delta_time.c	\
				sources/sets/game/set_events.c	\
				sources/sets/game/set_scenes.c	\
				sources/sets/menu/button/set_button_home_setting.c	\
				sources/sets/menu/button/set_button_home.c	\
				sources/sets/menu/button/set_button_save.c	\
				sources/sets/menu/set_hitbox.c	\
				sources/sets/effects/set_effects.c	\
				sources/sets/effects/set_shadow_effect.c	\
				sources/sets/effects/set_lanthern_effect.c	\
				sources/sets/objects/set_objects.c	\
				sources/sets/objects/set_lantern.c	\
				sources/sets/objects/set_potions.c	\
				sources/sets/objects/set_bandage.c	\
				sources/sets/objects/quest_objects/set_quest_object.c	\
				sources/sets/objects/quest_objects/set_obj_mushroom.c	\
				sources/sets/objects/quest_objects/set_paper.c	\
				sources/sets/objects/quest_objects/set_obj_cape.c	\
				sources/sets/maps/set_all_maps.c	\
				sources/sets/maps/set_manoir.c	\
				sources/sets/maps/set_exteriors.c	\
				sources/sets/maps/set_layer.c	\
				sources/sets/maps/csv/set_csv.c	\
				sources/sets/maps/csv/set_csv_manoir.c	\
				sources/sets/player/set_player_competencies.c	\
				sources/sets/game/set_competencies.c	\
				sources/sets/game/set_inventory.c	\
				sources/sets/game/set_pause.c	\
				sources/sets/maps/csv/set_csv_exteriors.c	\
				sources/sets/maps/csv/get_colision.c	\
				sources/sets/monsters/set_monsters.c	\
				sources/sets/monsters/set_flying_eye.c	\
				sources/sets/monsters/set_thief.c	\
				sources/sets/monsters/set_skeleton.c	\
				sources/sets/monsters/set_cyclope.c	\
				sources/sets/monsters/set_pos_random_in_spawner.c	\
				sources/sets/monsters/spawner/set_spawner.c	\
				sources/sets/monsters/spawner/search_spawner.c	\
				sources/sets/set_bar_life.c	\
				sources/sets/npcs/set_npcs.c	\
				sources/sets/chatbox/set_chatbox.c	\
				sources/sets/game/set_quests.c	\
				sources/sets/maps/csv/set_csv_cave.c	\
				sources/sets/maps/set_cave.c	\

SRC_GAME	=	sources/game/my_game.c	\
				sources/game/scenes/room/room.c	\
				sources/game/scenes/room/room_two.c	\
				sources/game/scenes/room/room_events.c	\
				sources/game/camera/camera.c	\
				sources/game/player/colision/check_colision_player.c	\
				sources/game/player/events/player_events.c	\
				sources/game/player/events/player_inventory_events.c	\
				sources/game/player/events/player_actions_events.c	\
				sources/game/player/events/player_move_events.c	\
				sources/game/player/events/checking_player_input.c	\
				sources/game/player/movement/player_move.c	\
				sources/game/player/movement/basic_movement.c	\
				sources/game/player/movement/player_check_move.c	\
				sources/game/player/movement/player_check_movement.c	\
				sources/game/player/movement/is_direction_valid.c	\
				sources/game/player/movement/player_animation.c	\
				sources/game/player/movement/get_animation.c	\
				sources/game/player/actions/actions_player.c	\
				sources/game/player/actions/which_actions.c	\
				sources/game/player/actions/action_player_run.c	\
				sources/game/player/actions/action_player_attacks.c	\
				sources/game/player/actions/player_action_animated.c	\
				sources/game/player/objects/add_object_player.c	\
				sources/game/player/objects/is_object_owned.c	\
				sources/game/player/objects/potion_event.c	\
				sources/game/player/objects/utils_object.c	\
				sources/game/player/objects/use_bandage.c	\
				sources/game/player/my_player.c	\
				sources/game/manager/is_input_valide.c	\
				sources/game/manager/is_key_correct_type.c	\
				sources/game/manager/get_input.c	\
				sources/game/effects/display_effects.c	\
				sources/game/effects/effects_following.c	\
				sources/game/player/competencies/player_competencies.c	\
				sources/game/player/events/player_competencies_events.c	\
				sources/game/scenes/competencies/competencies_scene.c	\
				sources/game/scenes/competencies/competencies_events.c	\
				sources/game/player/events/player_pause.c	\
				sources/game/scenes/pause/pause_scene.c	\
				sources/game/scenes/pause/pause_events.c	\
				sources/game/player/actions/action_player_interact.c	\
				sources/game/spawner/check_player_in_spawner.c	\
				sources/game/spawner/activate_spawner.c	\
				sources/game/spawner/desactive_spawner.c	\
				sources/game/spawner/display_monster.c	\
				sources/game/spawner/display_monsters_bf_ef.c	\
				sources/game/monsters/monsters_deplacement.c	\
				sources/game/monsters/enemy_action_animated.c	\
				sources/game/monsters/is_enemy_on_spawn.c	\
				sources/game/monsters/bar_life_follow.c	\
				sources/game/monsters/actions/action_enemy_attack.c	\
				sources/game/player/actions/action_player_skip.c	\
				sources/game/chatbox/display_chatbox.c	\
				sources/game/chatbox/create_chatbox.c	\
				sources/game/chatbox/change_chatbox.c	\
				sources/game/player/actions/action_player_house.c	\
				sources/game/scenes/exterior/exterior_scene.c	\
				sources/game/scenes/exterior/exterior_events.c	\
				sources/game/player/actions/action_player_exterior.c	\
				sources/game/scenes/inventory/inventory_scene.c	\
				sources/game/object/quest_object/obj_mushroom.c	\
				sources/game/object/quest_object/obj_paper.c	\
				sources/game/object/quest_object/obj_cape.c	\
				sources/game/player/actions/attack_enemies.c

SRC_MAP		=	sources/map/read_file.c	\
                sources/map/create_map.c	\
                sources/map/create_sprite_map.c	\
				sources/map/display_map.c	\
				sources/map/actualise_map.c	\

OBJ	=	$(SRC:.c=.o) $(SRC_PLAYER:.c=.o) $(SRC_HOME_MENU:.c=.o)	\
		$(SRC_SETS:.c=.o) $(SRC_GAME:.c=.o) $(SRC_MAP:.c=.o)

NAME = my_rpg

# EXTRACT	=	tar xf assets.tar.xz

CFLAGS =

CPPFLAGS	= -I ./includes

MATHFLAGS	=	-lm

LDFLAGS = -L ./lib

LDLIBS = -lmy

CSFMl_FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(CSFMl_FLAGS) $(MATHFLAGS)

clean:
	$(MAKE) clean -C lib
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib
	$(RM) $(NAME)
	$(RM) $(NAME_DEBUG)

debug: CPPFLAGS += -g
debug: re

re: fclean all

.PHONY: all clean fclean re debug
