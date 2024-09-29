---
Name: common/window.h
Brief: Aloo Window related functions
---

# window.h

## Structs

### _alooWindow

#### `_alooWindow::new`

| Returns       | Brief              |
| ------------- | ------------------ |
| `AlooWidget*` | Create a GtkWindow |

| Parameter Type     | Brief    |
| ------------------ | -------- |
| `AlooApplication*` | Aloo App |

#### `_alooWindow::present`

| Returns       | Brief                |
| ------------- | -------------------- |
| `AlooWidget*` | Presents Aloo Window |

| Parameter Type | Brief  |
| -------------- | ------ |
| `AlooWidget*`  | window |

#### `_alooWindow::setChild`

| Returns       | Brief             |
| ------------- | ----------------- |
| `AlooWidget*` | Sets Window child |

| Parameter Type | Brief            |
| -------------- | ---------------- |
| `AlooWidget*`  | window           |
| `AlooWidget*`  | child for window |

#### `_alooWindow::setTitle`

| Returns       | Brief                |
| ------------- | -------------------- |
| `AlooWidget*` | Sets GtkWindow title |

| Parameter Type | Brief           |
| -------------- | --------------- |
| `AlooWidget*`  | window          |
| `const char*`  | title of window |

#### `_alooWindow::setSize`

| Returns       | Brief                           |
| ------------- | ------------------------------- |
| `AlooWidget*` | Sets aloo Window width & height |

| Parameter Type | Brief           |
| -------------- | --------------- |
| `AlooWidge*`   | window          |
| `int`          | width of window |
| `int`          | width of window |

#### `_alooWindow::getSize`

| Returns       | Brief                           |
| ------------- | ------------------------------- |
| `AlooWidget*` | Gets aloo Window width & height |

| Parameter Type | Brief            |
| -------------- | ---------------- |
| `AlooWidget*`  | window           |
| `int`          | width of window  |
| `int`          | height of window |

#### `_alooWindow::set_app_window`

| Returns       | Brief                         |
| ------------- | ----------------------------- |
| `AlooWidget*` | Set the Window of Application |

| Parameter Type     | Brief    |
| ------------------ | -------- |
| `AlooWidget*`      | window   |
| `AlooApplication*` | Aloo App |

#### `_alooWindow::app_add_window`

| Returns       | Brief                      |
| ------------- | -------------------------- |
| `AlooWidget*` | Adds Window to Application |

| Parameter Type     | Brief    |
| ------------------ | -------- |
| `AlooApplication*` | Aloo App |
| `AlooWidget*`      | window   |

#### `_alooWindow::toGtk`

| Returns      | Brief                                 |
| ------------ | ------------------------------------- |
| `GtkWindow*` | Returns Gtk Window of the Aloo Window |

| Parameter Type | Brief  |
| -------------- | ------ |
| `AlooWidget*`  | window |

#### `_alooWindow::show`

| Returns | Brief        |
| ------- | ------------ |
| `void`  | Shows Window |

| Parameter Type | Brief  |
| -------------- | ------ |
| `AlooWidget*`  | window |

## Variables

### Window

| Key  | Value                |
| ---- | -------------------- |
| type | `struct _alooWindow` |
