/**
 * @file window.h
 * @author Jaipal001
 * @brief Contains aloo Window related functions
 */

#ifndef ALOO_WINDOW_H
#define ALOO_WINDOW_H
#include "app.h"
#include "types.h"

/******************** Private Funcs ********************/

/**
 * @brief Sets Window child
 */
AlooWidget *__alooSetWindowChild(AlooWidget *window, AlooWidget *child);

/**
 * @brief Presents GtkWindow
 */
AlooWidget *__alooPresentWindow(AlooWidget *window);

/**
 * @brief Create a GtkWindow
 */
AlooWidget *__alooApplicationNewWindow(AlooApplication *app);

/**
 * @brief Sets GtkWindow title
 */
AlooWidget *__alooSetWindowTitle(AlooWidget *window, const char *title);

/**
 * @brief Sets aloo Window size
 */
AlooWidget *__setWindowSize(AlooWidget *window, int width, int height);

/**
 * @brief Set the Window for Application
 */
AlooWidget *__setWindowApplication(AlooWidget *window, AlooApplication *app);

/**
 * @brief Adds Window to Application
 */
AlooWidget *__app_add_window(AlooApplication *app, AlooWidget *window);

/**
 * @brief Shows Window
 */
void __showWindow(AlooWidget *window);

/******************** Private Types ********************/

struct _alooWindow {
	/// @brief Create a GtkWindow
	/// @param app AlooApplication*
	/// @return AlooWidget*
	AlooWidget *(*new)(AlooApplication *app);
	/// @brief Presents GtkWindow
	/// @param window AlooWidget*
	/// @return AlooWidget*
	AlooWidget *(*present)(AlooWidget *window);
	/// @brief Sets Window child
	/// @param window AlooWidget *
	/// @param child AlooWidget *
	/// @return
	AlooWidget *(*setChild)(AlooWidget *window, AlooWidget *child);
	/// @brief Sets GtkWindow title
	/// @param window AlooWidget *
	/// @param title const char*
	/// @return AlooWidget *
	AlooWidget *(*setTitle)(AlooWidget *window, const char *title);
	/// @brief Sets aloo Window size
	/// @param window AlooWidget *
	/// @param width int
	/// @param height int
	/// @return AlooWidget*
	AlooWidget *(*setSize)(AlooWidget *window, int width, int height);
	/// @brief Set the Window for Application
	/// @param window AlooWidget*
	/// @param app AlooApplication*
	/// @return AlooWidget*
	AlooWidget *(*set_app_window)(AlooWidget *window, AlooApplication *app);
	/// @brief Adds Window to Application
	/// @param app AlooApplication*
	/// @param window AlooWidget*
	/// @return AlooWidget*
	AlooWidget *(*app_add_window)(AlooApplication *app, AlooWidget *window);
	/// @brief Shows Window
	/// @param window AlooWidget*
	/// @return void
	void (*show)(AlooWidget *window);
};

/******************** Public ********************/

extern struct _alooWindow Window;

#endif // ALOO_WINDOW_H