#include "common/app.h"

struct AlooApplication *__CreateApp(const char *appName,
									struct AlooAppOptions AppOptions) {
	GApplicationFlags flags;
	switch (AppOptions.appFlags) {
	case APP_FLAGS_NONE: flags = G_APPLICATION_FLAGS_NONE; break;
	case APP_FLAGS_IS_SERVICE: flags = G_APPLICATION_IS_SERVICE; break;
	case APP_FLAGS_IS_LAUNCHER: flags = G_APPLICATION_IS_LAUNCHER; break;
	default: flags = G_APPLICATION_FLAGS_NONE; break;
	}
	GtkApplication *gtkApp = gtk_application_new(appName, flags);
	AlooApplication *out = malloc(sizeof(AlooApplication));
	out->app = gtkApp;
	out->status = 0;
	out->argc = AppOptions.argc;
	out->argv = AppOptions.argv;
	return out;
}
int __RunApp(AlooApplication *application) {
	GApplication *app = G_APPLICATION(application->app);
	int status = g_application_run(app, application->argc, application->argv);
	application->status = status;
	return status;
}
int __RunAppAndUnrefIt(AlooApplication *application) {
	GApplication *app = G_APPLICATION(application->app);
	int status = g_application_run(app, application->argc, application->argv);
	application->status = status;
	__unrefApp(application);
	return status;
}

struct AlooAppOptions _app_get_none(int argc, char **argv) {
	struct AlooAppOptions opts = {APP_FLAGS_NONE, argc, argv};
	return opts;
}
struct AlooAppOptions _app_get_launcher(int argc, char **argv) {
	struct AlooAppOptions opts = {APP_FLAGS_IS_LAUNCHER, argc, argv};
	return opts;
}
struct AlooAppOptions _app_get_service(int argc, char **argv) {
	struct AlooAppOptions opts = {APP_FLAGS_IS_SERVICE, argc, argv};
	return opts;
}

void __unrefApp(AlooApplication *application) {
	g_object_unref(application->app);
}
void __AppAddEvents(AlooApplication *app, const char *event,
					GCallback callbackFn, gpointer data) {
	g_signal_connect(app->app, "activate", callbackFn, data);
}
struct _alooApp Application = {
	__CreateApp, __RunApp, __RunAppAndUnrefIt, __unrefApp, __AppAddEvents,
};
struct _getAppFlags getAppFlags = {
	.none = _app_get_none,
	.launcher = _app_get_launcher,
	.service = _app_get_service,
};
