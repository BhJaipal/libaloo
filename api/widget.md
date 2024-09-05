# widget.h

## Functions

### `GTK_TO_ALOO`

- **Resturns**: `AlooWidget *`
- **Description**: Creates AlooWidget from GtkWidget.
- **Parameters**:
- - `GtkWidget *widget`

### `OBJECT_TO_ALOO`

- **Resturns**: `AlooWidget *`
- **Description**: Create AlooWidget from GObject.
- **Parameters**:
- - `GObject *obj`

### `OBJECT_TO_GTK_WIDGET`

- **Resturns**: `GtkWidget *`
- **Description**: Creates GtkWidget from builder.
- **Parameters**:
- - `AlooBuilder *builder`
- - `const char *name`

### `AlooWidgetFromBuilder`

- **Resturns**: `AlooWidget *`
- **Description**: Creates AlooWidget from builder.
- **Parameters**:
- - `AlooBuilder *builder`
- - `const char *name`

### `alooSetOrientation`

- **Resturns**: `AlooWidget *`
- **Description**: Sets orientation of AlooWidget.
- **Parameters**:
- - `AlooWidget *widget`
- - `GtkOrientation orien`

### `NewWidget`

- **Resturns**: `AlooWidget *`
- **Description**: Create a widget.
- **Parameters**:
- - `WidgetType type`
- - `GtkWidget *child`

### `setWidgetName`

- **Resturns**: `AlooWidget *`
- **Description**: Set the Name of widget.
- **Parameters**:
- - `AlooWidget *widget`
- - `const char *name`
