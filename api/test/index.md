---
Name: test/main.h
Brief: fileDesc
---

# test/main.h

## Structs

### `_Test`

#### `_Test::testCount`

| Member Type | Brief            |
| ----------- | ---------------- |
| `int`       | Total test count |

#### `_Test::testPassed`

| Member Type | Brief                   |
| ----------- | ----------------------- |
| `int`       | Total passed test count |

#### `_Test::testFailed`

| Member Type | Brief                   |
| ----------- | ----------------------- |
| `int`       | Total failed test count |

#### `_Test::label`

| Member Type   | Brief     |
| ------------- | --------- |
| `const char*` | Test name |

#### `_Test::result`

| Returns | Brief             |
| ------- | ----------------- |
| `void`  | shows test result |

| Parameter Type | Brief     |
| -------------- | --------- |
| `struct _Test` | Test unit |

#### `_Test::addTest`

| Returns | Brief       |
| ------- | ----------- |
| `void`  | Adds a Test |

| Parameter Type | Brief        |
| -------------- | ------------ |
| `const char*`  | Test name    |
| `struct _Test` | Test unit    |
| `int`          | Test result` |

#### `_Test::expectInt`

| Returns | Brief              |
| ------- | ------------------ |
| `int`   | Compares int value |

| Parameter Type | Brief              |
| -------------- | ------------------ |
| `paramT`       | expected int value |
| `paramT`       | actual int value   |

#### `_Test::expectWidget`

| Returns | Brief           |
| ------- | --------------- |
| `int`   | Compares widget |

| Parameter Type | Brief           |
| -------------- | --------------- |
| `AlooWidget`   | expected Widget |
| `AlooWidget`   | actual Widget   |

#### `_Test::expectGtkWidget`

| Returns | Brief                                               |
| ------- | --------------------------------------------------- |
| `int`   | Compares GtkWidget with child member of Aloo Widget |

| Parameter Type | Brief               |
| -------------- | ------------------- |
| `paramT`       | expected Gtk Widget |
| `AlooWidget`   | actual Widget       |

## Variables

### Test

| Key  | Value          |
| ---- | -------------- |
| type | `struct _Test` |

## Functions

### `createTest`

| Returns           | Brief                                 |
| ----------------- | ------------------------------------- |
| `struct _logger*` | Returns a new Test object for Testing |
