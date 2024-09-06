---
Name: common/style.h
Brief: Aloo CSS related functions
---

# style.h

## Functions

### importCssFromPath

- **Returns**: `void`
- **Description**: Import CSS file from path
- **Parameters**:
- - `const char *name`: name path of css file

### importCssFromData

- **Returns**: `void`
- **Description**: content css content
- **Parameters**:
- - `const char *content`: content
- - `gssize length`: content length

### importCssFromFile

- **Returns**: `void`
- **Description**: Import CSS file from content
- **Parameters**:
- - `GFile *file`: file CSS GFile

### `setWidth`

- **Returns**: AlooWidget *
- **Description**: Set the Width of widget.
- **Parameters**:
- - `AlooWidget *wid`
- - `int width`

### `setHeight`

- **Returns**: AlooWidget *
- **Description**: Set the Height of widget.
- **Parameters**:
- - `AlooWidget *wid`
- - `int height`

### `setSize`

- **Returns**: AlooWidget *
- **Description**: Set the Width and Height of widget.
- **Parameters**:
- - `AlooWidget *wid`
- - `int width`
- - `int height`

### `widgetAddClass`

- **Returns**: AlooWidget *
- **Description**: Adds class to widget.
- **Parameters**:
- - `AlooWidget *widget`
- - `char *class`

### `widgetRemoveClass`

- **Returns**: AlooWidget *
- **Description**: Removes class from widget.
- **Parameters**:
- - `AlooWidget *widget`
- - `char *class`

### `getWidgetClasses`

- **Returns**: char **
- **Description**: Gets \classes of widget.
- **Parameters**:
- - `AlooWidget *widget`

### `setWidgetClasses`

- **Returns**: AlooWidget *
- **Description**: Sets classes of widget.
- **Parameters**:
- - `AlooWidget *widget`
- - `char **classes`
