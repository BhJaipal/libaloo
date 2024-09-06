---
Name: common/label.h
Brief: Aloo Label related functions
---

# label.h

## Private Functions

- __Label_new
- - used by [__alooLabel::new](#__aloolabelnew)
- __Label_toGtk
- - used by [__alooLabel::toGtk](#__aloolabeltogtk)

## Structs

### [`__alooLabel`](../include/common/label.h)

**Description**: `AlooLabel` for using `GtkLabel` utilities

#### [`__alooLabel::new`](./../include/common/label.h#__alooLabel::new)

| Brief | Returns |
|-|-|
| Creates new Aloo label. | `AlooWidget*` |

| Parameter | Type | Description |
|-|-|-|
| label | `const char*` | text shown on label |

#### [`__alooLabel::toGtk`](./../include/common/label.h#__alooLabel::toGtk)

| Description | Returns |
|-|-|
| Converts Aloo label to GtkLabel and return it. | `GtkLabel*` |

| Parameter | Type | Description |
|-|-|-|
| widget | `AlooWidget*` | AlooWidget whose GtkLabel you want to obtain |

## Variables

### Label

| Key | Value |
|--|---|
| type | struct __alooLabel |
| storage class | extern |
