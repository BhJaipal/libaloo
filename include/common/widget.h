/**
 * @file widget.h
 * @author Jaipal001
 * @brief Aloo Widget related functions
 */
#ifndef ALOO_WIDGET_H
#define ALOO_WIDGET_H
#include "types.h"
#include <gtk/gtk.h>

/******************** Private Funcs ********************/

/**
 * @brief Creates AlooWidget from GtkWidget
 */
AlooWidget *__GTK_TO_ALOO(GtkWidget *widget);

/**
 * @brief Create AlooWidget from GObject
 */
AlooWidget *__OBJECT_TO_ALOO(GObject *obj);

/**
 * @brief Sets orientation of AlooWidget
 */
AlooWidget *__alooSetOrientation(AlooWidget *widget, GtkOrientation orien);

/**
 * @brief Create a widget
 * @param type type of widget
 * @param child actual GtkWidget
 * @return AlooWidget*
 */
AlooWidget *__NewWidget(WidgetType type, GtkWidget *child);

/**
 * @brief Set the Name of widget
 * @param widget AlooWidget
 * @param name string for name of widget
 * @return returns the widget
 */
AlooWidget *__setWidgetName(AlooWidget *widget, const char *name);

/**
 * @brief Creates GtkWidget from builder
 */
GtkWidget *__OBJECT_TO_GTK_WIDGET(AlooBuilder *builder, const char *name);

/**
 * @brief Sets horizontal alignment of AlooWidget
 */
AlooWidget *__alooHorizontalAlign(AlooWidget *widget, GtkAlign alignment);
/**
 * @brief Sets vertical alignment of AlooWidget
 */
AlooWidget *__alooVerticalAlign(AlooWidget *widget, GtkAlign alignment);

/**
 * @brief Adds event listener to a widget
 * @param widget_instance
 * @param event_name Event name
 * @param CallbackFn Event Callback function
 * @param data parameters for event listener
 */
AlooWidget *__alooAddEventListener(AlooWidget *widget_instance,
								   char *event_name, GCallback CallbackFn,
								   gpointer data);

int __isBox(AlooWidget *wid);
int __isButton(AlooWidget *wid);
int __isGrid(AlooWidget *wid);
int __isLabel(AlooWidget *wid);
int __isInput(AlooWidget *wid);
int __isWindow(AlooWidget *wid);
GtkWidget *__WidtoGtk(AlooWidget *wid);

/******************** Private Types ********************/

struct _aloo_widget {
	/// @brief Creates GtkWidget from builder
	GtkWidget *(*obj_to_gtk)(AlooBuilder *builder, const char *name);
	/// @brief Create AlooWidget from GObject
	AlooWidget *(*obj_to_aloo)(GObject *obj);
	/// @brief Creates AlooWidget from GtkWidget
	AlooWidget *(*gtk_to_aloo)(GtkWidget *widget);
	/// @brief Sets orientation of AlooWidget
	AlooWidget *(*setOrientation)(AlooWidget *widget, GtkOrientation orien);
	/// @brief Create a widget
	/// @param type type of widget
	/// @param child actual GtkWidget
	/// @return AlooWidget*
	AlooWidget *(*new)(WidgetType type, GtkWidget *child);
	/// @brief Set the Name of widget
	/// @param widget AlooWidget
	/// @param name string for name of widget
	/// @return returns the widget
	AlooWidget *(*setName)(AlooWidget *widget, const char *name);
	/// @brief Sets horizontal alignment of AlooWidget
	AlooWidget *(*horizontalAlign)(AlooWidget *widget, GtkAlign alignment);
	/// @brief Sets vertical alignment of AlooWidget
	AlooWidget *(*verticalAlign)(AlooWidget *widget, GtkAlign alignment);
	/// @brief Adds event listener to a widget
	/// @param widget_instance
	/// @param data parameters for event listener
	AlooWidget *(*addEventListener)(AlooWidget *widget_instance,
									char *event_name, GCallback CallbackFn,
									gpointer data);
	struct {
		int (*isBox)(AlooWidget *wid);
		int (*isButton)(AlooWidget *wid);
		int (*isGrid)(AlooWidget *wid);
		int (*isLabel)(AlooWidget *wid);
		int (*isInput)(AlooWidget *wid);
		int (*isWindow)(AlooWidget *wid);
	} check;
	GtkWidget *(*to_gtk)(AlooWidget *wid);
};

/******************** Public ********************/

extern struct _aloo_widget Widget;

int is_widget_of_type(AlooWidget *widget, enum WidgetType type);

#endif // ALOO_WIDGET_H