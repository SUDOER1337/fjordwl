## Building from Source

> **Info:** Ensure the following dependencies are installed before proceeding:
> - `wayland`
> - `wayland-protocols`
> - `libinput`
> - `libdrm`
> - `libxkbcommon`
> - `pixman`
> - `libdisplay-info`
> - `libliftoff`
> - `hwdata`
> - `seatd`
> - `pcre2`
> - `xorg-xwayland`
> - `libxcb`

You will need to build `wlroots` and `scenefx` manually as well.

1. **Build wlroots**
   Clone and install the specific version required (check README for latest version).
   ```bash
   git clone -b 0.19.2 https://gitlab.freedesktop.org/wlroots/wlroots.git
   cd wlroots
   meson build -Dprefix=/usr
   sudo ninja -C build install
   ```

2. **Build scenefx**
   This library handles the visual effects.
   ```bash
   git clone -b 0.4.1 https://github.com/wlrfx/scenefx.git
   cd scenefx
   meson build -Dprefix=/usr
   sudo ninja -C build install
   ```

3. **Build fjordwl**
   Finally, compile the compositor itself.
   ```bash
   git clone https://github.com/fjordwl/fjordwl.git
   cd fjordwl
   meson build -Dprefix=/usr
   sudo ninja -C build install
   ```
