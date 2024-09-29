/**
 * @file app.h
 * @author Jaipal001
 * @brief Aloo Application related functions
 *
 * @version 0.1
 * @date 2024-09-06
 * @copyright Copyright (c) 2024
 */
#ifndef ALOO_APP_H
#define ALOO_APP_H
#include "types.h"
#include <gtk/gtk.h>

/**
 * @brief G Application Flags
 */
enum alooAppFlags {
	/**
	 * @brief G_APPLICATION_FLAGS_NONE
	 */
	APP_FLAGS_NONE = 0,
	/**
	 * @brief G_APPLICATION_FLAGS_IS_LAUNCHER
	 */
	APP_FLAGS_IS_LAUNCHER,
	/**
	 * @brief G_APPLICATION_FLAGS_IS_SERVICE
	 */
	APP_FLAGS_IS_SERVICE
};

typedef struct AlooApplication {
	GtkApplication *app;
	int status;
	int argc;
	char **argv;
} AlooApplication;

/**
 * @brief Takes GApplicationFlags, argc and argv
 */
struct AlooAppOptions {
	enum alooAppFlags appFlags;
	int argc;
	char **argv;
};

/**
 * @brief Takes argc and argv and returns struct AlooAppOptions
 */
struct _getAppFlags {
	/// @return `struct AlooAppOptions` with `APP_FLAGS_NONE`
	struct AlooAppOptions (*none)(int argc, char **argv);
	/// @return `struct AlooAppOptions` with `APP_FLAGS_IS_LAUNCHER`
	struct AlooAppOptions (*launcher)(int argc, char **argv);
	/// @return `struct AlooAppOptions` with `APP_FLAGS_IS_SERVICE`
	struct AlooAppOptions (*service)(int argc, char **argv);
};

/******************** Private Funcs ********************/

/**
 * @brief Create a App object
 * @param app_id App Id are like com.google.Chrome, dev.zed.Zed
 * @param AppOptions It takes GApplicationFlags, argc and argv
 * @return It returns Aloo Application
 */
AlooApplication *__CreateApp(const char *app_id,
							 struct AlooAppOptions AppOptions);

/// @brief Runs aloo App
/// @return status on exiting app
int __RunApp(AlooApplication *application);
/// @brief Runs aloo App and unrefs after exiting it
/// @return status on exiting app
int __RunAppAndUnrefIt(AlooApplication *application);
/** @brief unrefs aloo App */
void __unrefApp(AlooApplication *application);
/**
 * @brief Adds Event Listener to Aloo App
 * @param app Aloo Application
 * @param event Event name
 * @param callbackFn static void function which will be called when app is
 * started
 */
void __AppAddEvents(AlooApplication *app, const char *event,
					GCallback callbackFn, gpointer data);

/******************** Private Types ********************/

/**
 * @brief An Structure that contains all the AlooApplication related functions
 */
struct _alooApp {
	/// @brief Create a App object
	/// @param app_id App Id are like com.google.Chrome, dev.zed.Zed
	/// @param gAppOptions It takes GApplicationFlags, argc and argv
	/// @return Create and Return an AlooApplication.
	AlooApplication *(*create)(const char *app_id,
							   struct AlooAppOptions gAppOptions);
	/// @brief Runs aloo App
	/// @param application AlooApplicaion to be run
	/// @return status on exiting app
	int (*run)(AlooApplication *application);
	/// @brief Runs aloo App and unrefs after exiting it
	/// @param application AlooApplicaion to be run and unref
	/// @return status on exiting app
	int (*run_and_unref)(AlooApplication *application);
	/** @brief unrefs aloo App */
	/// @param application AlooApplicaion to be unref
	void (*unref)(AlooApplication *application);
	/// @brief Adds Event Listener to Aloo App
	/// @param app Aloo Application
	/// @param event Event name
	/// @param callbackFn static void function which will be called when app is
	/// started
	void (*add_event_listener)(AlooApplication *app, const char *event,
							   GCallback callbackFn, gpointer data);
};

/******************** Public ********************/

extern struct _alooApp Application;
extern struct _getAppFlags getAppFlags;

#endif // ALOO_APP_H