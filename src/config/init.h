#ifndef FJORDWL_CONFIG_INIT_H
#define FJORDWL_CONFIG_INIT_H

#include <ctype.h>

static void normalize_compiled_config(void) {
	config.animations = CLAMP_INT(config.animations, 0, 1);
	config.layer_animations = CLAMP_INT(config.layer_animations, 0, 1);
	config.tag_animation_direction =
		CLAMP_INT(config.tag_animation_direction, 0, 1);
	config.animation_fade_in = CLAMP_INT(config.animation_fade_in, 0, 1);
	config.animation_fade_out = CLAMP_INT(config.animation_fade_out, 0, 1);
	config.zoom_initial_ratio =
		CLAMP_FLOAT(config.zoom_initial_ratio, 0.1f, 1.0f);
	config.zoom_end_ratio = CLAMP_FLOAT(config.zoom_end_ratio, 0.1f, 1.0f);
	config.fadein_begin_opacity =
		CLAMP_FLOAT(config.fadein_begin_opacity, 0.0f, 1.0f);
	config.fadeout_begin_opacity =
		CLAMP_FLOAT(config.fadeout_begin_opacity, 0.0f, 1.0f);
	config.animation_duration_move =
		CLAMP_INT(config.animation_duration_move, 1, 50000);
	config.animation_duration_open =
		CLAMP_INT(config.animation_duration_open, 1, 50000);
	config.animation_duration_tag =
		CLAMP_INT(config.animation_duration_tag, 1, 50000);
	config.animation_duration_close =
		CLAMP_INT(config.animation_duration_close, 1, 50000);
	config.animation_duration_focus =
		CLAMP_INT(config.animation_duration_focus, 0, 50000);
	config.scroller_default_proportion =
		CLAMP_FLOAT(config.scroller_default_proportion, 0.1f, 1.0f);
	config.scroller_default_proportion_single =
		CLAMP_FLOAT(config.scroller_default_proportion_single, 0.1f, 1.0f);
	config.scroller_ignore_proportion_single =
		CLAMP_INT(config.scroller_ignore_proportion_single, 0, 1);
	config.scroller_focus_center =
		CLAMP_INT(config.scroller_focus_center, 0, 1);
	config.scroller_prefer_center =
		CLAMP_INT(config.scroller_prefer_center, 0, 1);
	config.scroller_prefer_overspread =
		CLAMP_INT(config.scroller_prefer_overspread, 0, 1);
	config.scroller_structs = CLAMP_INT(config.scroller_structs, 0, 1000);
	config.default_mfact = CLAMP_FLOAT(config.default_mfact, 0.1f, 0.9f);
	config.default_nmaster = CLAMP_INT(config.default_nmaster, 1, 1000);
	config.center_master_overspread =
		CLAMP_INT(config.center_master_overspread, 0, 1);
	config.center_when_single_stack =
		CLAMP_INT(config.center_when_single_stack, 0, 1);
	config.new_is_master = CLAMP_INT(config.new_is_master, 0, 1);
	config.hotarea_size = CLAMP_INT(config.hotarea_size, 1, 1000);
	config.hotarea_corner = CLAMP_INT(config.hotarea_corner, 0, 3);
	config.enable_hotarea = CLAMP_INT(config.enable_hotarea, 0, 1);
	config.ov_tab_mode = CLAMP_INT(config.ov_tab_mode, 0, 1);
	config.overviewgappi = CLAMP_INT(config.overviewgappi, 0, 1000);
	config.overviewgappo = CLAMP_INT(config.overviewgappo, 0, 1000);
	config.xwayland_persistence = CLAMP_INT(config.xwayland_persistence, 0, 1);
	config.syncobj_enable = CLAMP_INT(config.syncobj_enable, 0, 1);
	config.drag_tile_refresh_interval =
		CLAMP_FLOAT(config.drag_tile_refresh_interval, 1.0f, 16.0f);
	config.drag_floating_refresh_interval =
		CLAMP_FLOAT(config.drag_floating_refresh_interval, 0.0f, 1000.0f);
	config.drag_tile_to_tile = CLAMP_INT(config.drag_tile_to_tile, 0, 1);
	config.allow_tearing = CLAMP_INT(config.allow_tearing, 0, 2);
	config.allow_shortcuts_inhibit =
		CLAMP_INT(config.allow_shortcuts_inhibit, 0, 1);
	config.allow_lock_transparent =
		CLAMP_INT(config.allow_lock_transparent, 0, 1);
	config.axis_bind_apply_timeout =
		CLAMP_INT(config.axis_bind_apply_timeout, 0, 1000);
	config.focus_on_activate = CLAMP_INT(config.focus_on_activate, 0, 1);
	config.idleinhibit_ignore_visible =
		CLAMP_INT(config.idleinhibit_ignore_visible, 0, 1);
	config.sloppyfocus = CLAMP_INT(config.sloppyfocus, 0, 1);
	config.warpcursor = CLAMP_INT(config.warpcursor, 0, 1);
	config.drag_corner = CLAMP_INT(config.drag_corner, 0, 4);
	config.drag_warp_cursor = CLAMP_INT(config.drag_warp_cursor, 0, 1);
	config.focus_cross_monitor = CLAMP_INT(config.focus_cross_monitor, 0, 1);
	config.exchange_cross_monitor =
		CLAMP_INT(config.exchange_cross_monitor, 0, 1);
	config.scratchpad_cross_monitor =
		CLAMP_INT(config.scratchpad_cross_monitor, 0, 1);
	config.focus_cross_tag = CLAMP_INT(config.focus_cross_tag, 0, 1);
	config.view_current_to_back = CLAMP_INT(config.view_current_to_back, 0, 1);
	config.enable_floating_snap = CLAMP_INT(config.enable_floating_snap, 0, 1);
	config.snap_distance = CLAMP_INT(config.snap_distance, 0, 99999);
	config.cursor_size = CLAMP_INT(config.cursor_size, 4, 512);
	config.no_border_when_single =
		CLAMP_INT(config.no_border_when_single, 0, 1);
	config.no_radius_when_single =
		CLAMP_INT(config.no_radius_when_single, 0, 1);
	config.cursor_hide_timeout =
		CLAMP_INT(config.cursor_hide_timeout, 0, 36000);
	config.single_scratchpad = CLAMP_INT(config.single_scratchpad, 0, 1);
	config.repeat_rate = CLAMP_INT(config.repeat_rate, 1, 1000);
	config.repeat_delay = CLAMP_INT(config.repeat_delay, 1, 20000);
	config.numlockon = CLAMP_INT(config.numlockon, 0, 1);
	config.disable_trackpad = CLAMP_INT(config.disable_trackpad, 0, 1);
	config.tap_to_click = CLAMP_INT(config.tap_to_click, 0, 1);
	config.tap_and_drag = CLAMP_INT(config.tap_and_drag, 0, 1);
	config.drag_lock = CLAMP_INT(config.drag_lock, 0, 1);
	config.trackpad_natural_scrolling =
		CLAMP_INT(config.trackpad_natural_scrolling, 0, 1);
	config.disable_while_typing = CLAMP_INT(config.disable_while_typing, 0, 1);
	config.left_handed = CLAMP_INT(config.left_handed, 0, 1);
	config.middle_button_emulation =
		CLAMP_INT(config.middle_button_emulation, 0, 1);
	config.swipe_min_threshold = CLAMP_INT(config.swipe_min_threshold, 1, 1000);
	config.mouse_natural_scrolling =
		CLAMP_INT(config.mouse_natural_scrolling, 0, 1);
	config.accel_profile = CLAMP_INT(config.accel_profile, 0, 2);
	config.accel_speed = CLAMP_FLOAT(config.accel_speed, -1.0f, 1.0f);
	config.scroll_method = CLAMP_INT(config.scroll_method, 0, 4);
	config.scroll_button = CLAMP_INT(config.scroll_button, 272, 276);
	config.click_method = CLAMP_INT(config.click_method, 0, 2);
	config.send_events_mode = CLAMP_INT(config.send_events_mode, 0, 2);
	config.button_map = CLAMP_INT(config.button_map, 0, 1);
	config.axis_scroll_factor =
		CLAMP_FLOAT(config.axis_scroll_factor, 0.1f, 10.0f);
	config.gappih = CLAMP_INT(config.gappih, 0, 1000);
	config.gappiv = CLAMP_INT(config.gappiv, 0, 1000);
	config.gappoh = CLAMP_INT(config.gappoh, 0, 1000);
	config.gappov = CLAMP_INT(config.gappov, 0, 1000);
	config.scratchpad_width_ratio =
		CLAMP_FLOAT(config.scratchpad_width_ratio, 0.1f, 1.0f);
	config.scratchpad_height_ratio =
		CLAMP_FLOAT(config.scratchpad_height_ratio, 0.1f, 1.0f);
	config.borderpx = CLAMP_INT(config.borderpx, 0, 200);
	config.smartgaps = CLAMP_INT(config.smartgaps, 0, 1);
	config.border_radius = CLAMP_INT(config.border_radius, 0, 100);
	config.focused_opacity = CLAMP_FLOAT(config.focused_opacity, 0.0f, 1.0f);
	config.unfocused_opacity =
		CLAMP_FLOAT(config.unfocused_opacity, 0.0f, 1.0f);
}

static void init_compiled_config(void) {
	memset(&config, 0, sizeof(config));

	config.animations = animations;
	config.layer_animations = layer_animations;
	snprintf(config.animation_type_open, sizeof(config.animation_type_open),
			 "%.9s", animation_type_open);
	snprintf(config.animation_type_close, sizeof(config.animation_type_close),
			 "%.9s", animation_type_close);
	snprintf(config.layer_animation_type_open,
			 sizeof(config.layer_animation_type_open), "%.9s",
			 layer_animation_type_open);
	snprintf(config.layer_animation_type_close,
			 sizeof(config.layer_animation_type_close), "%.9s",
			 layer_animation_type_close);
	config.animation_fade_in = animation_fade_in;
	config.animation_fade_out = animation_fade_out;
	config.tag_animation_direction = tag_animation_direction;
	config.zoom_initial_ratio = zoom_initial_ratio;
	config.zoom_end_ratio = zoom_end_ratio;
	config.fadein_begin_opacity = fadein_begin_opacity;
	config.fadeout_begin_opacity = fadeout_begin_opacity;
	config.animation_duration_move = animation_duration_move;
	config.animation_duration_open = animation_duration_open;
	config.animation_duration_tag = animation_duration_tag;
	config.animation_duration_close = animation_duration_close;
	config.animation_duration_focus = animation_duration_focus;
	memcpy(config.animation_curve_move, animation_curve_move,
		   sizeof(config.animation_curve_move));
	memcpy(config.animation_curve_open, animation_curve_open,
		   sizeof(config.animation_curve_open));
	memcpy(config.animation_curve_tag, animation_curve_tag,
		   sizeof(config.animation_curve_tag));
	memcpy(config.animation_curve_close, animation_curve_close,
		   sizeof(config.animation_curve_close));
	memcpy(config.animation_curve_focus, animation_curve_focus,
		   sizeof(config.animation_curve_focus));
	memcpy(config.animation_curve_opafadein, animation_curve_opafadein,
		   sizeof(config.animation_curve_opafadein));
	memcpy(config.animation_curve_opafadeout, animation_curve_opafadeout,
		   sizeof(config.animation_curve_opafadeout));

	config.scroller_structs = scroller_structs;
	config.scroller_default_proportion = scroller_default_proportion;
	config.scroller_default_proportion_single =
		scroller_default_proportion_single;
	config.scroller_ignore_proportion_single =
		scroller_ignore_proportion_single;
	config.scroller_focus_center = scroller_focus_center;
	config.scroller_prefer_center = scroller_prefer_center;
	config.scroller_prefer_overspread = scroller_prefer_overspread;
	config.focus_cross_monitor = focus_cross_monitor;
	config.exchange_cross_monitor = exchange_cross_monitor;
	config.scratchpad_cross_monitor = scratchpad_cross_monitor;
	config.focus_cross_tag = focus_cross_tag;
	config.view_current_to_back = view_current_to_back;
	config.no_border_when_single = no_border_when_single;
	config.no_radius_when_single = no_radius_when_single;
	config.snap_distance = snap_distance;
	config.enable_floating_snap = enable_floating_snap;
	config.drag_tile_to_tile = drag_tile_to_tile;
	config.swipe_min_threshold = swipe_min_threshold;
	config.focused_opacity = focused_opacity;
	config.unfocused_opacity = unfocused_opacity;
	config.scroller_proportion_preset = scroller_proportion_preset_values;
	config.scroller_proportion_preset_count =
		LENGTH(scroller_proportion_preset_values);
	config.circle_layout = circle_layout_names;
	config.circle_layout_count = LENGTH(circle_layout_names);

	config.new_is_master = new_is_master;
	config.default_mfact = default_mfact;
	config.default_nmaster = default_nmaster;
	config.center_master_overspread = center_master_overspread;
	config.center_when_single_stack = center_when_single_stack;

	config.hotarea_size = hotarea_size;
	config.hotarea_corner = hotarea_corner;
	config.enable_hotarea = enable_hotarea;
	config.ov_tab_mode = ov_tab_mode;
	config.overviewgappi = overviewgappi;
	config.overviewgappo = overviewgappo;
	config.cursor_hide_timeout = cursor_hide_timeout;

	config.axis_bind_apply_timeout = axis_bind_apply_timeout;
	config.focus_on_activate = focus_on_activate;
	config.idleinhibit_ignore_visible = idleinhibit_ignore_visible;
	config.sloppyfocus = sloppyfocus;
	config.warpcursor = warpcursor;
	config.drag_corner = drag_corner;
	config.drag_warp_cursor = drag_warp_cursor;

	config.repeat_rate = repeat_rate;
	config.repeat_delay = repeat_delay;
	config.numlockon = numlockon;
	config.capslock = capslock;

	config.disable_trackpad = disable_trackpad;
	config.tap_to_click = tap_to_click;
	config.tap_and_drag = tap_and_drag;
	config.drag_lock = drag_lock;
	config.mouse_natural_scrolling = mouse_natural_scrolling;
	config.trackpad_natural_scrolling = trackpad_natural_scrolling;
	config.disable_while_typing = disable_while_typing;
	config.left_handed = left_handed;
	config.middle_button_emulation = middle_button_emulation;
	config.accel_profile = accel_profile;
	config.accel_speed = accel_speed;
	config.scroll_method = scroll_method;
	config.scroll_button = scroll_button;
	config.click_method = click_method;
	config.send_events_mode = send_events_mode;
	config.button_map = button_map;
	config.axis_scroll_factor = axis_scroll_factor;

	config.border_radius = border_radius;
	config.border_radius_location_default = border_radius_location_default;

	config.smartgaps = smartgaps;
	config.gappih = gappih;
	config.gappiv = gappiv;
	config.gappoh = gappoh;
	config.gappov = gappov;
	config.borderpx = borderpx;
	config.scratchpad_width_ratio = scratchpad_width_ratio;
	config.scratchpad_height_ratio = scratchpad_height_ratio;
	memcpy(config.rootcolor, rootcolor, sizeof(config.rootcolor));
	memcpy(config.bordercolor, bordercolor, sizeof(config.bordercolor));
	memcpy(config.focuscolor, focuscolor, sizeof(config.focuscolor));
	memcpy(config.maximizescreencolor, maximizescreencolor,
		   sizeof(config.maximizescreencolor));
	memcpy(config.urgentcolor, urgentcolor, sizeof(config.urgentcolor));
	memcpy(config.scratchpadcolor, scratchpadcolor,
		   sizeof(config.scratchpadcolor));
	memcpy(config.globalcolor, globalcolor, sizeof(config.globalcolor));
	memcpy(config.overlaycolor, overlaycolor, sizeof(config.overlaycolor));

	config.log_level = log_level;
	config.tag_rules = tagrules;
	config.tag_rules_count = TAGRULES_COUNT;
	config.layer_rules = layerrules;
	config.layer_rules_count = LENGTH(layerrules);
	config.window_rules = windowrules;
	config.window_rules_count = LENGTH(windowrules);
	config.monitor_rules = monitorrules;
	config.monitor_rules_count = LENGTH(monitorrules);
	config.key_bindings = keys;
	config.key_bindings_count = LENGTH(keys);
	config.mouse_bindings = buttons;
	config.mouse_bindings_count = LENGTH(buttons);
	config.axis_bindings = axes;
	config.axis_bindings_count = AXES_COUNT;
	config.switch_bindings = switches;
	config.switch_bindings_count = SWITCHES_COUNT;
	config.gesture_bindings = gestures;
	config.gesture_bindings_count = GESTURES_COUNT;
	config.env = envvars;
	config.env_count = ENVVARS_COUNT;
	config.startup_commands = autostart;
	config.startup_commands_count = LENGTH(autostart);
	config.cursor_theme = cursor_theme;
	config.cursor_size = cursor_size;
	config.single_scratchpad = single_scratchpad;
	config.xwayland_persistence = xwayland_persistence;
	config.syncobj_enable = syncobj_enable;
	config.drag_tile_refresh_interval = drag_tile_refresh_interval;
	config.drag_floating_refresh_interval = drag_floating_refresh_interval;
	config.allow_tearing = allow_tearing;
	config.allow_shortcuts_inhibit = allow_shortcuts_inhibit;
	config.allow_lock_transparent = allow_lock_transparent;

	config.xkb_rules.rules = xkb_rules_rules;
	config.xkb_rules.model = xkb_rules_model;
	config.xkb_rules.layout = xkb_rules_layout;
	config.xkb_rules.variant = xkb_rules_variant;
	config.xkb_rules.options = xkb_rules_options;

	normalize_compiled_config();
}

static void apply_config_env(void) {
	int32_t i;

	for (i = 0; i < config.env_count; i++) {
		setenv(config.env[i].type, config.env[i].value, 1);
	}
}

static void run_autostart_commands(void) {
	Arg arg = {0};
	int32_t i;

	for (i = 0; i < config.startup_commands_count; i++) {
		arg.v = config.startup_commands[i];
		spawn_shell(&arg);
	}
}

static void set_xcursor_env(void) {
	if (config.cursor_size > 0) {
		char size_str[16];
		snprintf(size_str, sizeof(size_str), "%d", config.cursor_size);
		setenv("XCURSOR_SIZE", size_str, 1);
	} else {
		setenv("XCURSOR_SIZE", "24", 1);
	}

	if (config.cursor_theme) {
		setenv("XCURSOR_THEME", config.cursor_theme, 1);
	}
}

static int32_t parse_circle_direction(const char *str) {
	char lower_str[10];
	int32_t i = 0;

	while (str && str[i] && i < 9) {
		lower_str[i] = tolower((unsigned char)str[i]);
		i++;
	}
	lower_str[i] = '\0';

	return strcmp(lower_str, "next") == 0 ? NEXT : PREV;
}

static int32_t parse_direction(const char *str) {
	char lower_str[10];
	int32_t i = 0;

	while (str && str[i] && i < 9) {
		lower_str[i] = tolower((unsigned char)str[i]);
		i++;
	}
	lower_str[i] = '\0';

	if (strcmp(lower_str, "up") == 0)
		return UP;
	if (strcmp(lower_str, "down") == 0)
		return DOWN;
	if (strcmp(lower_str, "left") == 0)
		return LEFT;
	if (strcmp(lower_str, "right") == 0)
		return RIGHT;
	return UNDIR;
}

static int32_t parse_mouse_action(const char *str) {
	char lower_str[20];
	int32_t i = 0;

	while (str && str[i] && i < 19) {
		lower_str[i] = tolower((unsigned char)str[i]);
		i++;
	}
	lower_str[i] = '\0';

	if (strcmp(lower_str, "curmove") == 0)
		return CurMove;
	if (strcmp(lower_str, "curresize") == 0)
		return CurResize;
	if (strcmp(lower_str, "curnormal") == 0)
		return CurNormal;
	if (strcmp(lower_str, "curpressed") == 0)
		return CurPressed;
	return 0;
}

static uint32_t parse_num_type(char *str) {
	switch (str[0]) {
	case '-':
		return NUM_TYPE_MINUS;
	case '+':
		return NUM_TYPE_PLUS;
	default:
		return NUM_TYPE_DEFAULT;
	}
}

static char *combine_args_until_empty(char *values[], int count) {
	int32_t first_empty = count;
	int32_t i;
	size_t total_len = 0;
	char *combined = NULL;

	for (i = 0; i < count; i++) {
		if (!values[i] || values[i][0] == '\0') {
			first_empty = i;
			break;
		}
	}

	if (first_empty == 0)
		return strdup("");

	for (i = 0; i < first_empty; i++)
		total_len += strlen(values[i]);
	total_len += first_empty - 1;

	combined = malloc(total_len + 1);
	if (!combined)
		return strdup("");

	combined[0] = '\0';
	for (i = 0; i < first_empty; i++) {
		if (i > 0)
			strcat(combined, ",");
		strcat(combined, values[i]);
	}

	return combined;
}

static FuncType parse_func_name(char *func_name, Arg *arg, char *arg_value,
								char *arg_value2, char *arg_value3,
								char *arg_value4, char *arg_value5) {
	FuncType func = NULL;
	uint32_t mask = 0;
	char *values[] = {arg_value, arg_value2, arg_value3, arg_value4, arg_value5};

	*arg = (Arg){0};

	if (strcmp(func_name, "focusstack") == 0) {
		func = focusstack;
		arg->i = parse_circle_direction(arg_value);
	} else if (strcmp(func_name, "focusdir") == 0) {
		func = focusdir;
		arg->i = parse_direction(arg_value);
	} else if (strcmp(func_name, "incnmaster") == 0) {
		func = incnmaster;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "setmfact") == 0) {
		func = setmfact;
		arg->f = atof(arg_value);
	} else if (strcmp(func_name, "zoom") == 0) {
		func = zoom;
	} else if (strcmp(func_name, "exchange_client") == 0) {
		func = exchange_client;
		arg->i = parse_direction(arg_value);
	} else if (strcmp(func_name, "exchange_stack_client") == 0) {
		func = exchange_stack_client;
		arg->i = parse_circle_direction(arg_value);
	} else if (strcmp(func_name, "toggleglobal") == 0) {
		func = toggleglobal;
	} else if (strcmp(func_name, "toggleoverview") == 0) {
		func = toggleoverview;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "set_proportion") == 0) {
		func = set_proportion;
		arg->f = atof(arg_value);
	} else if (strcmp(func_name, "switch_proportion_preset") == 0) {
		func = switch_proportion_preset;
		arg->i = parse_circle_direction(arg_value);
	} else if (strcmp(func_name, "viewtoleft") == 0) {
		func = viewtoleft;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "viewtoright") == 0) {
		func = viewtoright;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "tagsilent") == 0) {
		func = tagsilent;
		arg->ui = 1 << (atoi(arg_value) - 1);
	} else if (strcmp(func_name, "tagtoleft") == 0) {
		func = tagtoleft;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "tagtoright") == 0) {
		func = tagtoright;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "killclient") == 0) {
		func = killclient;
	} else if (strcmp(func_name, "centerwin") == 0) {
		func = centerwin;
	} else if (strcmp(func_name, "focuslast") == 0) {
		func = focuslast;
	} else if (strcmp(func_name, "toggle_trackpad_enable") == 0) {
		func = toggle_trackpad_enable;
	} else if (strcmp(func_name, "setkeymode") == 0) {
		func = setkeymode;
		arg->v = strdup(arg_value);
	} else if (strcmp(func_name, "switch_keyboard_layout") == 0) {
		func = switch_keyboard_layout;
		arg->i = CLAMP_INT(atoi(arg_value), 0, 100);
	} else if (strcmp(func_name, "setlayout") == 0) {
		func = setlayout;
		arg->v = strdup(arg_value);
	} else if (strcmp(func_name, "switch_layout") == 0) {
		func = switch_layout;
	} else if (strcmp(func_name, "togglefloating") == 0) {
		func = togglefloating;
	} else if (strcmp(func_name, "togglefullscreen") == 0) {
		func = togglefullscreen;
	} else if (strcmp(func_name, "togglefakefullscreen") == 0) {
		func = togglefakefullscreen;
	} else if (strcmp(func_name, "toggleoverlay") == 0) {
		func = toggleoverlay;
	} else if (strcmp(func_name, "minimized") == 0) {
		func = minimized;
	} else if (strcmp(func_name, "restore_minimized") == 0) {
		func = restore_minimized;
	} else if (strcmp(func_name, "toggle_scratchpad") == 0) {
		func = toggle_scratchpad;
	} else if (strcmp(func_name, "toggle_render_border") == 0) {
		func = toggle_render_border;
	} else if (strcmp(func_name, "focusmon") == 0) {
		func = focusmon;
		arg->i = parse_direction(arg_value);
		if (arg->i == UNDIR)
			arg->v = strdup(arg_value);
	} else if (strcmp(func_name, "tagmon") == 0) {
		func = tagmon;
		arg->i = parse_direction(arg_value);
		arg->i2 = atoi(arg_value2);
		if (arg->i == UNDIR)
			arg->v = strdup(arg_value);
	} else if (strcmp(func_name, "incgaps") == 0) {
		func = incgaps;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "togglegaps") == 0) {
		func = togglegaps;
	} else if (strcmp(func_name, "chvt") == 0) {
		func = chvt;
		arg->ui = atoi(arg_value);
	} else if (strcmp(func_name, "spawn") == 0) {
		func = spawn;
		arg->v = combine_args_until_empty(values, 5);
	} else if (strcmp(func_name, "spawn_shell") == 0) {
		func = spawn_shell;
		arg->v = combine_args_until_empty(values, 5);
	} else if (strcmp(func_name, "spawn_on_empty") == 0) {
		func = spawn_on_empty;
		arg->v = strdup(arg_value);
		arg->ui = 1 << (atoi(arg_value2) - 1);
	} else if (strcmp(func_name, "quit") == 0) {
		func = quit;
	} else if (strcmp(func_name, "create_virtual_output") == 0) {
		func = create_virtual_output;
	} else if (strcmp(func_name, "destroy_all_virtual_output") == 0) {
		func = destroy_all_virtual_output;
	} else if (strcmp(func_name, "moveresize") == 0) {
		func = moveresize;
		arg->ui = parse_mouse_action(arg_value);
	} else if (strcmp(func_name, "togglemaximizescreen") == 0) {
		func = togglemaximizescreen;
	} else if (strcmp(func_name, "viewtoleft_have_client") == 0) {
		func = viewtoleft_have_client;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "viewtoright_have_client") == 0) {
		func = viewtoright_have_client;
		arg->i = atoi(arg_value);
	} else if (strcmp(func_name, "tag") == 0) {
		func = tag;
		arg->ui = 1 << (atoi(arg_value) - 1);
		arg->i = atoi(arg_value2);
	} else if (strcmp(func_name, "view") == 0) {
		char *token = NULL;
		char *arg_copy = strdup(arg_value);
		char *saveptr = NULL;

		func = bind_to_view;
		if (arg_copy != NULL) {
			token = strtok_r(arg_copy, "|", &saveptr);
			while (token != NULL) {
				int32_t num = atoi(token);
				if (num > 0 && num <= LENGTH(tags))
					mask |= (1 << (num - 1));
				token = strtok_r(NULL, "|", &saveptr);
			}
			free(arg_copy);
		}

		arg->ui = mask ? mask : (uint32_t)atoi(arg_value);
		arg->i = atoi(arg_value2);
	} else if (strcmp(func_name, "viewcrossmon") == 0) {
		func = viewcrossmon;
		arg->ui = 1 << (atoi(arg_value) - 1);
		arg->v = strdup(arg_value2);
	} else if (strcmp(func_name, "tagcrossmon") == 0) {
		func = tagcrossmon;
		arg->ui = 1 << (atoi(arg_value) - 1);
		arg->v = strdup(arg_value2);
	} else if (strcmp(func_name, "toggletag") == 0) {
		func = toggletag;
		arg->ui = 1 << (atoi(arg_value) - 1);
	} else if (strcmp(func_name, "toggleview") == 0) {
		func = toggleview;
		arg->ui = 1 << (atoi(arg_value) - 1);
	} else if (strcmp(func_name, "comboview") == 0) {
		func = comboview;
		arg->ui = 1 << (atoi(arg_value) - 1);
	} else if (strcmp(func_name, "smartmovewin") == 0) {
		func = smartmovewin;
		arg->i = parse_direction(arg_value);
	} else if (strcmp(func_name, "smartresizewin") == 0) {
		func = smartresizewin;
		arg->i = parse_direction(arg_value);
	} else if (strcmp(func_name, "resizewin") == 0) {
		func = resizewin;
		arg->ui = parse_num_type(arg_value);
		arg->ui2 = parse_num_type(arg_value2);
		arg->i = arg->ui == NUM_TYPE_DEFAULT ? atoi(arg_value)
											 : atoi(arg_value + 1);
		arg->i2 = arg->ui2 == NUM_TYPE_DEFAULT ? atoi(arg_value2)
											   : atoi(arg_value2 + 1);
	} else if (strcmp(func_name, "movewin") == 0) {
		func = movewin;
		arg->ui = parse_num_type(arg_value);
		arg->ui2 = parse_num_type(arg_value2);
		arg->i = arg->ui == NUM_TYPE_DEFAULT ? atoi(arg_value)
											 : atoi(arg_value + 1);
		arg->i2 = arg->ui2 == NUM_TYPE_DEFAULT ? atoi(arg_value2)
											   : atoi(arg_value2 + 1);
	} else if (strcmp(func_name, "toggle_named_scratchpad") == 0) {
		func = toggle_named_scratchpad;
		arg->v = strdup(arg_value);
		arg->v2 = strdup(arg_value2);
		arg->v3 = strdup(arg_value3);
	} else if (strcmp(func_name, "disable_monitor") == 0) {
		func = disable_monitor;
		arg->v = strdup(arg_value);
	} else if (strcmp(func_name, "enable_monitor") == 0) {
		func = enable_monitor;
		arg->v = strdup(arg_value);
	} else if (strcmp(func_name, "toggle_monitor") == 0) {
		func = toggle_monitor;
		arg->v = strdup(arg_value);
	} else if (strcmp(func_name, "scroller_stack") == 0) {
		func = scroller_stack;
		arg->i = parse_direction(arg_value);
	} else if (strcmp(func_name, "toggle_all_floating") == 0) {
		func = toggle_all_floating;
	}

	return func;
}

#endif
