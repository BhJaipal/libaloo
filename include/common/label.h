/**
 * @file label.h
 * @author Jaipal001
 * @brief Aloo Label related functions
 */
#ifndef ALOO_LABEL_H
#define ALOO_LABEL_H
#include "types.h"

/******************** Private Funcs ********************/

AlooWidget *__newLabel(const char *val);

/******************** Private Types ********************/

struct __alooLabel {
	/// @brief Creates new Aloo label
	/// @param  val label text
	/// @return Aloo Label
	AlooWidget *(*new)(const char *val);
	/// @brief Converts Aloo label to Gtk label
	GtkLabel *(*toGtk)(AlooWidget *wid);
};

/******************** Public ********************/

extern struct __alooLabel Label;

#endif // ALOO_LABEL_H