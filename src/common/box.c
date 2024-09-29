#include "common/box.h"
#include "common/widget.h"
#include "utils/error.h"
#include <gtk/gtk.h>

AlooWidget *__new_alooBox(GtkOrientation orientation, int spacing) {
	AlooWidget *box = malloc(sizeof(AlooWidget));
	box->type = ALOO_BOX;
	box->child = gtk_box_new(orientation, spacing);
	return box;
}
AlooWidget *__setBoxOrientation(AlooWidget *box, GtkOrientation orientation) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_orientable_set_orientation(GTK_ORIENTABLE(Box.toGtk(box)), orientation);
	return box;
}
GtkOrientation __getBoxOrientation(AlooWidget *box) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return GTK_ORIENTATION_HORIZONTAL;
	}
	return gtk_orientable_get_orientation(GTK_ORIENTABLE(Box.toGtk(box)));
}

AlooWidget *__boxAppendGtk(AlooWidget *box, GtkWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_append(Box.toGtk(box), widget);
	return box;
}
AlooWidget *__boxPrependGtk(AlooWidget *box, GtkWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_prepend(Box.toGtk(box), widget);
	return box;
}
AlooWidget *__boxRemoveGtk(AlooWidget *box, GtkWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_remove(Box.toGtk(box), widget);
	return box;
}

AlooWidget *__boxAppend(AlooWidget *box, AlooWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_append(Box.toGtk(box), Widget.to_gtk(widget));
	return box;
}
AlooWidget *__boxPrepend(AlooWidget *box, AlooWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_prepend(Box.toGtk(box), Widget.to_gtk(widget));
	return box;
}
AlooWidget *__boxRemove(AlooWidget *box, AlooWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_remove(Box.toGtk(box), Widget.to_gtk(widget));
	return box;
}

AlooWidget *__setBoxSpacing(AlooWidget *box, int spacing) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_set_spacing(Box.toGtk(box), spacing);
	return box;
}
int __getBoxSpacing(AlooWidget *box) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return 0;
	}
	return gtk_box_get_spacing(Box.toGtk(box));
}
gboolean __getBoxHomogeneous(AlooWidget *box) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return 0;
	}
	return gtk_box_get_homogeneous(Box.toGtk(box));
}
AlooWidget *__setBoxHomogeneous(AlooWidget *box, gboolean homogeneous) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_set_homogeneous(Box.toGtk(box), homogeneous);
	return box;
}

GtkBaselinePosition __getBoxBaselinePosition(AlooWidget *box) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return GTK_BASELINE_POSITION_TOP;
	}
	return gtk_box_get_baseline_position(Box.toGtk(box));
}
AlooWidget *__setBoxBaselinePosition(AlooWidget *box,
									 GtkBaselinePosition position) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_set_baseline_position(Box.toGtk(box), position);
	return box;
}

AlooWidget *__boxInsertChildAfter(AlooWidget *box, AlooWidget *child,
								  AlooWidget *after) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_insert_child_after(Box.toGtk(box), child->child, after->child);
	return box;
}
GtkBox *__toGtk(AlooWidget *widget) {
	if (Widget.check.isBox(widget)) return GTK_BOX(widget->child);
	throw_error("Invalid box");
	return GTK_BOX(Box.new(GTK_ORIENTATION_HORIZONTAL, 0)->child);
}

struct _alooBox Box = {
	__new_alooBox,
	__boxAppendGtk,
	__boxPrependGtk,
	__boxRemoveGtk,
	__boxAppend,
	__boxPrepend,
	__boxRemove,
	__boxInsertChildAfter,
	.set =
		{
			.baselinePosition = __setBoxBaselinePosition,
			.homogeneous = __setBoxHomogeneous,
			.spacing = __setBoxSpacing,
			.orientation = __setBoxOrientation,
		},
	.get =
		{
			.orientation = __getBoxOrientation,
			.spacing = __getBoxSpacing,
			.homogeneous = __getBoxHomogeneous,
			.baselinePosition = __getBoxBaselinePosition,
		},
	__toGtk,
};