---
Name: common/style.h
Brief: Aloo CSS related functions
---

# widget.h

## Functions

### `__Widget_New`

| Brief            | Returns       |
| ---------------- | ------------- |
| Create a widget. | `AlooWidget*` |

| Parameters | Type         | Brief                                     |
| ---------- | ------------ | ----------------------------------------- |
| type       | `WidgetType` | Type of new Widget                        |
| widget     | `GtkWidget*` | `GtkWidget` to be set on new `AlooWidget` |

### `__Widget_Gtk_to_Aloo`

| Brief                              | Returns       |
| ---------------------------------- | ------------- |
| Creates AlooWidget from GtkWidget. | `AlooWidget*` |

| Parameters | Type         | Brief                                        |
| ---------- | ------------ | -------------------------------------------- |
| widget     | `GtkWidget*` | Widget whose `AlooWidget` has to be obtained |

### `__Widget_Obj_to_Aloo`

| Brief                           | Returns       |
| ------------------------------- | ------------- |
| Create AlooWidget from GObject. | `AlooWidget*` |

| Parameters | Type       | Brief                                   |
| ---------- | ---------- | --------------------------------------- |
| obj        | `GObject*` | `GObject` from which has to be obtained |

### `__Widget_Obj_to_Gtk`

| Brief                           | Returns      |
| ------------------------------- | ------------ |
| Creates GtkWidget from builder. | `GtkWidget*` |

| Parameters | Type           | Brief                                   |
| ---------- | -------------- | --------------------------------------- |
| builder    | `AlooBuilder*` | Builder from which  To obtain GtkWidget |
| name       | `const char*`  | ID of UI object                         |

### `__Widget_AlooFromBuilder`

| Brief                            | Returns       |
| -------------------------------- | ------------- |
| Creates AlooWidget from builder. | `AlooWidget*` |

| Parameters | Type           | Brief                                                    |
| ---------- | -------------- | -------------------------------------------------------- |
| builder    | `AlooBuilder*` | `AlooBuilder` from which `AlooWidget` has to be obtained |
| name       | `const char*`  | ID of UI object                                          |

### `__Widget_SetOrientation`

| Brief                           | Returns       |
| ------------------------------- | ------------- |
| Sets orientation of AlooWidget. | `AlooWidget*` |

| Parameters  | Type             | Brief                                  |
| ----------- | ---------------- | -------------------------------------- |
| widget      | `AlooWidget*`    | widget whose orientation has to be set |
| orientation | `GtkOrientation` | new orientation of widget              |

### `__Widget_setName`

| Brief                   | Returns       |
| ----------------------- | ------------- |
| Set the Name of widget. | `AlooWidget*` |

| Parameters | Type          | Brief                                    |
| ---------- | ------------- | ---------------------------------------- |
| widget     | `AlooWidget*` | `AlooWidget` on which name has to be set |
| name       | `const char*` | Name to be set on `AlooWidget`           |

### `__Widget_setHorizontalAlign`

| Brief | Returns |
| Set Horizontal alignment of `AlooWIdget` | `AlooWIdget*` |

| Parameters | Type | Briefs |
| widget | `AlooWidget*` | Widget whose alignment has to be changed |
| alignment | `GtkALign` | alignment type |

### `__Widget_setVerticalAlign`

| Brief | Returns |
| Set Vertical alignment of `AlooWIdget` | `AlooWIdget*` |

| Parameters | Type | Briefs |
| widget | `AlooWidget*` | Widget whose alignment has to be changed |
| alignment | `GtkALign` | alignment type |
