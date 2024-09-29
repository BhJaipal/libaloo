---
Name: common/label.h
Brief: Aloo Label related functions
---

# label.h

## Structs

### `__alooLabel`

**Description**: `AlooLabel` for using `GtkLabel` utilities

#### `__alooLabel::new`

| Brief                   | Returns       |
| ----------------------- | ------------- |
| Creates new Aloo label. | `AlooWidget*` |

| Parameter | Type          | Description         |
| --------- | ------------- | ------------------- |
| label     | `const char*` | text shown on label |

#### `__alooLabel::toGtk`

| Description                                    | Returns     |
| ---------------------------------------------- | ----------- |
| Converts Aloo label to GtkLabel and return it. | `GtkLabel*` |

| Parameter | Type          | Description                                  |
| --------- | ------------- | -------------------------------------------- |
| widget    | `AlooWidget*` | AlooWidget whose GtkLabel you want to obtain |

## Variables

### Label

| Key  | Value                |
| ---- | -------------------- |
| type | `struct __alooLabel` |
