---
name: Bug report
about: Something in fjordwl isn't working correctly
title: ""
labels: "A: bug"
assignees: ""
---

## Info

<!--Paste fjordwl version from running "fjordwl -v"-->
<!--
Wlroots library needs to be built from this repository to avoid crashes
https://github.com/DreamMaoMao/wlroots.git
-->

fjordwl version:
wlroots version:

## Crash track
1.you need to build fjordwl by enable asan flag.
```bash
meson build -Dprefix=/usr -Dasan=true
``
2.run fjordwl in tty.
```bash
export ASAN_OPTIONS="detect_leaks=1:halt_on_error=0:log_path=/home/xxx/asan.log"
fjordwl

```

3.after fjordwl crash,paste the log file `/home/xxx/asan.log` here.

## Description

<!--
Only report bugs that can be reproduced on the main line
-->
