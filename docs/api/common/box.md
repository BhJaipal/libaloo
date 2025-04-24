---
Name: common/button.h
Brief: Aloo Button related functions
---

# box.h

## Structs

### `_alooBox`

#### `_alooBox::new`

| Returns       | Brief                |
| ------------- | -------------------- |
| `AlooWidget*` | Creates new ALoo Box |

| Parameters Type  | Brief                   |
| ---------------- | ----------------------- |
| `GtkOrientation` | box default orientation |
| `int`            | box default spacing     |

#### `_alooBox::setOrientation`

| Returns       | Brief                 |
| ------------- | --------------------- |
| `AlooWidget*` | Sets Box Orientation. |

| Parameters Type  | Brief |
| ---------------- | ----- |
| `AlooWidget*`    |       |
| `GtkOrientation` |       |

#### `_alooBox::getOrientation`

| Returns              | Brief                 |
| -------------------- | --------------------- |
| `**: GtkOrientation` | Gets Box Orientation. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |

#### `_alooBox::appendGtk`

| Returns       | Brief                           |
| ------------- | ------------------------------- |
| `AlooWidget*` | Appends GtkWidget child to box. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `GtkWidget*`    |       |

#### `_alooBox::prependGtk`

| Returns       | Brief                            |
| ------------- | -------------------------------- |
| `AlooWidget*` | Prepends GtkWidget child to box. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `GtkWidget*`    |       |

#### `_alooBox::removeGtk`

| Returns       | Brief                             |
| ------------- | --------------------------------- |
| `AlooWidget*` | Removes GtkWidget child from box. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `GtkWidget*`    |       |

#### `_alooBox::append`

| Returns       | Brief                            |
| ------------- | -------------------------------- |
| `AlooWidget*` | Appends AlooWidget child to box. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `AlooWidget*`   |       |

#### `_alooBox::prepend`

| Returns       | Brief                             |
| ------------- | --------------------------------- |
| `AlooWidget*` | Prepends AlooWidget child to box. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `AlooWidget*`   |       |

#### `_alooBox::remove`

| Returns       | Brief                              |
| ------------- | ---------------------------------- |
| `AlooWidget ` | Removes AlooWidget child from box. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `AlooWidget*`   |       |

#### `_alooBox::insertChildAfter`

| Returns       | Brief                                     |
| ------------- | ----------------------------------------- |
| `AlooWidget*` | Adds child after a certain widget of box. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `AlooWidget*`   |       |
| `AlooWidget*`   |       |

#### `_alooBox::setSpacing`

| Returns       | Brief            |
| ------------- | ---------------- |
| `AlooWidget*` | Set Box Spacing. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `int`           |       |

#### `_alooBox::getSpacing`

| Returns | Brief             |
| ------- | ----------------- |
| `int`   | Gets box spacing. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |

#### `_alooBox::getHomogeneous`

| Returns    | Brief                 |
| ---------- | --------------------- |
| `gboolean` | Gets box homogeneous. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |

#### `_alooBox::setHomogeneous`

| Returns       | Brief                 |
| ------------- | --------------------- |
| `AlooWidget*` | Sets box homogeneous. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |
| `gboolean`      |       |

#### `_alooBox::getBaselinePosition`

| Returns               | Brief                       |
| --------------------- | --------------------------- |
| `GtkBaselinePosition` | Gets Box baseline position. |

| Parameters Type | Brief |
| --------------- | ----- |
| `AlooWidget*`   |       |

#### `_alooBox::setBaselinePosition`

| Returns       | Brief                       |
| ------------- | --------------------------- |
| `AlooWidget*` | Sets Box baseline position. |

| Parameters Type       | Brief |
| --------------------- | ----- |
| `AlooWidget*`         |       |
| `GtkBaselinePosition` |       |

## Variables

### Box

| Key  | Value             |
| ---- | ----------------- |
| type | `struct _alooBox` |
