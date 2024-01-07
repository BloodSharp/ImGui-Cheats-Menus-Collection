#pragma once

#include "IGCMC-Precompiled.h"

struct bind_t
{
	int		keynum;
	int		type;
};

struct cvars_ragebot
{
	bool	active;
	bool	friendly_fire;
	bool	raim_delayshot[2];
	bool	raim_tapping_mode;
	bool	raim_auto_fire;
	int		raim_auto_scope;
	bool	raim_remove_recoil;
	int		raim_remove_spread;
	int		raim_type;
	float	raim_fov;
	bool	raim_low_fps_mitigations[3];
	float	raim_low_fps_value;
	int		raim_resolver_pitch;
	int		raim_resolver_yaw;
	bind_t	raim_force_body_key;
	bool	raim_target_selection[3];
	int		raim_target_weight_damage;
	int		raim_target_weight_fov;
	int		raim_target_weight_head;
	int		raim_target_weight_neck;
	int		raim_target_weight_chest;
	int		raim_target_weight_stomach;
	int		raim_target_weight_arms;
	int		raim_target_weight_legs;

	bool	aa_enabled;
	bool	aa_teammates;
	int		aa_at_targets;
	int		aa_stand_pitch;
	int		aa_stand_yaw;
	int		aa_stand_desync;
	bool	aa_stand_desync_helper;
	int		aa_side;
	bind_t	aa_side_key;
	bool	aa_side_switch_when_take_damage;
	int		aa_move_pitch;
	int		aa_move_yaw;
	int		aa_roll;
	float	aa_stand_yaw_static;
	float	aa_roll_static;
	bool	aa_untrusted_checks;
	bool	aa_conditions[3];

	bool	fakelag_enabled;
	bool	fakelag_while_shooting;
	bool	fakelag_on_enemy_in_pvs;
	bool	fakelag_on_peek;
	bool	fakelag_triggers[2];
	int		fakelag_type;
	int		fakelag_choke_limit;
};

struct cvars_legitbot
{
	bool	active;
	bool	friendly_fire;
	bool	position_adjustment;
	bool	desync_helper;
	int		target_switch_delay;
	bool	aim_auto_scope;
	bool	aim_smooth_independence_fps;
	int		aim_block_attack_after_kill;
	bool	aim_dont_shoot_in_shield;
	bool	aim_demochecker_bypass;
	int		aim_recoil_standalone;
	bind_t	aim_key;
	bind_t	aim_psilent_key;
	bool	trigger_only_scoped;
	bool	trigger_accurate_traces;
	float	trigger_hitbox_scale;
	bind_t	trigger_key;
};

struct cvars_weapons
{
	bool	aim_enabled;
	bool	aim_hitboxes[6];
	bool	aim_auto_fire;
	bool	aim_auto_penetration;
	int		aim_auto_penetration_min_damage;
	bool	aim_psilent_tapping_mode;
	float	aim_psilent_angle;
	float	aim_fov;
	float	aim_smooth_auto;
	float	aim_smooth_in_attack;
	float	aim_smooth_scale_fov;
	float	aim_recoil_smooth;
	float	aim_recoil_fov;
	int		aim_recoil_start;
	float	aim_recoil_pitch;
	float	aim_recoil_yaw;
	int		aim_maximum_lock_on_time;
	int		aim_delay_before_aiming;
	int		aim_delay_before_firing;
	bool	aim_psilent_triggers[3];
	int		aim_psilent_type;
	int		aim_accuracy_boost;
	bool	trigger_enabled;
	bool	trigger_auto_penetration;
	int		trigger_auto_penetration_min_damage;
	bool	trigger_hitboxes[6];
	int		trigger_accuracy_boost;

	bool	raim_enabled;
	bool	raim_hitboxes[6];
	bool	raim_auto_penetration;
	int		raim_auto_penetration_min_damage;
	float	raim_head_scale;
	float	raim_neck_scale;
	float	raim_chest_scale;
	float	raim_stomach_scale;
	float	raim_arms_scale;
	float	raim_legs_scale;
	int		raim_autostop;
	bool	raim_autostop_crouch;
};

struct cvars_visuals
{
	bool	active;
	bind_t	panic_key;
	bool	copyright;
	float	copyright_position[3];
	bool	antiscreen;
	bool	streamer_mode;

	float	esp_dormant_time;
	bool	esp_dormant_fadeout;
	bool	esp_dormant_update_by_sound;
	bool	esp_interpolate_history;
	int		esp_font_size;
	bool	esp_player;
	bool	esp_player_players[3];
	int 	esp_player_box;
	bool	esp_player_box_outline;
	int		esp_player_box_filled;
	float	esp_player_box_color_t[4];
	float	esp_player_box_color_ct[4];
	int		esp_player_health;
	bool	esp_player_health_percentage;
	float	esp_player_health_percentage_color[4];
	int		esp_player_armor;
	float	esp_player_armor_color[4];
	int		esp_player_name;
	float	esp_player_name_color[4];
	int		esp_player_weapon_text;
	float	esp_player_weapon_text_color[4];
	int		esp_player_weapon_icon;
	float	esp_player_weapon_icon_color[4];
	int		esp_player_money;
	float	esp_player_money_color[4];
	int		esp_player_distance;
	int		esp_player_distance_measurement;
	float	esp_player_distance_color[4];
	int		esp_player_actions;
	float	esp_player_actions_color[4];
	bool	esp_player_actions_bar;
	float	esp_player_actions_bar_color[4];
	int		esp_player_has_c4;
	float	esp_player_has_c4_color[4];
	int		esp_player_has_defusal_kits;
	float	esp_player_has_defusal_kits_color[4];
	float	esp_player_line_of_sight;
	float	esp_player_line_of_sight_color[4];
	int		esp_player_hitboxes;
	float	esp_player_hitboxes_color[4];
	bool	esp_player_hitboxes_hit_position;
	float	esp_player_hitboxes_hit_position_time;
	float	esp_player_hitboxes_hit_position_color[4];
	float	esp_player_hitboxes_hit_position_color2[4];
	bool	esp_player_skeleton;
	float	esp_player_skeleton_color[4];
	bool	esp_player_skeleton_backtrack;
	float	esp_player_skeleton_backtrack_color[4];
	bool	esp_player_glow;
	bool	esp_player_glow_players[3];
	int		esp_player_glow_amount;
	bool	esp_player_glow_color_health_based;
	float	esp_player_glow_color_t[4];
	float	esp_player_glow_color_ct[4];
	bool	esp_player_sounds;
	bool	esp_player_sounds_players[3];
	float	esp_player_sounds_time;
	float	esp_player_sounds_circle_radius;
	float	esp_player_sounds_color_t[4];
	float	esp_player_sounds_color_ct[4];
	bool	esp_player_out_of_fov;
	int		esp_player_out_of_fov_draw_type;
	bool	esp_player_out_of_fov_players[2];
	bool	esp_player_out_of_fov_additional_info[3];
	float	esp_player_out_of_fov_size;
	float	esp_player_out_of_fov_radius;
	bool	esp_player_out_of_fov_aspect_ratio;
	float	esp_player_out_of_fov_color_t[4];
	float	esp_player_out_of_fov_color_ct[4];
	bool	esp_player_out_of_fov_impulse_alpha;
	bool	esp_player_out_of_fov_outline;

	float	colored_models_dormant_time;
	bool	colored_models_dormant_fadeout;
	bool	colored_models_paint_players_weapons;
	int		colored_models_players;
	bool	colored_models_players_wireframe;
	bool	colored_models_players_players[3];
	bool	colored_models_players_behind_wall;
	int		colored_models_players_color_health_based;
	float	colored_models_players_color_t_hide[4];
	float	colored_models_players_color_t_vis[4];
	float	colored_models_players_color_ct_hide[4];
	float	colored_models_players_color_ct_vis[4];
	int		colored_models_players_on_the_dead;
	float	colored_models_players_on_the_dead_color[4];
	int		colored_models_players_hit_position;
	float	colored_models_players_hit_position_time;
	float	colored_models_players_hit_position_color[4];
	int		colored_models_players_desync_aa;
	float	colored_models_players_desync_aa_color[4];
	int		colored_models_backtrack;
	bool	colored_models_backtrack_wireframe;
	bool	colored_models_backtrack_players[2];
	bool	colored_models_backtrack_behind_wall;
	float	colored_models_backtrack_color_t_hide[4];
	float	colored_models_backtrack_color_t_vis[4];
	float	colored_models_backtrack_color_ct_hide[4];
	float	colored_models_backtrack_color_ct_vis[4];
	int		colored_models_hands;
	bool	colored_models_hands_wireframe;
	float	colored_models_hands_color[4];
	bool	colored_models_hands_color_rainbow;
	float	colored_models_hands_color_rainbow_speed;
	bool	colored_models_dlight;
	bool	colored_models_dlight_players[3];
	int		colored_models_dlight_origin;
	float	colored_models_dlight_radius;
	float	colored_models_dlight_minlight;
	bool	colored_models_dlight_fading_lighting;
	float	colored_models_dlight_fading_lighting_speed;
	float	colored_models_dlight_color[4];
	bool	colored_models_elight;
	bool	colored_models_elight_players[3];
	float	colored_models_elight_radius;
	float	colored_models_elight_color[4];

	bool	esp_other_local_aa_side_arrows;
	bool	esp_other_local_sniper_crosshair;
	bool	esp_other_local_recoil_point;
	float	esp_other_local_recoil_point_color[4];
	bool	esp_other_local_spread_point;
	float	esp_other_local_spread_point_color[4];
	bool	esp_other_local_spread_circle;
	float	esp_other_local_spread_circle_color[4];
	float	esp_other_local_spread_circle_color2[4];
	bool	esp_other_local_aim_fov;
	float	esp_other_local_aim_fov_color[4];
	float	esp_other_local_aim_fov_color2[4];
	bool	esp_other_local_toggle_status;
	float	esp_other_local_toggle_status_color[4];
	float	esp_other_local_toggle_status_color2[4];

	bool	effects_hud_clear;
	int		effects_thirdperson;
	bind_t	effects_thirdperson_key;
	int		effects_custom_render_fov;
	bool	remove_scope;
};

struct cvars_kreedz
{
	bool	active;
};

struct cvars_misc
{
	bind_t	fakelatency_key;
	bool	fakelatency;
	int		fakelatency_amount;
	bool	namestealer;
	int		namestealer_interval;
	bool	automatic_reload;
	bool	automatic_pistol;
	bool	replace_models_with_original;
	bool	steamid_spoofer;
	bind_t	kb_key;
	bool	kb_enabled;
	bool	kb_friendly_fire;
	bool	kb_conditions[3];
	bool	kb_position_adjustment;
	int		kb_attack_type;
	int		kb_aim_type;
	bool	kb_aim_hitbox[6];
	float	kb_fov;
	float	kb_swing_distance;
	float	kb_stab_distance;
	float	kb_aim_hitbox_scale;
};

//extern std::map<std::string, cvar_t*> g_ClientCvarsMap;

namespace cvars
{
	extern cvars_ragebot ragebot;
	extern cvars_legitbot legitbot;
	extern cvars_weapons weapons[WEAPON_MAX_COUNT];
	extern cvars_visuals visuals;
	extern cvars_kreedz kreedz;
	extern cvars_misc misc;
}