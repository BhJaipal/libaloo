---
Name: common/macros.h
Brief: It contains Macros of Aloo Project
---

# macros.h

## Macros

### ALOO_GRID_TO_GTK

| Body | Brief | Returns |
|-|-|-|
| `GTK_GRID(x->child)` | Returns `GTK_GRID` of Aloo Widget  | `GTK_GRID` |

| Parameters | Type | Description |
|-|-|-|
| widget | `AlooWidget*` | `AlooWidget` with `ALOO_GRID` type |

### NONE_FLAGS_OPTIONS

| Returns | Brief | Body |
|-|-|-|
| `AlooAppOptions` | generates app options with `APP_FLAGS_NONE` | `{ APP_FLAGS_NONE, argc, argv }` |

| Parameters | Type | Brief |
|-|-|-|
| argc | `int` | No of arguments |
| argv | `char**` | Arguments |

### LAUNCHER_FLAGS_OPTIONS

| Returns | Brief | Body |
|-|-|-|
| `AlooAppOptions` | generates app options with `APP_FLAGS_IS_LAUNCHER` | `{ APP_FLAGS_IS_LAUNCHER, argc, argv }` |

| Parameters | Type | Brief |
|-|-|-|
| argc | `int` | No of arguments |
| argv | `char**` | Arguments |

### SERVICE_FLAGS_OPTIONS

| Returns | Brief | Body |
|-|-|-|
| `AlooAppOptions` | generates app options with `APP_FLAGS_IS_SERVICE` | `{ APP_FLAGS_IS_SERVICE, argc, argv }` |

| Parameters | Type | Brief |
|-|-|-|
| argc | `int` | No of arguments |
| argv | `char**` | Arguments |
