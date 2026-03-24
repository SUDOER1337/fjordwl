---
title: Basic Configuration
description: Learn how to configure fjordwl with compile-time `config.h`, environment variables, and autostart commands.
---

## Compile-Time Config

fjordwl now reads configuration from the project-root `config.h`, similar to `dwl` and `dwm`.

1. Edit `config.h`.
2. Rebuild the compositor.
3. Restart fjordwl to pick up the new config.

```bash
$EDITOR config.h
meson setup build
ninja -C build
```

`config.def.h` is provided as the tracked template; `config.h` is the active build config.

## Environment Variables

You can define environment variables directly in the `envvars[]` array in `config.h`.

```c
static ConfigEnv envvars[] = {
	{ .type = "QT_IM_MODULES", .value = "wayland;fcitx" },
	{ .type = "XMODIFIERS", .value = "@im=fcitx" },
};
```

## Autostart

fjordwl can automatically run commands or scripts at startup from the `autostart[]` array in `config.h`.

### Example Setup

```c
static char *autostart[] = {
	"waybar",
	"swaybg -i ~/.config/fjordwl/wallpaper/room.png",
};
```
