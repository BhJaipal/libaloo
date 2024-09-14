---
Name: common/app.h
Brief: Aloo Application related functions
---

# app.h

## Enumrations

### `alooAppFlags`

**Description**: G Application Flags

| Values                  | Brief                                            |
| ----------------------- | ------------------------------------------------ |
| `APP_FLAGS_NONE`        | corresponds to `G_APPLICATION_FLAGS_NONE`        |
| `APP_FLAGS_IS_LAUNCHER` | corresponds to `G_APPLICATION_FLAGS_IS_LAUNCHER` |
| `APP_FLAGS_IS_SERVICE`  | corresponds to `G_APPLICATION_FLAGS_IS_SERVICE`  |

## Struct

### AlooApplication

**Description**: Returns GtkApplication and status.

| Members | Types             | Brief                       |
| ------- | ----------------- | --------------------------- |
| app     | `GtkApplication*` | Actual Gtk Application      |
| status  | `int`             | status on app exit          |
| argc    | `int`             | command line argument count |
| argv    | `char**`          | command line arguments      |

### AlooAppOptions

**Description**: Takes GApplicationFlags, argc and argv.

| Members  | Types               | Brief                       |
| -------- | ------------------- | --------------------------- |
| appFlags | `enum alooAppFlags` | Application Flags           |
| appFlags | `int`               | command line argument count |
| appFlags | `char**`            | command line arguments      |

### `_alooApp`

#### `_alooApp::create`

| Returns                 | Brief                |
| ----------------------- | -------------------- |
| `struct alooApp_Status` | Create a App object. |

| Parameters Type         | Brief                                          |
| ----------------------- | ---------------------------------------------- |
| `const char*`           | App Id are like com.google.Chrome, dev.zed.Zed |
| `struct AlooAppOptions` | It takes GApplicationFlags, argc and argv      |

#### `_alooApp::add_event_listener`

| Returns       | Brief                                    |
| ------------- | ---------------------------------------- |
| `AlooWidget*` | Sets horizontal alignment of AlooWidget. |

| Parameters Type    | Brief                                               |
| ------------------ | --------------------------------------------------- |
| `AlooApplication*` | App on which event listener has to be added         |
| `const char*`      | event name                                          |
| `void()`           | callback                                   function |

#### `_alooApp::run`

**Description**: Runs aloo App

| Parameter Type     | Description               |
| ------------------ | ------------------------- |
| `AlooApplication*` | Aloo aplication to be run |

#### `_alooApp::run_and_unref`

**Description**: Runs aloo App and unrefs after exiting it

| Parameter Type     | Description                         |
| ------------------ | ----------------------------------- |
| `AlooApplication*` | Aloo aplication to be run and unref |

#### `_alooApp::unref`

**Description**: unrefs aloo App

| Parameter Type     | Description                 |
| ------------------ | --------------------------- |
| `AlooApplication*` | Aloo aplication to be unref |

## Variables

### Application

| Key  | Value             |
| ---- | ----------------- |
| type | `struct _alooApp` |
