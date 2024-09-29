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

AlooWidget *__newButton(AlooButtonType type);
AlooWidget *__newButtonWithLabel(const char *label, AlooButtonType type);
GtkButton *__toButtonGtk(AlooWidget *wid);

AlooWidget *__setLabel(AlooWidget *btn, char const *name);
AlooWidget *__setChild(AlooWidget *btn, AlooWidget *child);
AlooWidget *__setIcon(AlooWidget *btn, const char *child);
AlooWidget *__setUseUnderline(AlooWidget *btn, gboolean yes);

const char *__getLabel(AlooWidget *btn);
AlooWidget *__getChild(AlooWidget *btn);
const char *__getIcon(AlooWidget *btn);
gboolean __getUseUnderline(AlooWidget *btn);

/******************** Private Types ********************/

/** @brief type of material buttons */

/**
 * @brief An Structure that contains all the AlooButton related functions
 */
struct _alooButton {
	/// @brief Creates new Aloo Button without label
	AlooWidget *(*new)(AlooButtonType type);
	/// @brief Creates new Aloo Button with label
	AlooWidget *(*newWithLabel)(const char *label, AlooButtonType type);
	/// @brief Converts Aloo Button to Gtk Button
	GtkButton *(*toGtk)(AlooWidget *wid);
	struct {
		/// @brief Sets the label of the button
		AlooWidget *(*label)(AlooWidget *btn, char const *name);
		/// @brief Sets the child of the button
		AlooWidget *(*child)(AlooWidget *btn, AlooWidget *child);
		/// @brief Sets the icon of the button
		AlooWidget *(*icon)(AlooWidget *btn, const char *iconName);
		/// @brief Sets whether to use underline or not in the button
		AlooWidget *(*useUnderline)(AlooWidget *btn, gboolean yes);
	} set;
	struct {
		/// @brief Gets the label of the button
		const char *(*label)(AlooWidget *btn);
		/// @brief Gets the child of the button
		AlooWidget *(*child)(AlooWidget *btn);
		/// @brief Gets the icon of the button
		const char *(*icon)(AlooWidget *btn);
		/// @brief Gets whether to use underline or not in the button
		gboolean (*useUnderline)(AlooWidget *btn);
	} get;
};

/******************** Public ********************/

extern struct _alooButton Button;
#endif // ALOO_BUTTON_H