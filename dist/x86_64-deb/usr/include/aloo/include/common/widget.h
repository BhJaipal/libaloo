/**
 * @file widget.h
 * @author Jaipal001
 * @brief Aloo Widget related functions
 *
 * @version 0.1
 * @date 2024-09-06
 * @copyright Copyright (c) 2024
 */
#ifndef ALOO_WIDGET_H
#define ALOO_WIDGET_H
#include "types.h"
#include <gtk/gtk.h>

/******************** Private Funcs ********************/
/**
 * @brief Create a widget
 * @param type type of widget
 * @param child actual GtkWidget
 * @return AlooWidget*
 */
AlooWidget *__Widget_new(WidgetType type, GtkWidget *child);

/**
 * @brief Set the Name of widget
 * @param widget AlooWidget
 * @param name string for name of widget
 * @return returns the widget
 */
AlooWidget *__Widget_setName(AlooWidget *widget, const char *name);

/**
 * @brief Creates AlooWidget from GtkWidget
 * @param widget Widget whose `AlooWidget` has to be obtained
 */
AlooWidget *__Widget_Gtk_to_Aloo(GtkWidget *widget);

/**
 * @brief Create `AlooWidget` from GObject
 * @param obj `GObject` from which has to be obtained
 */
AlooWidget *__Widget_Obj_to_Aloo(GObject *obj);

/**
 * @brief Creates `AlooWidget` from builder
 * @param builder `AlooBuilder` from which `AlooWidget` has to be obtained
 * @param name ID of UI object
 * @return `AlooWidget*`
 */
AlooWidget *__Widget_AlooFromBuilder(AlooBuilder *builder, const char *name);

/**
 * @brief Sets orientation of `AlooWidget`
 * @param widget widget whose orientation has to be set
 * @param orientation new orientation of widget
 */
AlooWidget *__Widget_SetOrientation(AlooWidget *widget, GtkOrientation orien);

/**
 * @brief Sets horizontal alignment of `AlooWidget`
 * @param widget Widget whose alignment has to be changed
 * @param alignment alignment type
 */
AlooWidget *__Widget_setHorizontalAlign(AlooWidget *widget, GtkAlign alignment);
/**
 * @brief Sets vertical alignment of `AlooWidget`
 * @param widget Widget whose alignment has to be changed
 * @param alignment alignment type
 */
AlooWidget *__Widget_setVerticalAlign(AlooWidget *widget, GtkAlign alignment);

/**
 * @brief Adds event listener to a widget
 * @param widget_instance
 * @param event_name Event name
 * @param CallbackFn Event Callback function
 * @param data parameters for event listener
 */
AlooWidget *__Widget_AddEventListener(AlooWidget *widget_instance,
									  char *event_name, GCallback CallbackFn,
									  gpointer data);

int __WidgetCheck_isBox(AlooWidget *wid);
int __WidgetCheck_isButton(AlooWidget *wid);
int __WidgetCheck_isGrid(AlooWidget *wid);
int __WidgetCheck_isLabel(AlooWidget *wid);
int __WidgetCheck_isInput(AlooWidget *wid);
int __WidgetCheck_isWindow(AlooWidget *wid);
GtkWidget *__Widget_Aloo_to_Gtk(AlooWidget *wid);

/******************** Private Types ********************/

struct _aloo_widget {
	/// @brief Create a widget
	/// @param type type of widget
	/// @param child actual GtkWidget
	/// @return AlooWidget*
	AlooWidget *(*new)(WidgetType type, GtkWidget *child);
	/// @brief Creates GtkWidget from builder
	GtkWidget *(*obj_to_gtk)(AlooBuilder *builder, const char *name);
	/// @brief Creates AlooWidget from builder
	AlooWidget *(*alooFromBuilder)(AlooBuilder *builder, const char *name);
	/// @brief Create AlooWidget from GObject
	AlooWidget *(*obj_to_aloo)(GObject *obj);
	/// @brief Creates AlooWidget from GtkWidget
	AlooWidget *(*gtk_to_aloo)(GtkWidget *widget);
	/// @brief Sets orientation of AlooWidget
	AlooWidget *(*setOrientation)(AlooWidget *widget, GtkOrientation orien);
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