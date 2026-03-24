#ifndef FJORDWL_CONFIG_TYPES_H
#define FJORDWL_CONFIG_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#define CLAMP_INT(x, min, max)                                                 \
	((int32_t)(x) < (int32_t)(min)                                             \
		 ? (int32_t)(min)                                                      \
		 : ((int32_t)(x) > (int32_t)(max) ? (int32_t)(max) : (int32_t)(x)))

#define CLAMP_FLOAT(x, min, max)                                               \
	((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

enum { NUM_TYPE_MINUS, NUM_TYPE_PLUS, NUM_TYPE_DEFAULT };
enum { KEY_TYPE_CODE, KEY_TYPE_SYM };

typedef struct {
	uint32_t keycode1;
	uint32_t keycode2;
	uint32_t keycode3;
} MultiKeycode;

typedef struct {
	xkb_keysym_t keysym;
	MultiKeycode keycode;
	int32_t type;
} KeySymCode;

typedef struct {
	uint32_t mod;
	KeySymCode keysymcode;
	int32_t (*func)(const Arg *);
	Arg arg;
	char mode[28];
	bool iscommonmode;
	bool isdefaultmode;
	bool islockapply;
	bool isreleaseapply;
	bool ispassapply;
} KeyBinding;

typedef struct {
	char *type;
	char *value;
} ConfigEnv;

typedef struct {
	const char *id;
	const char *title;
	uint32_t tags;
	int32_t isfloating;
	int32_t isfullscreen;
	int32_t isfakefullscreen;
	float scroller_proportion;
	const char *animation_type_open;
	const char *animation_type_close;
	const char *layer_animation_type_open;
	const char *layer_animation_type_close;
	int32_t isnoborder;
	int32_t isnoradius;
	int32_t isnoanimation;
	int32_t isopensilent;
	int32_t istagsilent;
	int32_t isnamedscratchpad;
	int32_t isunglobal;
	int32_t isglobal;
	int32_t isoverlay;
	int32_t allow_shortcuts_inhibit;
	int32_t ignore_maximize;
	int32_t ignore_minimize;
	int32_t isnosizehint;
	int32_t indleinhibit_when_focus;
	char *monitor;
	int32_t offsetx;
	int32_t offsety;
	int32_t width;
	int32_t height;
	int32_t nofocus;
	int32_t nofadein;
	int32_t nofadeout;
	int32_t no_force_center;
	int32_t isterm;
	int32_t allow_csd;
	int32_t force_maximize;
	int32_t force_tiled_state;
	int32_t force_tearing;
	int32_t noswallow;
	float focused_opacity;
	float unfocused_opacity;
	float scroller_proportion_single;
	uint32_t passmod;
	xkb_keysym_t keysym;
	KeyBinding globalkeybinding;
} ConfigWinRule;

typedef struct {
	const char *name;
	char *make, *model, *serial;
	int32_t rr;
	float scale;
	int32_t x, y;
	int32_t width, height;
	float refresh;
	int32_t vrr;
	int32_t custom;
} ConfigMonitorRule;

typedef struct {
	uint32_t mod;
	uint32_t button;
	int32_t (*func)(const Arg *);
	Arg arg;
} MouseBinding;

typedef struct {
	uint32_t mod;
	uint32_t dir;
	int32_t (*func)(const Arg *);
	Arg arg;
} AxisBinding;

typedef struct {
	uint32_t fold;
	int32_t (*func)(const Arg *);
	Arg arg;
} SwitchBinding;

typedef struct {
	uint32_t mod;
	uint32_t motion;
	uint32_t fingers_count;
	int32_t (*func)(const Arg *);
	Arg arg;
} GestureBinding;

typedef struct {
	int32_t id;
	char *layout_name;
	char *monitor_name;
	char *monitor_make;
	char *monitor_model;
	char *monitor_serial;
	float mfact;
	int32_t nmaster;
	int32_t no_render_border;
	int32_t open_as_floating;
	int32_t no_hide;
} ConfigTagRule;

typedef struct {
	char *layer_name;
	char *animation_type_open;
	char *animation_type_close;
	int32_t noanim;
} ConfigLayerRule;

typedef struct {
	int32_t animations;
	int32_t layer_animations;
	char animation_type_open[10];
	char animation_type_close[10];
	char layer_animation_type_open[10];
	char layer_animation_type_close[10];
	int32_t animation_fade_in;
	int32_t animation_fade_out;
	int32_t tag_animation_direction;
	float zoom_initial_ratio;
	float zoom_end_ratio;
	float fadein_begin_opacity;
	float fadeout_begin_opacity;
	uint32_t animation_duration_move;
	uint32_t animation_duration_open;
	uint32_t animation_duration_tag;
	uint32_t animation_duration_close;
	uint32_t animation_duration_focus;
	double animation_curve_move[4];
	double animation_curve_open[4];
	double animation_curve_tag[4];
	double animation_curve_close[4];
	double animation_curve_focus[4];
	double animation_curve_opafadein[4];
	double animation_curve_opafadeout[4];

	int32_t scroller_structs;
	float scroller_default_proportion;
	float scroller_default_proportion_single;
	int32_t scroller_ignore_proportion_single;
	int32_t scroller_focus_center;
	int32_t scroller_prefer_center;
	int32_t scroller_prefer_overspread;
	int32_t focus_cross_monitor;
	int32_t exchange_cross_monitor;
	int32_t scratchpad_cross_monitor;
	int32_t focus_cross_tag;
	int32_t view_current_to_back;
	int32_t no_border_when_single;
	int32_t no_radius_when_single;
	int32_t snap_distance;
	int32_t enable_floating_snap;
	int32_t drag_tile_to_tile;
	uint32_t swipe_min_threshold;
	float focused_opacity;
	float unfocused_opacity;
	float *scroller_proportion_preset;
	int32_t scroller_proportion_preset_count;

	char **circle_layout;
	int32_t circle_layout_count;

	uint32_t new_is_master;
	float default_mfact;
	uint32_t default_nmaster;
	int32_t center_master_overspread;
	int32_t center_when_single_stack;

	uint32_t hotarea_size;
	uint32_t hotarea_corner;
	uint32_t enable_hotarea;
	uint32_t ov_tab_mode;
	int32_t overviewgappi;
	int32_t overviewgappo;
	uint32_t cursor_hide_timeout;

	uint32_t axis_bind_apply_timeout;
	uint32_t focus_on_activate;
	int32_t idleinhibit_ignore_visible;
	int32_t sloppyfocus;
	int32_t warpcursor;
	int32_t drag_corner;
	int32_t drag_warp_cursor;

	int32_t repeat_rate;
	int32_t repeat_delay;
	uint32_t numlockon;

	int32_t disable_trackpad;
	int32_t tap_to_click;
	int32_t tap_and_drag;
	int32_t drag_lock;
	int32_t mouse_natural_scrolling;
	int32_t trackpad_natural_scrolling;
	int32_t disable_while_typing;
	int32_t left_handed;
	int32_t middle_button_emulation;
	uint32_t accel_profile;
	double accel_speed;
	uint32_t scroll_method;
	uint32_t scroll_button;
	uint32_t click_method;
	uint32_t send_events_mode;
	uint32_t button_map;

	double axis_scroll_factor;

	int32_t border_radius;
	int32_t border_radius_location_default;
	int32_t smartgaps;
	uint32_t gappih;
	uint32_t gappiv;
	uint32_t gappoh;
	uint32_t gappov;
	uint32_t borderpx;
	float scratchpad_width_ratio;
	float scratchpad_height_ratio;
	float rootcolor[4];
	float bordercolor[4];
	float focuscolor[4];
	float maximizescreencolor[4];
	float urgentcolor[4];
	float scratchpadcolor[4];
	float globalcolor[4];
	float overlaycolor[4];

	int32_t log_level;
	uint32_t capslock;

	ConfigTagRule *tag_rules;
	int32_t tag_rules_count;

	ConfigLayerRule *layer_rules;
	int32_t layer_rules_count;

	ConfigWinRule *window_rules;
	int32_t window_rules_count;

	ConfigMonitorRule *monitor_rules;
	int32_t monitor_rules_count;

	KeyBinding *key_bindings;
	int32_t key_bindings_count;

	MouseBinding *mouse_bindings;
	int32_t mouse_bindings_count;

	AxisBinding *axis_bindings;
	int32_t axis_bindings_count;

	SwitchBinding *switch_bindings;
	int32_t switch_bindings_count;

	GestureBinding *gesture_bindings;
	int32_t gesture_bindings_count;

	ConfigEnv *env;
	int32_t env_count;

	char **startup_commands;
	int32_t startup_commands_count;

	char *cursor_theme;
	uint32_t cursor_size;

	int32_t single_scratchpad;
	int32_t xwayland_persistence;
	int32_t syncobj_enable;
	float drag_tile_refresh_interval;
	float drag_floating_refresh_interval;
	int32_t allow_tearing;
	int32_t allow_shortcuts_inhibit;
	int32_t allow_lock_transparent;

	struct xkb_rule_names xkb_rules;
} Config;

typedef int32_t (*FuncType)(const Arg *);

#endif
