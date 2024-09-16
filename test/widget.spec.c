#include "aloo.h"
#include <stdio.h>
Test *t;
AlooApplication *app;

static void activate() {
	AlooWidget *win = Window.new(app);
	Window.setSize(win, 400, 300);
	Window.setTitle(win, "Testing libaloo");
	AlooWidget *label = Label.new("Hello World!");
	Window.setChild(win, label);
	t->addTest("Widget Test", t, t->expectGtkWidget(label->child, label));
	t->result(t);
	Window.show(win);
	Window.present(win);
	Window.set_app_window(win, app);
	g_application_quit(G_APPLICATION(app->app));
}

int main(int argc, char **argv) {
	app = Application.create("com.libaloo.test", getAppFlags.none(argc, argv));
	t = createTest("Testing Aloo");
	Application.add_event_listener(app, "activate", activate);
	Application.run_and_unref(app);
	return 0;
}