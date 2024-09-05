#include "common/window.h"
#include "common/macros.h"
#include "common/widget.h"

AlooWidget *__alooSetWindowChild(AlooWidget *window, AlooWidget *child) {
	gtk_window_set_child(GTK_WINDOW(window->child), child->child);
	return window;
}
AlooWidget *__alooPresentWindow(AlooWidget *window) {
	gtk_window_present(GTK_WINDOW(window->child));
	return window;
}

AlooWidget *__alooApplicationNewWindow(AlooApplication *app) {
	return Widget.gtk_to_aloo(gtk_application_window_new(app->app));
}
AlooWidget *__alooSetWindowTitle(AlooWidget *window, const char *title) {
	gtk_window_set_title(GTK_WINDOW(window->child), title);
	return window;
}
AlooWidget *__setWindowSize(AlooWidget *window, int width, int height) {
	gtk_window_set_default_size(GTK_WINDOW(window->child), width, height);
	return window;
}

AlooWidget *__setWindowApplication(AlooWidget *window, AlooApplication *app) {
	gtk_window_set_application(GTK_WINDOW(window->child), app->app);
	return window;
}

void __showWindow(AlooWidget *window) {
	if (!Widget.check.isWindow(window)) {
		fprintf(stderr, "Widget is not a window\n");
	} else {
		gtk_widget_show(window->child);
	}
}

AlooWidget *__app_add_window(AlooApplication *app, AlooWidget *window) {
	gtk_application_add_window(app->app, GTK_WINDOW(window->child));
	return window;
}

struct _alooWindow Window = {
	.new = __alooApplicationNewWindow,
	.present = __alooPresentWindow,
	.show = __showWindow,
	.setChild = __alooSetWindowChild,
	.setTitle = __alooSetWindowTitle,
	.setSize = __setWindowSize,
	.app_add_window = __app_add_window,
	.set_app_window = __setWindowApplication,
};
