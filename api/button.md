# button.h

## Macros

### `ALOO_BTN_TO_GTK(x)`

- **body**: `GTK_BUTTON(x->child)`
- **Description**: Returns GtkButton of widget
- **Parameters**: `AlooWidget *x`

## Function

### `newButton`

- **Returns**: `AlooWidget*`
- **Description**: Creates an aloo button
- **No Parameters**

### `newButtonWithLabel`

- **Returns**: `AlooWidget*`
- **Description**: Creates an aloo button with a label
- **Parameters**:
- - `const char * label`
