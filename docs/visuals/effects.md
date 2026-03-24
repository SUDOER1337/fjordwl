---
title: Window Effects
description: Configure corner radius and opacity.
---

## Opacity & Corner Radius

Control the transparency and roundness of your windows.

| Setting | Default | Description |
| :--- | :--- | :--- |
| `border_radius` | `0` | Window corner radius in pixels. |
| `border_radius_location_default` | `0` | Corner radius location: `0` (all), `1` (top-left), `2` (top-right), `3` (bottom-left), `4` (bottom-right), `5` (closest corner). |
| `no_radius_when_single` | `0` | Disable radius if only one window is visible. |
| `focused_opacity` | `1.0` | Opacity for the active window (0.0 - 1.0). |
| `unfocused_opacity` | `1.0` | Opacity for inactive windows (0.0 - 1.0). |

```ini
# Window corner radius in pixels
border_radius=0

# Corner radius location (0=all, 1=top-left, 2=top-right, 3=bottom-left, 4=bottom-right)
border_radius_location_default=0

# Disable radius if only one window is visible
no_radius_when_single=0

# Opacity for the active window (0.0 - 1.0)
focused_opacity=1.0

# Opacity for inactive windows
unfocused_opacity=1.0
```
