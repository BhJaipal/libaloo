#include "aloo.h"
#include "common/app.h"
#include <stdio.h>
AlooApplication *app;
Test *t;

static void activate() {
	AlooWidget *label = Label.new("Hello World!");
	AlooWidget *win = Window.new(app);
	Window.set.child(win, label);
	Window.set.size(win, 400, 300);
	Window.set.title(win, "Example App");
	Window.show(win);
	Window.present(win);

	t->addTest("Widget Test", t, t->expectGtkWidget(label->child, label));
	t->result(t);

	Window.set.AppWindow(win, app);
	g_application_quit(G_APPLICATION(app->app));
}

int main(int argc, char **argv) {
	t = createTest("Testing");
	t->addTest("Test trying", t, t->expectInt(2 * 2, 4));

	app = Application.create("com.example.hello", getAppFlags.noneNoArgs());
	Application.add_event_listener(app, "activate", activate, NULL);

	int status = Application.run(app);
	Application.unref(app);
	fprintf(stderr, "\n");
	return 0;
}