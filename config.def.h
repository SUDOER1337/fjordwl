#ifndef FJORDWL_CONFIG_DEF_H
#define FJORDWL_CONFIG_DEF_H

#define MODKEY WLR_MODIFIER_LOGO

#define CMD(cmd) { .v = (char *)(cmd) }
#define SHCMD(cmd) CMD(cmd)

#define KEY(modmask, keyval, funcname, ...)                                   \
	{                                                                          \
		.mod = (modmask),                                                     \
		.keysymcode = {.type = KEY_TYPE_SYM, .keysym = (keyval)},             \
		.func = (funcname), .arg = __VA_ARGS__, .mode = "default",            \
		.isdefaultmode = true,                                                \
	}

#define KEYMODE(mode_name, modmask, keyval, funcname, ...)                    \
	{                                                                          \
		.mod = (modmask),                                                     \
		.keysymcode = {.type = KEY_TYPE_SYM, .keysym = (keyval)},             \
		.func = (funcname), .arg = __VA_ARGS__, .mode = (mode_name),          \
	}

#define KEYRELEASE(modmask, keyval, funcname, ...)                            \
	{                                                                          \
		.mod = (modmask),                                                     \
		.keysymcode = {.type = KEY_TYPE_SYM, .keysym = (keyval)},             \
		.func = (funcname), .arg = __VA_ARGS__, .mode = "default",            \
		.isdefaultmode = true, .isreleaseapply = true,                        \
	}

#define KEYPASS(modmask, keyval, funcname, ...)                               \
	{                                                                          \
		.mod = (modmask),                                                     \
		.keysymcode = {.type = KEY_TYPE_SYM, .keysym = (keyval)},             \
		.func = (funcname), .arg = __VA_ARGS__, .mode = "default",            \
		.isdefaultmode = true, .ispassapply = true,                           \
	}

#define KEYCOMMON(modmask, keyval, funcname, ...)                             \
	{                                                                          \
		.mod = (modmask),                                                     \
		.keysymcode = {.type = KEY_TYPE_SYM, .keysym = (keyval)},             \
		.func = (funcname), .arg = __VA_ARGS__, .mode = "common",             \
		.iscommonmode = true,                                                 \
	}

#define KEYCOMMONLOCK(modmask, keyval, funcname, ...)                         \
	{                                                                          \
		.mod = (modmask),                                                     \
		.keysymcode = {.type = KEY_TYPE_SYM, .keysym = (keyval)},             \
		.func = (funcname), .arg = __VA_ARGS__, .mode = "common",             \
		.iscommonmode = true, .islockapply = true,                            \
	}

#define BUTTON_BIND(modmask, button_name, funcname, ...)                      \
	{                                                                          \
		.mod = (modmask), .button = (button_name), .func = (funcname),        \
		.arg = __VA_ARGS__,                                                   \
	}

#define AXIS_BIND(modmask, direction, funcname, ...)                          \
	{                                                                          \
		.mod = (modmask), .dir = (direction), .func = (funcname),             \
		.arg = __VA_ARGS__,                                                   \
	}

#define GESTURE_BIND(modmask, motion_name, fingers, funcname, ...)            \
	{                                                                          \
		.mod = (modmask), .motion = (motion_name),                            \
		.fingers_count = (fingers), .func = (funcname), .arg = __VA_ARGS__,  \
	}

#define SWITCH_BIND(fold_state, funcname, ...)                                \
	{                                                                          \
		.fold = (fold_state), .func = (funcname), .arg = __VA_ARGS__,         \
	}

#define CHVT(n)                                                               \
	KEYCOMMONLOCK(WLR_MODIFIER_CTRL | WLR_MODIFIER_ALT,                       \
				  XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)})

#define TAGKEYS(keysym, tagindex)                                             \
	KEY(MODKEY, keysym, bind_to_view, {.ui = 1 << (tagindex), .i = 0}),      \
	KEY(MODKEY | WLR_MODIFIER_CTRL, keysym, toggleview,                      \
		{.ui = 1 << (tagindex)}),                                            \
	KEY(MODKEY | WLR_MODIFIER_SHIFT, keysym, tag,                            \
		{.ui = 1 << (tagindex), .i = 0}),                                    \
	KEY(MODKEY | WLR_MODIFIER_CTRL | WLR_MODIFIER_SHIFT, keysym, toggletag,  \
		{.ui = 1 << (tagindex)})

#define MONITORRULE(...)                                                      \
	{                                                                         \
		.name = NULL, .make = NULL, .model = NULL, .serial = NULL,           \
		.rr = WL_OUTPUT_TRANSFORM_NORMAL, .scale = 1.0f, .x = INT32_MAX,     \
		.y = INT32_MAX, .width = 0, .height = 0, .refresh = 0.0f, .vrr = -1, \
		.custom = -1, __VA_ARGS__                                            \
	}

#define WINRULE(...)                                                          \
	{                                                                         \
		.id = NULL, .title = NULL, .tags = 0, .isfloating = -1,              \
		.isfullscreen = -1, .isfakefullscreen = -1, .scroller_proportion = 0.0f, \
		.animation_type_open = NULL, .animation_type_close = NULL,           \
		.layer_animation_type_open = NULL,                                   \
		.layer_animation_type_close = NULL, .isnoborder = -1,                \
		.isnoradius = -1, .isnoanimation = -1,                               \
		.isopensilent = -1, .istagsilent = -1, .isnamedscratchpad = -1,      \
		.isunglobal = -1, .isglobal = -1, .isoverlay = -1,                   \
		.allow_shortcuts_inhibit = -1, .ignore_maximize = -1,                \
		.ignore_minimize = -1, .isnosizehint = -1,                           \
		.indleinhibit_when_focus = -1, .monitor = NULL, .offsetx = 0,        \
		.offsety = 0, .width = 0, .height = 0, .nofocus = -1,                \
		.nofadein = -1, .nofadeout = -1, .no_force_center = -1,              \
		.isterm = -1, .allow_csd = -1, .force_maximize = -1,                 \
		.force_tiled_state = -1, .force_tearing = -1, .noswallow = -1,       \
		.focused_opacity = 0.0f,                                              \
		.unfocused_opacity = 0.0f, .scroller_proportion_single = 0.0f,       \
		.passmod = 0, .keysym = XKB_KEY_NoSymbol, .globalkeybinding = {0},   \
		__VA_ARGS__                                                           \
	}

#define TAGRULE(...)                                                          \
	{                                                                         \
		.id = 0, .layout_name = NULL, .monitor_name = NULL,                  \
		.monitor_make = NULL, .monitor_model = NULL, .monitor_serial = NULL, \
		.mfact = 0.0f, .nmaster = 0, .no_render_border = -1,                 \
		.open_as_floating = -1, .no_hide = -1, __VA_ARGS__                   \
	}

#define LAYERRULE(...)                                                        \
	{                                                                         \
		.layer_name = NULL, .animation_type_open = NULL,                     \
		.animation_type_close = NULL, .noanim = -1, __VA_ARGS__              \
	}

static const char *tags[] = {"1", "2", "3", "4", "5", "6"};

static ConfigEnv envvars[] = {{0}};
#define ENVVARS_COUNT 0

static char *autostart[] = {
	"/usr/lib/xdg-desktop-portal-wlr &",
	//"wlsunset -l 12.7 -L 101.3 -T 6500 -t 3600",
	"qs -c ~/.config/quickshell/4guage-shell",
	"mpd",
	"mpd-mpris",
	"mmsg -s -l S",
};

static ConfigMonitorRule monitorrules[] = {
	MONITORRULE(.name = "^HDMI-A-1$", .width = 1920, .height = 1080,
				.refresh = 120.0f, .x = 0, .y = 0),
};

static ConfigTagRule tagrules[] = {{0}};
#define TAGRULES_COUNT 0

static ConfigWinRule windowrules[] = {
	WINRULE(.tags = 1 << 0, .id = "^zen-browser$"),
	WINRULE(.tags = 1 << 4, .id = "^discord$"),
	WINRULE(.tags = 1 << 5, .id = "^steam$"),
	WINRULE(.isfloating = 1, .id = "^(nemo|thunar)$"),
	WINRULE(.isfloating = 1,
			.title = "^(File Operation Progress|Properties|Event Tester)$"),
	WINRULE(.isfloating = 1, .id = "^(Gimp|gimp|org.gimp.GIMP)$"),
	WINRULE(.isterm = 1, .id = "^kitty$"),
	WINRULE(.noswallow = 1, .id = "^(spterm|spmpd)$"),
	WINRULE(.isnamedscratchpad = 1, .width = 1200, .height = 800,
			.id = "^spterm$"),
	WINRULE(.isnamedscratchpad = 1, .width = 1200, .height = 800,
			.id = "^spmpd$"),
};

static ConfigLayerRule layerrules[] = {
	LAYERRULE(.animation_type_open = "zoom", .layer_name = "rofi"),
	LAYERRULE(.animation_type_close = "zoom", .layer_name = "rofi"),
};

static float scroller_proportion_preset_values[] = {0.2f, 0.8f, 1.0f};
static char *circle_layout_names[] = {"tile", "grid", "scroller", "monocle",
									  "center_tile"};

static KeyBinding keys[] = {
	CHVT(1),
	CHVT(2),
	CHVT(3),
	CHVT(4),
	CHVT(5),
	CHVT(6),
	CHVT(7),
	CHVT(8),
	CHVT(9),
	CHVT(10),
	CHVT(11),
	CHVT(12),

	KEY(MODKEY, XKB_KEY_s, setlayout, {.v = "scroller"}),
	KEY(MODKEY, XKB_KEY_g, setlayout, {.v = "grid"}),
	KEY(MODKEY, XKB_KEY_space, switch_keyboard_layout, {0}),
	KEY(MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_l, switch_layout, {0}),

	KEY(MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_o, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/utility/utility.sh")),
	KEY(MODKEY, XKB_KEY_r, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/runner/runner.sh")),
	KEY(MODKEY, XKB_KEY_period, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/emoji/emoji.sh")),
	KEY(MODKEY, XKB_KEY_c, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/calc/calc.sh")),
	KEY(WLR_MODIFIER_CTRL | WLR_MODIFIER_ALT, XKB_KEY_Delete, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/powermenu/powermenu.sh")),
	KEY(WLR_MODIFIER_CTRL | WLR_MODIFIER_ALT, XKB_KEY_b, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/bluetooth/rofi-bluetooth")),
	KEY(WLR_MODIFIER_CTRL | WLR_MODIFIER_SHIFT, XKB_KEY_b, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/brightness/brightness.sh")),
	KEY(WLR_MODIFIER_CTRL | WLR_MODIFIER_ALT, XKB_KEY_s, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/stretchly/stretchly.sh")),
	KEY(MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_w, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/wallpaper/wallpaper.sh")),
	KEY(MODKEY, XKB_KEY_v, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/clipboard/clipboard.sh")),
	KEY(MODKEY, XKB_KEY_n, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/note/note.sh")),
	KEY(WLR_MODIFIER_ALT | WLR_MODIFIER_SHIFT, XKB_KEY_r, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/media/media.sh")),

	KEY(MODKEY, XKB_KEY_b, spawn, CMD("zen-browser")),
	KEY(MODKEY, XKB_KEY_e, spawn, CMD("nemo")),
	KEY(MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_e, spawn, CMD("thunar")),
	KEY(MODKEY, XKB_KEY_t, spawn, CMD("kitty")),
	KEY(MODKEY, XKB_KEY_o, spawn, CMD("obsidian")),

	KEY(WLR_MODIFIER_ALT, XKB_KEY_z, toggle_named_scratchpad,
		{.v = "spterm", .v2 = "none", .v3 = "kitty --class spterm"}),
	KEY(WLR_MODIFIER_ALT, XKB_KEY_r, toggle_named_scratchpad,
		{.v = "rmpc", .v2 = "none", .v3 = "kitty --class rmpc"}),

	KEY(MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_s, spawn,
		CMD("flameshot gui")),
	KEY(MODKEY, XKB_KEY_p, spawn, CMD("flameshot gui")),

	KEY(0, XKB_KEY_XF86AudioPlay, spawn, CMD("playerctl play-pause")),
	KEY(0, XKB_KEY_XF86AudioNext, spawn, CMD("playerctl next")),
	KEY(0, XKB_KEY_XF86AudioPrev, spawn, CMD("playerctl previous")),
	KEY(0, XKB_KEY_XF86AudioStop, spawn, CMD("playerctl stop")),
	KEY(0, XKB_KEY_XF86AudioRaiseVolume, spawn,
		CMD("wpctl set-volume --limit 1.0 @DEFAULT_SINK@ 1%+")),
	KEY(0, XKB_KEY_XF86AudioLowerVolume, spawn,
		CMD("wpctl set-volume @DEFAULT_SINK@ 1%-")),
	KEY(0, XKB_KEY_XF86AudioMute, spawn,
		CMD("wpctl set-mute @DEFAULT_SINK@ toggle")),

	KEY(MODKEY, XKB_KEY_f, togglefloating, {0}),
	KEY(MODKEY, XKB_KEY_j, focusstack, {.i = NEXT}),
	KEY(MODKEY, XKB_KEY_k, focusstack, {.i = PREV}),
	KEY(MODKEY, XKB_KEY_i, incnmaster, {.i = +1}),
	KEY(MODKEY, XKB_KEY_h, setmfact, {.f = -0.05f}),
	KEY(MODKEY, XKB_KEY_l, setmfact, {.f = +0.05f}),
	KEY(MODKEY, XKB_KEY_F11, togglefullscreen, {0}),
	KEY(MODKEY, XKB_KEY_Return, zoom, {0}),
	KEY(WLR_MODIFIER_ALT, XKB_KEY_Tab, spawn_shell,
		SHCMD("$HOME/fjordwl/rofi/windows/windows.sh")),
	KEY(MODKEY | WLR_MODIFIER_SHIFT, XKB_KEY_q, killclient, {0}),

	KEY(WLR_MODIFIER_CTRL | MODKEY, XKB_KEY_k, resizewin,
		{.ui = NUM_TYPE_PLUS, .i = 0, .ui2 = NUM_TYPE_MINUS, .i2 = 50}),
	KEY(WLR_MODIFIER_CTRL | MODKEY, XKB_KEY_j, resizewin,
		{.ui = NUM_TYPE_PLUS, .i = 0, .ui2 = NUM_TYPE_PLUS, .i2 = 50}),
	KEY(WLR_MODIFIER_CTRL | MODKEY, XKB_KEY_h, resizewin,
		{.ui = NUM_TYPE_MINUS, .i = 50, .ui2 = NUM_TYPE_PLUS, .i2 = 0}),
	KEY(WLR_MODIFIER_CTRL | MODKEY, XKB_KEY_l, resizewin,
		{.ui = NUM_TYPE_PLUS, .i = 50, .ui2 = NUM_TYPE_PLUS, .i2 = 0}),

	TAGKEYS(XKB_KEY_1, 0),
	TAGKEYS(XKB_KEY_2, 1),
	TAGKEYS(XKB_KEY_3, 2),
	TAGKEYS(XKB_KEY_4, 3),
	TAGKEYS(XKB_KEY_5, 4),
	TAGKEYS(XKB_KEY_6, 5),
};

static MouseBinding buttons[] = {
	BUTTON_BIND(MODKEY, BTN_LEFT, moveresize, {.i = CurMove}),
	BUTTON_BIND(MODKEY, BTN_MIDDLE, togglefloating, {0}),
	BUTTON_BIND(MODKEY, BTN_RIGHT, moveresize, {.i = CurResize}),
};

static AxisBinding axes[] = {{0}};
#define AXES_COUNT 0

static GestureBinding gestures[] = {{0}};
#define GESTURES_COUNT 0

static SwitchBinding switches[] = {{0}};
#define SWITCHES_COUNT 0

static int32_t animations = 1;
static int32_t layer_animations = 0;
static char *animation_type_open = "";
static char *animation_type_close = "";
static char *layer_animation_type_open = "";
static char *layer_animation_type_close = "";
static int32_t animation_fade_in = 1;
static int32_t animation_fade_out = 1;
static int32_t tag_animation_direction = HORIZONTAL;
static float zoom_initial_ratio = 0.3f;
static float zoom_end_ratio = 0.8f;
static float fadein_begin_opacity = 0.5f;
static float fadeout_begin_opacity = 0.5f;
static uint32_t animation_duration_move = 500;
static uint32_t animation_duration_open = 400;
static uint32_t animation_duration_tag = 300;
static uint32_t animation_duration_close = 300;
static uint32_t animation_duration_focus = 0;
static double animation_curve_move[] = {0.46, 1.0, 0.29, 0.99};
static double animation_curve_open[] = {0.46, 1.0, 0.29, 0.99};
static double animation_curve_tag[] = {0.46, 1.0, 0.29, 0.99};
static double animation_curve_close[] = {0.46, 1.0, 0.29, 0.99};
static double animation_curve_focus[] = {0.46, 1.0, 0.29, 0.99};
static double animation_curve_opafadein[] = {0.46, 1.0, 0.29, 0.99};
static double animation_curve_opafadeout[] = {0.5, 0.5, 0.5, 0.5};

static int32_t scroller_structs = 20;
static float scroller_default_proportion = 0.8f;
static float scroller_default_proportion_single = 1.0f;
static int32_t scroller_ignore_proportion_single = 1;
static int32_t scroller_focus_center = 0;
static int32_t scroller_prefer_center = 0;
static int32_t scroller_prefer_overspread = 1;
static int32_t focus_cross_monitor = 0;
static int32_t exchange_cross_monitor = 0;
static int32_t scratchpad_cross_monitor = 0;
static int32_t focus_cross_tag = 0;
static int32_t view_current_to_back = 0;
static int32_t no_border_when_single = 0;
static int32_t no_radius_when_single = 0;
static int32_t snap_distance = 30;
static int32_t enable_floating_snap = 0;
static int32_t drag_tile_to_tile = 0;
static uint32_t swipe_min_threshold = 1;
static float focused_opacity = 1.0f;
static float unfocused_opacity = 1.0f;

static uint32_t new_is_master = 1;
static float default_mfact = 0.55f;
static uint32_t default_nmaster = 1;
static int32_t center_master_overspread = 0;
static int32_t center_when_single_stack = 1;

static uint32_t hotarea_size = 10;
static uint32_t hotarea_corner = BOTTOM_LEFT;
static uint32_t enable_hotarea = 1;
static uint32_t ov_tab_mode = 0;
static int32_t overviewgappi = 5;
static int32_t overviewgappo = 30;
static uint32_t cursor_hide_timeout = 0;

static uint32_t axis_bind_apply_timeout = 100;
static uint32_t focus_on_activate = 1;
static int32_t idleinhibit_ignore_visible = 0;
static int32_t sloppyfocus = 1;
static int32_t warpcursor = 1;
static int32_t drag_corner = 3;
static int32_t drag_warp_cursor = 1;

static int32_t repeat_rate = 25;
static int32_t repeat_delay = 600;
static uint32_t numlockon = 0;
static uint32_t capslock = 0;

static char *xkb_rules_rules = NULL;
static char *xkb_rules_model = NULL;
static char *xkb_rules_layout = "us,th";
static char *xkb_rules_variant = NULL;
static char *xkb_rules_options = NULL;

static int32_t disable_trackpad = 0;
static int32_t tap_to_click = 1;
static int32_t tap_and_drag = 1;
static int32_t drag_lock = 1;
static int32_t mouse_natural_scrolling = 0;
static int32_t trackpad_natural_scrolling = 0;
static int32_t disable_while_typing = 1;
static int32_t left_handed = 0;
static int32_t middle_button_emulation = 0;
static uint32_t accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static double accel_speed = 0.0;
static uint32_t scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;
static uint32_t scroll_button = 274;
static uint32_t click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;
static uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;
static uint32_t button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;
static double axis_scroll_factor = 1.0;

static int32_t border_radius = 0;
static int32_t border_radius_location_default = CORNER_LOCATION_ALL;

static int32_t smartgaps = 0;
static uint32_t gappih = 2;
static uint32_t gappiv = 2;
static uint32_t gappoh = 10;
static uint32_t gappov = 10;
static uint32_t borderpx = 3;
static float scratchpad_width_ratio = 0.8f;
static float scratchpad_height_ratio = 0.9f;
static float rootcolor[] = {0x32 / 255.0f, 0x32 / 255.0f, 0x32 / 255.0f, 1.0f};
static float bordercolor[] = {0x44 / 255.0f, 0x44 / 255.0f, 0x44 / 255.0f,
							  1.0f};
static float focuscolor[] = {0x55 / 255.0f, 0x6c / 255.0f, 0x59 / 255.0f, 1.0f};
static float maximizescreencolor[] = {0x89 / 255.0f, 0xaa / 255.0f,
									  0x61 / 255.0f, 1.0f};
static float urgentcolor[] = {0xad / 255.0f, 0x40 / 255.0f, 0x1f / 255.0f,
							  1.0f};
static float scratchpadcolor[] = {0x51 / 255.0f, 0x6c / 255.0f, 0x93 / 255.0f,
								  1.0f};
static float globalcolor[] = {0xb1 / 255.0f, 0x53 / 255.0f, 0xa7 / 255.0f,
							  1.0f};
static float overlaycolor[] = {0x14 / 255.0f, 0xa5 / 255.0f, 0x7c / 255.0f,
							   1.0f};

static int32_t log_level = WLR_ERROR;
static char *cursor_theme = NULL;
static uint32_t cursor_size = 24;
static int32_t single_scratchpad = 1;
static int32_t xwayland_persistence = 1;
static int32_t syncobj_enable = 0;
static float drag_tile_refresh_interval = 8.0f;
static float drag_floating_refresh_interval = 8.0f;
static int32_t allow_tearing = TEARING_DISABLED;
static int32_t allow_shortcuts_inhibit = SHORTCUTS_INHIBIT_ENABLE;
static int32_t allow_lock_transparent = 0;

#endif
