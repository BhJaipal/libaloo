#include "common/label.h"
#include "common/widget.h"
#include "utils/error.h"

AlooWidget __Label_new(const char *val) {
	return Widget.new(ALOO_LABEL, gtk_label_new(val));
}
GtkLabel *__Label_toGtk(AlooWidget wid) {
	if (!Widget.check.isLabel(wid)) {
		throw_error("Invalid label");
		return GTK_LABEL(Label.new("Invalid label")->child);
	}
	return GTK_LABEL(wid->child);
}

struct __alooLabel Label = {__Label_new, __Label_toGtk};