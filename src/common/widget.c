#include "common/widget.h"
#include "common/macros.h"
#include <glib-2.0/glib.h>
#include <gtk/gtk.h>

GtkWidget *__WidtoGtk(AlooWidget *wid) { return wid->child; }

AlooWidget *__NewWidget(WidgetType type, GtkWidget *child) {
	AlooWidget *widget = malloc(sizeof(AlooWidget));
	widget->child = child;
	widget->type = type;
	return widget;
}

AlooWidget *__OBJECT_TO_ALOO(GObject *obj) {
	WidgetType type;
	GtkWidget *widget = GTK_WIDGET(obj);
	if (GTK_IS_BOX(widget)) {
		type = ALOO_BOX;
	} else if (GTK_IS_GRID(widget)) {
		type = ALOO_GRID;
	} else if (GTK_IS_BUTTON(widget)) {
		type = ALOO_BUTTON;
	} else if (GTK_IS_LABEL(widget)) {
		type = ALOO_LABEL;
	} else if (GTK_IS_EDITABLE(widget)) {
		type = ALOO_INPUT;
	} else if (GTK_IS_WINDOW(widget)) {
		type = ALOO_WINDOW;
	} else {
		type = ALOO_NEW_WIDGET;
	}
	AlooWidget *wid = malloc(sizeof(AlooWidget));
	wid->child = widget;
	wid->type = type;
	return wid;
}

AlooWidget *__GTK_TO_ALOO(GtkWidget *widget) {
	WidgetType type;
	if (GTK_IS_BOX(widget)) {
		type = ALOO_BOX;
	} else if (GTK_IS_GRID(widget)) {
		type = ALOO_GRID;
	} else if (GTK_IS_BUTTON(widget)) {
		type = ALOO_BUTTON;
	} else if (GTK_IS_LABEL(widget)) {
		type = ALOO_LABEL;
	} else {
		type = ALOO_NEW_WIDGET;
	}
	AlooWidget *wid = malloc(sizeof(AlooWidget));
	wid->child = widget;
	wid->type = type;
	return wid;
}

GtkWidget *__OBJECT_TO_GTK_WIDGET(AlooBuilder *builder, const char *name) {
	return GTK_WIDGET(gtk_builder_get_object(builder->builder, name));
}
AlooWidget *__alooHorizontalAlign(AlooWidget *widget, GtkAlign alignment) {
	gtk_widget_set_halign(widget->child, alignment);
	return widget;
}
AlooWidget *__alooVerticalAlign(AlooWidget *widget, GtkAlign alignment) {
	gtk_widget_set_valign(widget->child, alignment);
	return widget;
}
AlooWidget *__alooSetOrientation(AlooWidget *widget, GtkOrientation orien) {
	gtk_orientable_set_orientation(GTK_ORIENTABLE(widget->child), orien);
	return widget;
}

AlooWidget *__setWidgetName(AlooWidget *widget, const char *name) {
	gtk_widget_set_name(Widget.to_gtk(widget), name);
	return widget;
}

AlooWidget *__alooAddEventListener(AlooWidget *widget_instance,
								   char *event_name, GCallback CallbackFn,
								   gpointer data) {
	g_signal_connect(widget_instance->child, event_name, G_CALLBACK(CallbackFn),
					 data);
	return widget_instance;
}

int is_widget_of_type(AlooWidget *widget, enum WidgetType type) {

	GType checker;
	switch (type) {
	case ALOO_BOX: checker = GTK_TYPE_BOX; break;
	case ALOO_BUTTON: checker = GTK_TYPE_BUTTON; break;
	case ALOO_GRID: checker = GTK_TYPE_GRID; break;
	case ALOO_LABEL: checker = GTK_TYPE_LABEL; break;
	case ALOO_INPUT: checker = GTK_TYPE_EDITABLE; break;
	default: checker = GTK_TYPE_WINDOW; break;
	}
	return ((widget->type == type || widget->type == ALOO_NEW_WIDGET) &&
			G_TYPE_CHECK_INSTANCE_TYPE((widget->child), checker));
}

int __isBox(AlooWidget *wid) { return is_widget_of_type(wid, ALOO_BOX); }
int __isButton(AlooWidget *wid) { return is_widget_of_type(wid, ALOO_BUTTON); }
int __isGrid(AlooWidget *wid) { return is_widget_of_type(wid, ALOO_GRID); }
int __isLabel(AlooWidget *wid) { return is_widget_of_type(wid, ALOO_LABEL); }
int __isWindow(AlooWidget *wid) { return is_widget_of_type(wid, ALOO_WINDOW); }
int __isInput(AlooWidget *wid) { return is_widget_of_type(wid, ALOO_INPUT); }

struct _aloo_widget Widget = {
	.new = __NewWidget,
	.gtk_to_aloo = __GTK_TO_ALOO,
	.obj_to_aloo = __OBJECT_TO_ALOO,
	.setName = __setWidgetName,
	.setOrientation = __alooSetOrientation,
	.obj_to_gtk = __OBJECT_TO_GTK_WIDGET,
	.verticalAlign = __alooVerticalAlign,
	.horizontalAlign = __alooHorizontalAlign,
	.addEventListener = __alooAddEventListener,
	.check =
		{
			.isBox = __isBox,
			.isButton = __isButton,
			.isGrid = __isGrid,
			.isLabel = __isLabel,
			.isInput = __isInput,
			.isWindow = __isWindow,
		},
	.to_gtk = __WidtoGtk,
};