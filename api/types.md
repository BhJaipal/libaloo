---
Name: common/style.h
Brief: Aloo CSS related functions
---

# types.h

## Struct

### `AlooWidget`

**Description**: widget for my aloo library

| Member | type         | Description      |
| ------ | ------------ | ---------------- |
| widget | `GtkWidget*` | actual GtkWidget |
| type   | `WidgetType` | Type of widget   |

### `AlooBuilder`

**Description**: Builder for aloo library

| Member  | type          | Description |
| ------- | ------------- | ----------- |
| builder | `GtkBuilder*` | Gtk builder |

## Enumerations

### `WidgetType`

**Description**: Type of AlooWidget

| Values            | Brief                                                     |
| ----------------- | --------------------------------------------------------- |
| `ALOO_BOX`        | Used for Gtk Box                                          |
| `ALOO_GRID`       | Used for Gtk Grid                                         |
| `ALOO_ROW`        | Used for Gtk Row                                          |
| `ALOO_COLUMN`     | Used for Gtk Column                                       |
| `ALOO_BUTTON`     | Used for Gtk Button                                       |
| `ALOO_LABEL`      | Used for Gtk Label                                        |
| `ALOO_NEW_WIDGET` | Can be used to create new custom widget and used with all |
