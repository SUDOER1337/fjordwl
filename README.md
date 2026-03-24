# fjordwl

`fjordwl` is my personal extra lightweight fork of the Mango Wayland Compositor. The goal is to keep the workflow fast, simple, and self-contained while building out a full Wayland desktop setup around it.

This exists because I did not want to start from pure `dwl` as a base. The main direction is compile-time `config.h`, self-contained configs, and quickshell-driven pieces around the compositor.

## Current Status

This repo is meant to be more than just the compositor source. It already includes configuration, helper tooling, themes, wallpapers, and desktop assets, but the larger shell side is still incomplete while `4guage-shell` is being worked on.

## What's Included

- `fjordwl` compositor source
- compile-time `config.h` configuration
- `rofi/` scripts and themes for common desktop actions
- wallpapers and desktop assets
- project documentation under [`docs/`](docs/)

## Quick Build

For the full dependency list and manual `wlroots` / `scenefx` setup, see [Installation](docs/installation.md).

```sh
git clone https://github.com/SUDOER1337/fjordwl.git
```

## First Run

After building, edit `config.h` to match your setup, rebuild, and launch `fjordwl` from a TTY.

Some default bindings expect tools such as `kitty`, `rofi`, `playerctl`, `wpctl`, and `flameshot`. If your setup differs, update `config.h` accordingly.

For a fuller walkthrough, see [Quick Start](docs/quick-start.md).

## Credits

Thanks to [Sqooky](https://github.com/Sqooky/Maomao-with-tablet-support.git) for tablet support.

## Documentation

- [Documentation Index](docs/index.md)
- [Installation](docs/installation.md)
- [Quick Start](docs/quick-start.md)
- [Configuration](docs/configuration/index.mdx)
- [Bindings](docs/bindings/index.mdx)
- [Window Management](docs/window-management/index.mdx)
- [Visuals](docs/visuals/index.mdx)
