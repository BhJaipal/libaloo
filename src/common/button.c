#include "common/button.h"
#include "common/style.h"
#include "common/widget.h"
#include "utils/error.h"

AlooWidget *__newButton(AlooButtonType type) {
	AlooWidget *btn = Widget.new(ALOO_BUTTON, gtk_button_new());
	CSS.addClass(btn, "material-button");
	switch (type) {
	case ELEVATED: CSS.addClass(btn, "material-elevated-btn"); break;
	case OUTLINED: CSS.addClass(btn, "material-outlined-btn"); break;
	case TONAL: CSS.addClass(btn, "material-tonal-btn"); break;
	case FILLED: CSS.addClass(btn, "material-filled-btn"); break;
	}
	return btn;
}
AlooWidget *__newButtonWithLabel(const char *label, AlooButtonType type) {
	AlooWidget *btn = Widget.new(ALOO_BUTTON, gtk_button_new());
	switch (type) {
	case ELEVATED: CSS.addClass(btn, "material-elevated-btn"); break;
	case OUTLINED: CSS.addClass(btn, "material-outlined-btn"); break;
	case TONAL: CSS.addClass(btn, "material-tonal-btn"); break;
	case FILLED: CSS.addClass(btn, "material-filled-btn"); break;
	}
	gtk_button_set_label(Button.toGtk(btn), label);
	return btn;
}

AlooWidget *__setLabel(AlooWidget *btn, char const *name) {
	if (!Widget.check.isButton(btn)) {
		throw_error("Invalid button");
		return btn;
	}
	gtk_button_set_label(Button.toGtk(btn), name);
	return btn;
}
AlooWidget *__setChild(AlooWidget *btn, AlooWidget *child) {
	if (!Widget.check.isButton(btn)) {
		throw_error("Invalid button");
		return btn;
	}
	gtk_button_set_child(Button.toGtk(btn), Widget.to_gtk(child));
	return btn;
}
AlooWidget *__setIcon(AlooWidget *btn, const char *icon) {
	if (!Widget.check.isButton(btn)) {
		throw_error("Invalid button");
		return btn;
	}
	gtk_button_set_icon_name(Button.toGtk(btn), icon);
	return btn;
}
AlooWidget *__setUseUnderline(AlooWidget *btn, gboolean yes) {
	if (!Widget.check.isButton(btn)) {
		throw_error("Invalid button");
		return btn;
	}
	gtk_button_set_use_underline(Button.toGtk(btn), yes);
	return btn;
}

const char *__getLabel(AlooWidget *btn) {
	if (!Widget.check.isButton(btn)) {
		throw_error("Invalid button");
		return "Invalid";
	}
	return gtk_button_get_label(Button.toGtk(btn));
}
AlooWidget *__getChild(AlooWidget *btn) {
	if (!Widget.check.isButton(btn)) {
		throw_error("Invalid button");
		return btn;
	}
	return Widget.new(ALOO_BUTTON, gtk_button_get_child(Button.toGtk(btn)));
}
const char *__getIcon(AlooWidget *btn) {
	if (!Widget.check.isButton(btn)) {
		throw_error("Invalid button");
		return "Invalid";
	}
	return gtk_button_get_icon_name(Button.toGtk(btn));
}
gboolean __getUseUnderline(AlooWidget *btn) {
	if (!Widget.check.isButton(btn)) {
		throw_error("Invalid button");
		return 0;
	}
	return gtk_button_get_use_underline(Button.toGtk(btn));
}

GtkButton *__toButtonGtk(AlooWidget *wid) {
	if (!Widget.check.isButton(wid)) {
		throw_error("Invalid button");
		return GTK_BUTTON(Button.new(NORMAL)->child);
	}
	return GTK_BUTTON(wid->child);
}

struct _alooButton Button = {
	__newButton,
	__newButtonWithLabel,
	__toButtonGtk,
	.set =
		{
			__setLabel,
			__setChild,
			__setIcon,
			__setUseUnderline,
		},
	.get =
		{
			__getLabel,
			__getChild,
			__getIcon,
			__getUseUnderline,
		},
};
