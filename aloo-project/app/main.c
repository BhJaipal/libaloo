#include "aloo.h"
AlooApplication *app;

static void activate() {
	AlooWidget *label = Label.new("Hello World!");
	AlooWidget *win = Window.new(app);
	Window.setChild(win, label);
	Window.setSize(win, 400, 300);
	Window.setTitle(win, "Example App");
	Window.show(win);
	Window.present(win);
	Window.set_app_window(win, app);
}

int main(int argc, char *argv[]) {
	struct AlooAppOptions opts = NONE_FLAGS_OPTIONS(argc, argv);
	app = Application.create("com.example.hello", opts);
	Application.add_event_listener(app, "activate", activate);
	int status = Application.run(app);
	Application.unref(app);
	return 0;
}