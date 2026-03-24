## Building from Source

> **Info:** Package names vary by distro, but you will need these tools and libraries available to build `fjordwl`.
>
> Build tools:
> - `git`
> - `meson`
> - `ninja`
> - `pkg-config`
> - a C/C++ toolchain such as `gcc`/`g++`
>
> Runtime/build dependencies:
> - `wayland-server`
> - `wayland-client`
> - `wayland-protocols`
> - `libinput` `>= 1.27.1`
> - `libxkbcommon`
> - `libpcre2-8`
> - `xcb`
> - `xcb-icccm`
> - `wlroots-0.19` `>= 0.19.0`
> - `scenefx-0.4` `>= 0.4.1`
>
> You may also need common wlroots support libraries provided by your distro, such as `libdrm`, `pixman`, `libdisplay-info`, `libliftoff`, `seatd`, `hwdata`, and `xorg-xwayland`.

If your distro does not provide compatible `wlroots` and `scenefx` packages, build them manually first.

1. **Build wlroots**
   Any `0.19.x` release that satisfies `wlroots-0.19 >= 0.19.0` should work.
   ```bash
   git clone -b 0.19.3 https://gitlab.freedesktop.org/wlroots/wlroots.git
   cd wlroots
   meson setup build -Dprefix=/usr
   meson compile -C build
   sudo meson install -C build
   ```

2. **Build scenefx**
   This library handles visual effects used by `fjordwl`.
   ```bash
   git clone -b 0.4.1 https://github.com/wlrfx/scenefx.git
   cd scenefx
   meson setup build -Dprefix=/usr
   meson compile -C build
   sudo meson install -C build
   ```

3. **Build fjordwl**
   ```bash
   git clone https://github.com/SUDOER1337/fjordwl.git
   cd fjordwl
   meson setup build -Dprefix=/usr
   meson compile -C build
   sudo meson install -C build
   ```

If you already have an old `build/` directory and the build behaves strangely, remove it or use a fresh directory name such as `build-local` before running `meson setup` again.
