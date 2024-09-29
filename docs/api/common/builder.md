---
Name: common/builder.h
Brief: Aloo Builder related functions
---

# Builder.h

## Structs

### `_AlooBuilder`

#### `_AlooBuilder::unref`

| Returns | Brief               |
| ------- | ------------------- |
| `void`  | Unrefs aloo builder |

| Parameter Type | Description         |
| -------------- | ------------------- |
| `AlooBuilder*` | Builder to be unref |

#### `_AlooBuilder::create`

| Returns        | Brief                   |
| -------------- | ----------------------- |
| `AlooBuilder*` | Create a Builder object |

#### `_AlooBuilder::addFile`

| Returns | Brief                    |
| ------- | ------------------------ |
| `int`   | Adds a file with builder |

| Parameter Type | Description                                                |
| -------------- | ---------------------------------------------------------- |
| `AlooBuilder*` | AlooBuilder object                                         |
| `const char*`  | UI file path with name                                     |
| `GError**`     | Error handler, Default `NULL` __builderAddFileType addFile |

#### `_AlooBuilder::addContent`

| Returns | Brief                    |
| ------- | ------------------------ |
| `int`   | Adds a file with builder |

| Parameter Type | Description                                                      |
| -------------- | ---------------------------------------------------------------- |
| `AlooBuilder*` | AlooBuilder object                                               |
| `const char*`  | UI data                                                          |
| `gssize`       | UI data length                                                   |
| `GError**`     | Error handler, Default `NULL` __builderAddContentType addContent |

#### `_AlooBuilder::addResource`

| Returns | Brief                    |
| ------- | ------------------------ |
| `int`   | Adds a file with builder |

| Parameter Type | Description                   |
| -------------- | ----------------------------- |
| `AlooBuilder*` | AlooBuilder object            |
| `const char*`  | UI resource path              |
| `GError**`     | Error handler, Default `NULL` |

#### `_AlooBuilder::getBuilderObject`

| Returns    | Brief                     |
| ---------- | ------------------------- |
| `GObject*` | Gets GObject from builder |

| Parameter Type | Description   |
| -------------- | ------------- |
| `AlooBuilder*` | Builder       |
| `const char*`  | id of GObject |

#### `_AlooBuilder::alooFromBuilder`

| Returns       | Brief                           |
| ------------- | ------------------------------- |
| `AlooWidget*` | Creates AlooWidget from builder |

| Parameter Type | Description       |
| -------------- | ----------------- |
| `AlooBuilder*` | Builder           |
| `const char*`  | id of Aloo Widget |

## Variables

### Builder

| Key  | Value                 |
| ---- | --------------------- |
| type | `struct _AlooBuilder` |
