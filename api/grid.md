# grid.h

## Macros

### `ALOO_GRID_TO_GTK(x)`

- **body**: `GTK_GRID(x->child)`
- **Description**: Returns GtkGrid of AlooWidget.
- **Parameters**: `GtkWidget *x`

## Functions

### `gridAttach`

- **Returns**: `AlooWidget *`
- **Description**: Adds widget to aloo grid.
- **Parameters**:
- - `AlooWidget *grid`
- - `AlooWidget *child`
- - `int column`
- - `int row`
- - `int width`
- - `int height`

### `gridAttachGtk`

- **Returns**: `AlooWidget *`
- **Description**: Adds widget to aloo grid.
- **Parameters**:
- - `AlooWidget *grid`
- - `GtkWidget *child`
- - `int column`
- - `int row`
- - `int width`
- - `int height`

### `gridRemove`

- **Returns**: `AlooWidget *`
- **Description**: Removes child from grid.
- **Parameters**:
- - `AlooWidget *grid`
- - `AlooWidget *child`

### `gridRemoveGtk`

- **Returns**: `AlooWidget *`
- **Description**: Removes child from grid.
- **Parameters**:
- - `AlooWidget *grid`
- - `GtkWidget *child`

### `alooGridNew`

- **Returns**: `AlooWidget *`
- **Description**: Creates new Aloo Grid Widget.
- **No Parameters**

### `setGridColumnSpacing`

- **Returns**: `AlooWidget *`
- **Description**: Set the Grid Column Spacing.
- **Parameters**:
- - `AlooWidget *grid`
- - `int space`

### `setGridRowSpacing`

- **Returns**: `AlooWidget *`
- **Description**: Set the Grid Row Spacing.
- **Parameters**
- - `AlooWidget *grid`
- - `int space`
