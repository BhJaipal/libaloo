/**
 * @file button.h
 * @author Jaipal001
 * @brief Aloo Button related functions
 *
 * @version 0.1
 * @date 2024-09-06
 * @copyright Copyright (c) 2024
 */
#ifndef ALOO_BUTTON_H
#define ALOO_BUTTON_H
#include "types.h"

/******************** Private Funcs ********************/

AlooWidget *__newButton();
AlooWidget *__newButtonWithLabel(const char *label);
AlooWidget *__setLabel(AlooWidget *btn, char const *name);
AlooWidget *__setChild(AlooWidget *btn, AlooWidget *child);
AlooWidget *__setIcon(AlooWidget *btn, const char *child);
AlooWidget *__setUseUnderline(AlooWidget *btn, gboolean yes);
GtkButton *__toButtonGtk(AlooWidget *wid);

/******************** Private Types ********************/

/**
 * @brief An Structure that contains all the AlooButton related functions
 */
struct _alooButton {
	/// @brief Creates new Aloo Button without label
	AlooWidget *(*new)();
	/// @brief Creates new Aloo Button with label
	AlooWidget *(*newWithLabel)(const char *label);
	/// @brief Sets the label of the button
	AlooWidget *(*label)(AlooWidget *btn, char const *name);
	/// @brief Sets the child of the button
	AlooWidget *(*child)(AlooWidget *btn, AlooWidget *child);
	/// @brief Sets the icon of the button
	AlooWidget *(*icon)(AlooWidget *btn, const char *child);
	/// @brief Sets whether to use underline or not in the button
	AlooWidget *(*useUnderline)(AlooWidget *btn, gboolean yes);
	/// @brief Converts Aloo Button to Gtk Button
	GtkButton *(*toGtk)(AlooWidget *wid);
};

/******************** Public ********************/

extern struct _alooButton Button;

#endif // ALOO_BUTTON_H