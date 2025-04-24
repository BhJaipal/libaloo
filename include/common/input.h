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

AlooWidget __input_new(char *label);
GtkEditable *__input_to_gtk(AlooWidget input);

AlooWidget __input_insert_text(AlooWidget input, const char *text,
								int text_length, int *position);
AlooWidget __input_append_text(AlooWidget input, const char *text,
								int text_length);
AlooWidget __input_prepend_text(AlooWidget input, const char *text,
								 int text_length);
AlooWidget __input_deleteText(AlooWidget input, int start, int end);
AlooWidget __input_deleteSelection(AlooWidget input, int start, int end);

// getters
const char *__input_get_val(AlooWidget input);
gboolean __input_get_isEditable(AlooWidget input);
guint64 __input_get_value_length(AlooWidget input);
gboolean __input_get_isUndo_enabled(AlooWidget input);
gint __input_get_position(AlooWidget input);
gfloat __input_get_alignment(AlooWidget input);
AlooWidget __input_get_Selected(AlooWidget input, int *start, int *end);

// setters
AlooWidget __input_set_isEditable(AlooWidget input, gboolean editable);
AlooWidget __input_select(AlooWidget input, int start, int end);
AlooWidget __input_set_val(AlooWidget input, const char *value);
AlooWidget __input_set_isUndo_enabled(AlooWidget input, gboolean enabled);
AlooWidget __input_set_position(AlooWidget input, gint position);
AlooWidget __input_set_alignment(AlooWidget input, gfloat alignment);

/******************** Private Types ********************/

/**
 * @brief An Structure that contains all the AlooInput related functions
 */
struct __alooInput {
	/// @brief Creates new Aloo Input
	AlooWidget (*new)(char *label);
	/// @brief Converts Aloo Input to Gtk Input
	/// @param input input aloo Widget
	/// @return Gtk Editable
	GtkEditable *(*toGtk)(AlooWidget input);
	/// @brief Gets the value length of the input
	/// @param input input aloo Widget
	guint64 (*getValueLength)(AlooWidget input);
	/// @brief Inserts text in the input at a position
	AlooWidget (*insertText)(AlooWidget input, const char *text,
							  int text_length, int *position);
	/// @brief Inserts text in the input to end of input
	AlooWidget (*appendText)(AlooWidget input, const char *text,
							  int text_length);
	/// @brief Inserts text in the input to start of input
	AlooWidget (*prependText)(AlooWidget input, const char *text,
							   int text_length);

	AlooWidget (*deleteText)(AlooWidget input, int start, int end);
	AlooWidget (*deleteSelection)(AlooWidget input, int start, int end);
	struct {
		/// @brief Gets the value of the input
		AlooWidget (*value)(AlooWidget input, const char *value);
		AlooWidget (*position)(AlooWidget input, gint position);
		AlooWidget (*select_text)(AlooWidget input, int start, int end);
		/// @brief Sets input to editable or not
		/// @param input input aloo Widget
		AlooWidget (*isEditable)(AlooWidget input, gboolean editable);
		AlooWidget (*alignment)(AlooWidget input, gfloat alignment);
		AlooWidget (*undoEnabled)(AlooWidget input, gboolean enabled);
	} set;
	struct {
		/// @brief Gets the value of the input
		const char *(*value)(AlooWidget input);
		gint (*position)(AlooWidget input);
		/// @brief Returns is input is editable or not
		/// @param input input aloo Widget
		gboolean (*isEditable)(AlooWidget input);
		gfloat (*alignment)(AlooWidget input);
		gboolean (*isUndoEnabled)(AlooWidget input);
		AlooWidget (*selected)(AlooWidget input, int *start, int *end);
	} get;
};

extern struct __alooInput Input;

#endif // ALOO_INPUT_H
