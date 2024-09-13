---
Name: common/button.h
Brief: Aloo Button related functions
---

# button.h

## Structs

### `_alooButton`

#### `alooButon::new`

| Returns       | Brief                                 |
| ------------- | ------------------------------------- |
| `AlooWidget*` | Creates new Aloo Button without label |

#### `alooButon::newWithLabel`

| Returns       | Brief                              |
| ------------- | ---------------------------------- |
| `AlooWidget*` | Creates new Aloo Button with label |

| Parameters Type | Brief               |
| --------------- | ------------------- |
| `const char*`   | label of new button |

#### `alooButon::label`

| Returns       | Brief                        |
| ------------- | ---------------------------- |
| `AlooWidget*` | Sets the label of the button |

| Parameters Type | Brief               |
| --------------- | ------------------- |
| `AlooWidget*`   | Aloo Buton          |
| `const char*`   | new label of button |

#### `alooButon::child`

| Returns       | Brief                        |
| ------------- | ---------------------------- |
| `AlooWidget*` | Sets the child of the button |

| Parameters Type | Brief                |
| --------------- | -------------------- |
| `AlooWidget*`   | Aloo Buton           |
| `AlooWidget*`   | Child of Aloo Button |

#### `alooButon::icon`

| Returns       | Brief                       |
| ------------- | --------------------------- |
| `AlooWidget*` | Sets the icon of the button |

| Parameters Type | Brief               |
| --------------- | ------------------- |
| `AlooWidget*`   | Aloo Button         |
| `const char*`   | Icon of Aloo Button |

#### `alooButon::useUnderline`

| Returns       | Brief                                              |
| ------------- | -------------------------------------------------- |
| `AlooWidget*` | Sets whether to use underline or not in the button |

| Parameters Type | Brief                          |
| --------------- | ------------------------------ |
| `AlooWidget*`   | Aloo Button                    |
| `int`           | wheher to use underline or not |

#### `alooButon::toGtk`

| Returns      | Brief                              |
| ------------ | ---------------------------------- |
| `GtkButton*` | Converts Aloo Button to Gtk Button |

| Parameters Type | Brief                                |
| --------------- | ------------------------------------ |
| `AlooWidget*`   | Widget to be convered to Aloo Button |

## Variables

### Button

| Key  | Value                |
| ---- | -------------------- |
| type | `struct _alooButton` |
