#include "common/label.h"
#include "common/widget.h"
#include "utils/error.h"

AlooWidget *__newLabel(const char *val) {
	return Widget.new(ALOO_LABEL, gtk_label_new(val));
}
GtkLabel *__LabeltoGtk(AlooWidget *wid) {
	if (!Widget.check.isLabel(wid)) {
		throw_error("Invalid label");
		return GTK_LABEL(Label.new("Invalid label")->child);
	}
	return GTK_LABEL(wid->child);
}

struct __alooLabel Label = {__newLabel, __LabeltoGtk};