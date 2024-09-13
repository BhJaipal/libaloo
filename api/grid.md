---
Name: common/grid.h
Brief: Aloo Grid related functions
---

# grid.h

## Macros

### `ALOO_GRID_TO_GTK`

| Key         | Value                              |
| ----------- | ---------------------------------- |
| body        | `GTK_GRID(x->child)`               |
| Description | Returns `GtkGrid` of `AlooWidget`. |
| Parameters  | `GtkWidget *x`                     |

## Structs

### `_alooGrid`

#### `_alooGrid::attach`

| Returns       | Description               |
| ------------- | ------------------------- |
| `AlooWidget*` | Adds widget to aloo grid. |

| Parameter Type | Description                                       |
| -------------- | ------------------------------------------------- |
| `AlooWidget*`  | grid in which child should be added               |
| `AlooWidget*`  | child to be added                                 |
| `int`          | column in which it should be added                |
| `int`          | row in which it should be added                   |
| `int`          | column span of widget or how many column it takes |
| `int`          | row span of widget or how many row it takes       |

#### `_alooGrid::attachGtk`

| Returns       | Description               |
| ------------- | ------------------------- |
| `AlooWidget*` | Adds widget to aloo grid. |

| Parameter Type | Description                                       |
| -------------- | ------------------------------------------------- |
| `AlooWidget*`  | grid in which child should be added               |
| `GtkWidget*`   | child to be added                                 |
| `int`          | column in which it should be added                |
| `int`          | row in which it should be added                   |
| `int`          | column span of widget or how many column it takes |
| `int`          | row span of widget or how many row it takes       |

#### `_alooGrid::remove`

| Returns       | Description              |
| ------------- | ------------------------ |
| `AlooWidget*` | Removes child from grid. |

| Parameter Type | Description                                      |
| -------------- | ------------------------------------------------ |
| `AlooWidget*`  | widget from which `AlooWidget` should be removed |
| `AlooWidget*`  | widget to be removed                             |

#### `_alooGrid::removeGtk`

| Returns       | Description              |
| ------------- | ------------------------ |
| `AlooWidget*` | Removes child from grid. |

| Parameter Type | Description                                     |
| -------------- | ----------------------------------------------- |
| `AlooWidget*`  | widget from which `GtkWidget` should be removed |
| `GtkWidget*`   | widget to be removed                            |

#### `_alooGrid::new`

| Returns       | Description                   |
| ------------- | ----------------------------- |
| `AlooWidget*` | Creates new Aloo Grid Widget. |

#### `_alooGrid::column_spacing`

| Returns       | Description                  |
| ------------- | ---------------------------- |
| `AlooWidget*` | Set the Grid Column Spacing. |

| Parameter Type | Description                            |
| -------------- | -------------------------------------- |
| `AlooWidget*`  | widget whose spacing has to be changed |
| `int`          | column spacing                         |

#### `_alooGrid::row_spacing`

| Returns       | Description               |
| ------------- | ------------------------- |
| `AlooWidget*` | Set the Grid Row Spacing. |

| Parameter Type | Description                            |
| -------------- | -------------------------------------- |
| `AlooWidget*`  | widget whose spacing has to be changed |
| `int`          | row spacing                            |

#### toGtk

| Returns    | Description      |
| ---------- | ---------------- |
| `GtkGrid*` | Returns Gtk Grid |

| Parameter Type | Description |
| -------------- | ----------- |
| AlooWidget*`   | Aloo Grid   |

## Variables

### Grid

| Key  | Value              |
| ---- | ------------------ |
| type | `struct _alooGrid` |
