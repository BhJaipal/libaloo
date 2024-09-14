---
Name: common/style.h
Brief: Aloo CSS related functions
---

# style.h

## Structs

### `_alooCSS`

#### `_alooCSS::importPath`

| Returns | Description               |
| ------- | ------------------------- |
| `void`  | Import CSS file from path |

| Parameters Type | Brief            |
| --------------- | ---------------- |
| `const char*`   | path of css file |

#### `_alooCSS::importData`

| Returns | Description         |
| ------- | ------------------- |
| `void`  | content css content |

| Parameters Type | Brief          |
| --------------- | -------------- |
| `const char*`   | content        |
| `gssize`        | content length |

#### `_alooCSS::importFile`

| Returns | Description                  |
| ------- | ---------------------------- |
| `void`  | Import CSS file from content |

| Parameters Type | Brief          |
| --------------- | -------------- |
| `GFile*`        | file CSS GFile |

#### `_alooCSS::setWidth`

| Returns       | Description              |
| ------------- | ------------------------ |
| `AlooWidget*` | Set the Width of widget. |

| Parameters Type | Brief                            |
| --------------- | -------------------------------- |
| `AlooWidget*`   | widget whose width has to be set |
| `int`           | new width of widget              |

#### `_alooCSS::setHeight`

| Returns       | Description               |
| ------------- | ------------------------- |
| `AlooWidget*` | Set the Height of widget. |

| Parameters Type | Brief                             |
| --------------- | --------------------------------- |
| `AlooWidget*`   | widget whose height has to be set |
| `int`           | new height of widget              |

#### `_alooCSS::setSize`

| Returns       | Description                         |
| ------------- | ----------------------------------- |
| `AlooWidget*` | Set the Width and Height of widget. |

| Parameters Type | Brief                                     |
| --------------- | ----------------------------------------- |
| `AlooWidget*`   | widget whose width & height has to be set |
| `int`           | new width of widget                       |
| `int`           | new height of widget                      |

#### `_alooCSS::addClass`

| Returns       | Description           |
| ------------- | --------------------- |
| `AlooWidget*` | Adds class to widget. |

| Parameters Type | Brief                                 |
| --------------- | ------------------------------------- |
| `AlooWidget*`   | widget in which class has to be added |
| `char*`         | class name                            |

#### `removeClass`

| Returns       | Description                |
| ------------- | -------------------------- |
| `AlooWidget*` | Removes class from widget. |

| Parameters Type | Brief                                     |
| --------------- | ----------------------------------------- |
| `AlooWidget*`   | widget from which class has to be removed |
| `char*`         | class name                                |

#### `_alooCSS::getClasses`

| Returns  | Description             |
| -------- | ----------------------- |
| `char**` | Gets classes of widget. |

| Parameters Type | Brief                                |
| --------------- | ------------------------------------ |
| `AlooWidget*`   | widget whose classes you want to get |

#### `_alooCSS::setClasses`

| Returns       | Description             |
| ------------- | ----------------------- |
| `AlooWidget*` | Sets classes of widget. |

| Parameters Type | Brief                              |
| --------------- | ---------------------------------- |
| `AlooWidget*`   | widget whose classes has to be set |
| `char**`        | list of classes                    |

## Variables

### CSS

| Key  | Value             |
| ---- | ----------------- |
| type | `struct _alooCSS` |
