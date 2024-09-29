---
Name: db/sqlite.h
Brief: Utilities for connection with Sqlite DB
---

# sqlite.h

## Structs

### `_sqlite`

#### `_sqlite::open`

| Returns | Brief         |
| ------- | ------------- |
| `int`   | opens db file |

| Parameter Type | Brief        |
| -------------- | ------------ |
| `const char*`  | db file name |
| `sqlite3**`    | database     |

#### `_sqlite::close`

| Returns | Brief          |
| ------- | -------------- |
| `int`   | closes db file |

| Parameter Type | Brief    |
| -------------- | -------- |
| `sqlite3`      | database |

#### `_sqlite::insert`

| Returns | Brief                  |
| ------- | ---------------------- |
| `int`   | insert data to a table |

| Parameter Type | Brief                                           |
| -------------- | ----------------------------------------------- |
| `sqlite3*`     | database                                        |
| `char*`        | table name                                      |
| `int`          | column count                                    |
| `char*`        | column names in a single string like `name, age |
| `char**`       | column values                                   |
| `char**`       | string pointer if any error                     |

#### `_sqlite::select`

| Returns | Brief                   |
| ------- | ----------------------- |
| `int`   | selects data from table |

| Parameter Type                                                        | Brief                                   |
| --------------------------------------------------------------------- | --------------------------------------- |
| `sqlite3*`                                                            | database                                |
| `char*`                                                               | table name                              |
| `int`                                                                 | column count                            |
| `char*[]`                                                             | array of columns like `{"name", "age"}` |
| `char*`                                                               | where clause (optional)                 |
| `int(void *data, int rows_count, char **values, char **column_names)` | callback function                       |
| `char*`                                                               | error if any                            |

#### `_sqlite::delete`

| Returns | Brief                    |
| ------- | ------------------------ |
| `int`   | deletes data from tables |

| Parameter Type                                                        | Brief                |
| --------------------------------------------------------------------- | -------------------- |
| `sqlite3*`                                                            | database             |
| `char*`                                                               | table name           |
| `char**`                                                              | array of columns     |
| `char*`                                                               | where clause         |
| `int(void *data, int rows_count, char **values, char **column_names)` | callback function    |
| `char**`                                                              | error message if any |

#### `_sqlite::createTable`

| Returns | Brief               |
| ------- | ------------------- |
| `int`   | creates table in DB |

| Parameter Type | Brief                                    |
| -------------- | ---------------------------------------- |
| `sqlite3*`     | database                                 |
| `char*`        | table name                               |
| `char*`        | table body like `name TEXT, age INTEGER` |
| `char**`       | error pointer if any error               |

## Variables

### SQLite

| Key  | Value            |
| ---- | ---------------- |
| type | `struct _sqlite` |

## Functions

### nothing

| Returns | Brief        |
| ------- | ------------ |
| `int`   | Does nothing |

| Parameter Type | Brief        |
| -------------- | ------------ |
| `void*`        | {param-desc} |
| `int`          | {param-desc} |
| `char**`       | {param-desc} |
| `char**`       | {param-desc} |

### isString

| Returns | Brief                                    |
| ------- | ---------------------------------------- |
| `int`   | Checks if string only contains alphabets |

| Parameter Type | Brief                |
| -------------- | -------------------- |
| `char*`        | string to be checked |
