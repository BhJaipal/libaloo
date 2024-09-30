#include "common/style.h"
#include "common/widget.h"
#include "common/window.h"
#include "utils/error.h"

AlooWidget *__alooSetWindowChild(AlooWidget *window, AlooWidget *child) {
	gtk_window_set_child(GTK_WINDOW(window->child), child->child);
	return window;
}
AlooWidget *__alooGetWindowChild(AlooWidget *window) {
	return Widget.gtk_to_aloo(gtk_window_get_child(GTK_WINDOW(window->child)));
}
AlooWidget *__alooPresentWindow(AlooWidget *window) {
	gtk_window_present(GTK_WINDOW(window->child));
	return window;
}

AlooWidget *__alooApplicationNewWindow(AlooApplication *app) {
	CSS.importPath("styles/material.css");
	CSS.importPath("styles/colors.css");
	return Widget.gtk_to_aloo(gtk_application_window_new(app->app));
}
AlooWidget *__alooSetWindowTitle(AlooWidget *window, const char *title) {
	gtk_window_set_title(GTK_WINDOW(window->child), title);
	return window;
}
const char *__alooGetWindowTitle(AlooWidget *window) {
	return gtk_window_get_title(GTK_WINDOW(window->child));
}
AlooWidget *__setWindowSize(AlooWidget *window, int width, int height) {
	gtk_window_set_default_size(GTK_WINDOW(window->child), width, height);
	return window;
}
AlooWidget *__getWindowSize(AlooWidget *window, int *width, int *height) {
	gtk_window_get_default_size(GTK_WINDOW(window->child), width, height);
	return window;
}

AlooWidget *__setWindowApplication(AlooWidget *window, AlooApplication *app) {
	CSS.importPath("styles/material.css");
	CSS.importPath("styles/colors.css");
	gtk_window_set_application(GTK_WINDOW(window->child), app->app);
	return window;
}
GtkApplication *__getWindowApplication(AlooWidget *window) {
	return gtk_window_get_application(GTK_WINDOW(window->child));
}

void __showWindow(AlooWidget *window) {
	if (!Widget.check.isWindow(window)) {
		fprintf(stderr, "Widget is not a window\n");
	} else {
		gtk_widget_show(window->child);
	}
}

GtkWindow *__Window_toGtk(AlooWidget *window) {
	if (!Widget.check.isWindow(window)) {
		throw_error("Invalid button");
		return GTK_WINDOW(gtk_window_new());
	}
	return GTK_WINDOW(window->child);
}

AlooWidget *__app_add_window(AlooApplication *app, AlooWidget *window) {
	gtk_application_add_window(app->app, GTK_WINDOW(window->child));
	return window;
}

struct _alooWindow Window = {
	.new = __alooApplicationNewWindow,
	.present = __alooPresentWindow,
	.show = __showWindow,
	.set =
		{
			.child = __alooSetWindowChild,
			.title = __alooSetWindowTitle,
			.size = __setWindowSize,
			.AppWindow = __setWindowApplication,
		},
	.get =
		{
			.size = __getWindowSize,
			.AppWindow = __getWindowApplication,
			.child = __alooGetWindowChild,
			.title = __alooGetWindowTitle,
		},
	.app_add_window = __app_add_window,
	.toGtk = __Window_toGtk,
};
