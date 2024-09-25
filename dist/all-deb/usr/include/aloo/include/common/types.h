/**
 * @file types.h
 * @author Jaipal001
 * @brief Aloo Project Types related functions
 *
 * @version 0.1
 * @date 2024-09-06
 * @copyright Copyright (c) 2024
 */
#ifndef ALOO_TYPES_H
#define ALOO_TYPES_H
#include <gtk/gtk.h>

/**
 * @brief Type of AlooWidget
 */
typedef enum WidgetType {
	/**
	 * @brief Used for Gtk Box
	 */
	ALOO_BOX,
	/**
	 * @brief Used for Gtk Grid
	 */
	ALOO_GRID,
	/**
	 * @brief Used for Gtk Button
	 */
	ALOO_BUTTON,
	/**
	 * @brief Used for Gtk Label
	 */
	ALOO_LABEL,
	/**
	 * @brief Used for Gtk Window
	 */
	ALOO_WINDOW,
	/// @brief Used for Gtk Input
	ALOO_INPUT,
	/**
	 * @brief Can be used to create new custom widget and used with all
	 */
	ALOO_NEW_WIDGET
} WidgetType;

/**
 * @brief widget for my aloo library
 */
typedef struct AlooWidget {
	/**
	 * @brief actual GtkWidget
	 */
	GtkWidget *child;
	/**
	 * @brief Type of widget
	 */
	WidgetType type;
} AlooWidget;

/// @public
typedef struct {
	GtkBuilder *builder;
} AlooBuilder;

#endif // ALOO_TYPES_H