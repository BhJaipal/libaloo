#include "common/input.h"
#include "common/widget.h"
#include "utils/error.h"

AlooWidget *__input_new(char *label) {
	return Widget.new(ALOO_INPUT, gtk_editable_label_new(label));
}
const char *__input_get_val(AlooWidget *input) {
	return gtk_editable_get_text(Input.toGtk(input));
}
AlooWidget *__input_set_val(AlooWidget *input, const char *value) {
	gtk_editable_set_text(Input.toGtk(input), value);
	return input;
}

GtkEditable *__input_to_gtk(AlooWidget *input) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return GTK_EDITABLE(Input.new("Invalid")->child);
	}
	return GTK_EDITABLE(input->child);
}

gboolean __input_get_isEditable(AlooWidget *input) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	return gtk_editable_get_editable(Input.toGtk(input));
}
AlooWidget *__input_set_isEditable(AlooWidget *input, gboolean editable) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_set_editable(Input.toGtk(input), editable);
	return input;
}

guint64 __input_get_value_length(AlooWidget *input) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	return strlen(__input_get_val(input));
}
AlooWidget *__input_insert_text(AlooWidget *input, const char *text,
								int text_length, int *position) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_insert_text(Input.toGtk(input), text, text_length, position);
	return input;
}
AlooWidget *__input_append_text(AlooWidget *input, const char *text,
								int text_length) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	guint64 length = __input_get_value_length(input);
	gtk_editable_insert_text(Input.toGtk(input), text, text_length,
							 (int *)(&length));
	return input;
}
AlooWidget *__input_prepend_text(AlooWidget *input, const char *text,
								 int text_length) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	int length = 0;
	gtk_editable_insert_text(Input.toGtk(input), text, text_length, &length);
	return input;
}
AlooWidget *__input_deleteText(AlooWidget *input, int start, int end) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_delete_text(Input.toGtk(input), start, end);
	return input;
}
AlooWidget *__input_deleteSelection(AlooWidget *input, int start, int end) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_delete_selection(Input.toGtk(input));
	return input;
}
gboolean __input_get_isUndo_enabled(AlooWidget *input) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	return gtk_editable_get_enable_undo(Input.toGtk(input));
}
gint __input_get_position(AlooWidget *input) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	return gtk_editable_get_position(Input.toGtk(input));
}
gfloat __input_get_alignment(AlooWidget *input) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	return gtk_editable_get_alignment(Input.toGtk(input));
}
AlooWidget *__input_set_isUndo_enabled(AlooWidget *input, gboolean enabled) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_set_enable_undo(Input.toGtk(input), enabled);
	return input;
}
AlooWidget *__input_set_position(AlooWidget *input, gint position) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_set_position(Input.toGtk(input), position);
	return input;
}
AlooWidget *__input_set_alignment(AlooWidget *input, gfloat alignment) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_set_alignment(Input.toGtk(input), alignment);
	return input;
}
AlooWidget *__input_select(AlooWidget *input, int start, int end) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_select_region(Input.toGtk(input), start, end);
	return input;
}
AlooWidget *__input_get_Selected(AlooWidget *input, int *start, int *end) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return 0;
	}
	gtk_editable_get_selection_bounds(Input.toGtk(input), start, end);
	return input;
}

struct __alooInput Input = {
	.new = __input_new,
	.toGtk = __input_to_gtk,
	.insertText = __input_insert_text,
	.prependText = __input_prepend_text,
	.appendText = __input_append_text,
	.getValueLength = __input_get_value_length,
	.get =
		{
			.value = __input_get_val,
			.isEditable = __input_get_isEditable,
			.selected = __input_get_Selected,
			.position = __input_get_position,
			.alignment = __input_get_alignment,
			.isUndoEnabled = __input_get_isUndo_enabled,
		},
	.set =
		{
			.alignment = __input_set_alignment,
			.isEditable = __input_set_isEditable,
			.undoEnabled = __input_set_isUndo_enabled,
			.position = __input_set_position,
			.select_text = __input_select,
			.value = __input_set_val,
		},
};
