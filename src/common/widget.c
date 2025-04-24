#include "common/widget.h"

GtkWidget *__Widget_Aloo_to_Gtk(AlooWidget wid) { return wid->child; }

AlooWidget __Widget_new(WidgetType type, GtkWidget *child) {
	AlooWidget widget = malloc(sizeof(AlooWidget));
	widget->child = child;
	widget->type = type;
	return widget;
}

AlooWidget __Widget_Obj_to_Aloo(GObject *obj) {
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
	AlooWidget wid = malloc(sizeof(AlooWidget));
	wid->child = widget;
	wid->type = type;
	return wid;
}

AlooWidget __Widget_Gtk_to_Aloo(GtkWidget *widget) {
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
	AlooWidget wid = malloc(sizeof(AlooWidget));
	wid->child = widget;
	wid->type = type;
	return wid;
}

GtkWidget *__Widget_Obj_to_Gtk(AlooBuilder *builder, const char *name) {
	return GTK_WIDGET(gtk_builder_get_object(builder->builder, name));
}

AlooWidget __Widget_setName(AlooWidget widget, const char *name) {
	gtk_widget_set_name(Widget.to_gtk(widget), name);
	return widget;
}
const char *__Widget_getName(AlooWidget widget) {
	return gtk_widget_get_name(Widget.to_gtk(widget));
}

AlooWidget __Widget_AlooFromBuilder(AlooBuilder *builder, const char *name) {
	AlooWidget wid =
		__Widget_Obj_to_Aloo(gtk_builder_get_object(builder->builder, name));
	return wid;
}

AlooWidget __Widget_setHorizontalAlign(AlooWidget widget,
										GtkAlign alignment) {
	gtk_widget_set_halign(widget->child, alignment);
	return widget;
}
AlooWidget __Widget_setVerticalAlign(AlooWidget widget, GtkAlign alignment) {
	gtk_widget_set_valign(widget->child, alignment);
	return widget;
}

AlooWidget __Widget_SetOrientation(AlooWidget widget, GtkOrientation orien) {
	gtk_orientable_set_orientation(GTK_ORIENTABLE(widget->child), orien);
	return widget;
}

AlooWidget __Widget_AddEventListener(AlooWidget widget_instance,
									  char *event_name, GCallback CallbackFn,
									  gpointer data) {
	g_signal_connect(widget_instance->child, event_name, G_CALLBACK(CallbackFn),
					 data);
	return widget_instance;
}
GtkOrientation __Widget_getOrientation(AlooWidget widget) {
	return gtk_orientable_get_orientation(GTK_ORIENTABLE(widget->child));
}
GtkAlign __Widget_getHorizontalAlign(AlooWidget widget) {
	return gtk_widget_get_halign(widget->child);
}
GtkAlign __Widget_getVerticalAlign(AlooWidget widget) {
	return gtk_widget_get_valign(widget->child);
}

int is_widget_of_type(AlooWidget widget, enum WidgetType type) {

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

int __WidgetCheck_isBox(AlooWidget wid) {
	return is_widget_of_type(wid, ALOO_BOX);
}
int __WidgetCheck_isButton(AlooWidget wid) {
	return is_widget_of_type(wid, ALOO_BUTTON);
}
int __WidgetCheck_isGrid(AlooWidget wid) {
	return is_widget_of_type(wid, ALOO_GRID);
}
int __WidgetCheck_isLabel(AlooWidget wid) {
	return is_widget_of_type(wid, ALOO_LABEL);
}
int __WidgetCheck_isWindow(AlooWidget wid) {
	return is_widget_of_type(wid, ALOO_WINDOW);
}
int __WidgetCheck_isInput(AlooWidget wid) {
	return is_widget_of_type(wid, ALOO_INPUT);
}

struct _aloo_widget Widget = {
	.new = __Widget_new,
	.gtk_to_aloo = __Widget_Gtk_to_Aloo,
	.obj_to_aloo = __Widget_Obj_to_Aloo,
	.alooFromBuilder = __Widget_AlooFromBuilder,
	.set =
		{
			.name = __Widget_setName,
			.orientation = __Widget_SetOrientation,
			.horizontalAlign = __Widget_setHorizontalAlign,
			.verticalAlign = __Widget_setVerticalAlign,
		},
	.get =
		{
			.name = __Widget_getName,
			.orientation = __Widget_getOrientation,
			.horizontalAlign = __Widget_getHorizontalAlign,
			.verticalAlign = __Widget_getVerticalAlign,
		},
	.obj_to_gtk = __Widget_Obj_to_Gtk,
	.addEventListener = __Widget_AddEventListener,
	.check =
		{
			.isBox = __WidgetCheck_isBox,
			.isButton = __WidgetCheck_isButton,
			.isGrid = __WidgetCheck_isGrid,
			.isLabel = __WidgetCheck_isLabel,
			.isInput = __WidgetCheck_isInput,
			.isWindow = __WidgetCheck_isWindow,
		},
	.to_gtk = __Widget_Aloo_to_Gtk,
};