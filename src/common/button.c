#include <aloo/common/button.h>
#include <aloo/common/widget.h>
#include <aloo/utils/error.h>

AlooWidget *__newButton() {
	AlooWidget *btn = Widget.new(ALOO_BUTTON, gtk_button_new());
	return btn;
}
AlooWidget *__newButtonWithLabel(const char *label) {
	AlooWidget *btn = Widget.new(ALOO_BUTTON, gtk_button_new());
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

GtkButton *__toButtonGtk(AlooWidget *wid) {
	if (!Widget.check.isButton(wid)) {
		throw_error("Invalid button");
		return GTK_BUTTON(Button.new()->child);
	}
	return GTK_BUTTON(wid->child);
}

struct _alooButton Button = {
	__newButton, __newButtonWithLabel, __setLabel,	 __setChild,
	__setIcon,	 __setUseUnderline,	   __toButtonGtk};
