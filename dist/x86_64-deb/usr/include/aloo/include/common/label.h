/**
 * @file label.h
 * @author Jaipal001
 * @brief Aloo Label related functions
 */
#ifndef ALOO_LABEL_H
#define ALOO_LABEL_H
#include "types.h"

/******************** Private Funcs ********************/

AlooWidget *__Label_new(const char *val);
GtkLabel *__Label_toGtk(AlooWidget *wid);

/******************** Private Types ********************/

/**
 * @brief `AlooLabel` for using `GtkLabel` utilities
 */
struct __alooLabel {
	/**
	 * @brief Creates new Aloo label
	 * @param  label text shown on label
	 *
	 * * Details:
	 * It calls `Widget.new` from `widget.h` with `ALOO_LABEL` and
	 *
	 * `gtk_label_new` with out label parameter
	 */
	AlooWidget *(*new)(const char *label);
	/**
	 * @brief Converts Aloo label to GtkLabel and return it
	 * @param widget AlooWidget whose GtkLabel you want to obtain
	 *
	 * * Details:
	 * It checks if child of AlooWidget is a GtkLabel or not,
	 * by using `GTK_LABEL`
	 *
	 * if yes, returns it
	 *
	 * Else creates a New AlooWidget Label and return `GtkLabel` of it
	 */
	GtkLabel *(*toGtk)(AlooWidget *widget);
};

/******************** Public ********************/

extern struct __alooLabel Label;

#endif // ALOO_LABEL_H