# box.h

## Macros

### `ALOO_BOX_TO_GTK_BOX(x)`

- **body**: GTK_BOX(ALOO_BOX_WIDGET(x))
- **Description**: Return GtkBox of widget
- **Parameters**: `AlooWidget *x`

## Functions

### `ALOO_BOX_WIDGET`

- **Returns**: `GtkWidget *`
- **Parameters**:
- - `AlooWidget *x`

### `ALOO_IS_BOX`

- **Returns**: `gboolean`
- **Parameters**:
- - `AlooWidget *x`

### `newAlooBox`

- **Returns**: `AlooWidget *`
- **Parameters**:
- - `GtkOrientation orientation`
- - `int spacing`

### `setBoxOrientation`

- **Returns**: `AlooWidget *`
- **Description**: Sets Box Orientation.
- **Parameters**:
- - `AlooWidget *box`
- - `GtkOrientation orientation`

### `getBoxOrientation`

- **Returns`**: GtkOrientation`
- **Description**: Gets Box Orientation.
- **Parameters**:
- - `AlooWidget *box`

### `boxAppendGtk`

- **Returns**: `AlooWidget *`
- **Description**: Appends GtkWidget child to box.
- **Parameters**:
- - `AlooWidget *box`
- - `GtkWidget *widget`

### `boxPrependGtk`

- **Returns**: `AlooWidget *`
- **Description**: Prepends GtkWidget child to box.
- **Parameters**:
- - `AlooWidget *box`
- - `GtkWidget *widget`

### `boxRemoveGtk`

- **Returns**: `AlooWidget *`
- **Description**: Removes GtkWidget child from box.
- **Parameters**:
- - `AlooWidget *box`
- - `GtkWidget *widget`

### `boxAppend`

- **Returns**: `AlooWidget *`
- **Description**: Appends AlooWidget child to box.
- **Parameters**:
- - `AlooWidget *box`
- - `AlooWidget *widget`

### `boxPrepend`

- **Returns**: `AlooWidget *`
- **Description**: Prepends AlooWidget child to box.
- **Parameters**:
- - `AlooWidget *box`
- - `AlooWidget *widget`

### `boxRemove`

- **Returns**: `AlooWidget *`
- **Description**: Removes AlooWidget child from box.
- **Parameters**:
- - `AlooWidget *box`
- - `AlooWidget *widget`

### `boxInsertChildAfter`

- **Returns**: `AlooWidget *`
- **Description**: Adds child after a certain widget of box.
- **Parameters**:
- - `AlooWidget *box`
- - `AlooWidget *child`
- - `AlooWidget *after`

### `setBoxSpacing`

- **Returns**: `AlooWidget *`
- **Description**: Set Box Spacing.
- **Parameters**:
- - `AlooWidget *box`
- - `int spacing`

### `getBoxSpacing`

- **Returns**: `int`
- **Description**: Gets box spacing.
- **Parameters**:
- - `AlooWidget *box`

### `getBoxHomogeneous`

- **Returns**: `gboolean`
- **Description**: Gets box homogeneous.
- **Parameters**:
- - `AlooWidget *box`

### `setBoxHomogeneous`

- **Returns**: `AlooWidget *`
- **Description**: Sets box homogeneous.
- **Parameters**:
- - `AlooWidget *box`
- - `gboolean homogeneous`

### `getBoxBaselinePosition`

- **Returns**: `GtkBaselinePosition`
- **Description**: Gets Box baseline position.
- **Parameters**:
- - `AlooWidget *box`

### `setBoxBaselinePosition`

- **Returns**: `AlooWidget *`
- **Description**: Sets Box baseline position.
- **Parameters**:
- - `AlooWidget *box`
- - `GtkBaselinePosition position`
