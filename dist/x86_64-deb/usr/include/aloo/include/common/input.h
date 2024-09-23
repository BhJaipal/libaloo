/**
 * @file input.h
 * @author Jaipal001
 * @brief Aloo Input related functions
 * @version 0.1
 * @date 2024-09-06
 * @copyright Copyright (c) 2024
 */

#ifndef ALOO_INPUT_H
#define ALOO_INPUT_H
#include "types.h"

/******************** Private Funcs ********************/

AlooWidget *__input_new();
const char *__input_get_val(AlooWidget *input);
GtkEditable *__input_to_gtk(AlooWidget *input);

/******************** Private Types ********************/

/**
 * @brief An Structure that contains all the AlooInput related functions
 */
struct __alooInput {
	/// @brief Creates new Aloo Input
	AlooWidget *(*new)();
	/// @brief Gets the value of the input
	const char *(*getValue)(AlooWidget *input);
	/// @brief Converts Aloo Input to Gtk Input
	/// @param input input aloo Widget
	/// @return Gtk Editable
	GtkEditable *(*toGtk)(AlooWidget *input);
};

extern struct __alooInput Input;

#endif // ALOO_INPUT_H