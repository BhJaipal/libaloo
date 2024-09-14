---
Name: utils/logger.h
Brief: Aloo Logging utils
---

# logger.h

## Structs

### `_logger`

#### `_logger::logCount`

| Member Type | Brief     |
| ----------- | --------- |
| `int`       | Log count |

#### `_logger::err`

| Returns | Brief          |
| ------- | -------------- |
| `void`  | Logs out error |

| Parameter Type    | Brief               |
| ----------------- | ------------------- |
| `struct _logger*` | logger object       |
| `const char*`     | error message       |
| ...               | remaining arguments |

#### `_logger::log`

| Returns | Brief            |
| ------- | ---------------- |
| `void`  | Logs out message |

| Parameter Type    | Brief               |
| ----------------- | ------------------- |
| `struct _logger*` | logger object       |
| `const char*`     | Log output          |
| ...               | remaining arguments |

#### `_logger::warn`

| Returns | Brief            |
| ------- | ---------------- |
| `void`  | Logs out warning |

| Parameter Type    | Brief               |
| ----------------- | ------------------- |
| `struct _logger*` | logger object       |
| `const char*`     | Warning             |
| ...               | remaining arguments |

#### `_logger::info`

| Returns | Brief                |
| ------- | -------------------- |
| `void`  | Logs out information |

| Parameter Type    | Brief               |
| ----------------- | ------------------- |
| `struct _logger*` | logger object       |
| `const char*`     | Information         |
| ...               | remaining arguments |

## Functions

### `newLogger`

| Returns           | Brief                       |
| ----------------- | --------------------------- |
| `struct _logger*` | Returns a new Logger object |
