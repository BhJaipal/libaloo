---
Name: common/style.h
Brief: Aloo CSS related functions
---

# widget.h

## Structs

### `_aloo_widget`

#### `_aloo_widget::new`

| Brief            | Returns       |
| ---------------- | ------------- |
| Create a widget. | `AlooWidget*` |

| Parameters | Type         | Brief                                     |
| ---------- | ------------ | ----------------------------------------- |
| type       | `WidgetType` | Type of new Widget                        |
| widget     | `GtkWidget*` | `GtkWidget` to be set on new `AlooWidget` |

#### `_aloo_widget::gtk_to_aloo`

| Brief                              | Returns       |
| ---------------------------------- | ------------- |
| Creates AlooWidget from GtkWidget. | `AlooWidget*` |

| Parameters | Type         | Brief                                        |
| ---------- | ------------ | -------------------------------------------- |
| widget     | `GtkWidget*` | Widget whose `AlooWidget` has to be obtained |

#### `_aloo_widget::obj_to_aloo`

| Brief                           | Returns       |
| ------------------------------- | ------------- |
| Create AlooWidget from GObject. | `AlooWidget*` |

| Parameters | Type       | Brief                                   |
| ---------- | ---------- | --------------------------------------- |
| obj        | `GObject*` | `GObject` from which has to be obtained |

#### `_aloo_widget::obj_to_gtk`

| Brief                           | Returns      |
| ------------------------------- | ------------ |
| Creates GtkWidget from builder. | `GtkWidget*` |

| Parameters | Type           | Brief                                   |
| ---------- | -------------- | --------------------------------------- |
| builder    | `AlooBuilder*` | Builder from which  To obtain GtkWidget |
| name       | `const char*`  | ID of UI object                         |

#### `_aloo_widget::alooFromBuilder`

| Brief                            | Returns       |
| -------------------------------- | ------------- |
| Creates AlooWidget from builder. | `AlooWidget*` |

| Parameters | Type           | Brief                                                    |
| ---------- | -------------- | -------------------------------------------------------- |
| builder    | `AlooBuilder*` | `AlooBuilder` from which `AlooWidget` has to be obtained |
| name       | `const char*`  | ID of UI object                                          |

#### `_aloo_widget::setOrientation`

| Brief                           | Returns       |
| ------------------------------- | ------------- |
| Sets orientation of AlooWidget. | `AlooWidget*` |

| Parameters  | Type             | Brief                                  |
| ----------- | ---------------- | -------------------------------------- |
| widget      | `AlooWidget*`    | widget whose orientation has to be set |
| orientation | `GtkOrientation` | new orientation of widget              |

#### `_aloo_widget::setName`

| Brief                   | Returns       |
| ----------------------- | ------------- |
| Set the Name of widget. | `AlooWidget*` |

| Parameters | Type          | Brief                                    |
| ---------- | ------------- | ---------------------------------------- |
| widget     | `AlooWidget*` | `AlooWidget` on which name has to be set |
| name       | `const char*` | Name to be set on `AlooWidget`           |

#### `_aloo_widget::horizontalAlign`

| Brief                                    | Returns       |
| ---------------------------------------- | ------------- |
| Set Horizontal alignment of `AlooWIdget` | `AlooWIdget*` |

| Parameters | Type          | Briefs                                   |
| ---------- | ------------- | ---------------------------------------- |
| widget     | `AlooWidget*` | Widget whose alignment has to be changed |
| alignment  | `GtkALign`    | alignment type                           |

#### `_aloo_widget::verticalAlign`

| Brief                                  | Returns       |
| -------------------------------------- | ------------- |
| Set Vertical alignment of `AlooWIdget` | `AlooWIdget*` |

| Parameters | Type          | Briefs                                   |
| ---------- | ------------- | ---------------------------------------- |
| widget     | `AlooWidget*` | Widget whose alignment has to be changed |
| alignment  | `GtkALign`    | alignment type                           |

#### `_alooWidget::check`

| Name     | parameter     | Brief                           |
| -------- | ------------- | ------------------------------- |
| isBox    | `AlooWidget*` | Checks if widget is Aloo Box    |
| isButton | `AlooWidget*` | Checks if widget is Aloo Button |
| isGrid   | `AlooWidget*` | Checks if widget is Aloo Grid   |
| isLabel  | `AlooWidget*` | Checks if widget is Aloo Label  |
| isInput  | `AlooWidget*` | Checks if widget is Aloo Input  |
| isWindow | `AlooWidget*` | Checks if widget is Aloo Window |

## Variables

### Widget

| Key  | Value                 |
| ---- | --------------------- |
| type | `struct _aloo_widget` |
