/**
 * @file box.h
 * @author Jaipal001
 * @brief Aloo Box functions
 *
 * @version 0.1
 * @date 2024-09-06
 * @copyright Copyright (c) 2024
 */
#ifndef ALOO_BOX_H
#define ALOO_BOX_H
#include "types.h"
#include <gtk/gtk.h>

/******************** Private Funcs ********************/

/**
 * @brief Creates new aloo box
 * @param orientation Box orientation
 * @param spacing space in child
 */
AlooWidget *__new_alooBox(GtkOrientation orientation, int spacing);
/**
 * @brief Sets Box Orientation
 */
AlooWidget *__setBoxOrientation(AlooWidget *box, GtkOrientation orientation);
/**
 * @brief Gets Box Orientation
 */
GtkOrientation __getBoxOrientation(AlooWidget *box);
/**
 * @brief Appends `GtkWidget` child to box
 */
AlooWidget *__boxAppendGtk(AlooWidget *box, GtkWidget *widget);
/**
 * @brief Prepends `GtkWidget` child to box
 */
AlooWidget *__boxPrependGtk(AlooWidget *box, GtkWidget *widget);
/**
 * @brief Removes `GtkWidget` child from box
 */
AlooWidget *__boxRemoveGtk(AlooWidget *box, GtkWidget *widget);
/**
 * @brief Appends `AlooWidget` child to box
 */
AlooWidget *__boxAppend(AlooWidget *box, AlooWidget *widget);
/**
 * @brief Prepends `AlooWidget` child to box
 */
AlooWidget *__boxPrepend(AlooWidget *box, AlooWidget *widget);
/**
 * @brief Removes `AlooWidget` child from box
 */
AlooWidget *__boxRemove(AlooWidget *box, AlooWidget *widget);
/**
 * @brief Adds child after a certain widget of box
 * @return returns box
 */
AlooWidget *__boxInsertChildAfter(AlooWidget *box, AlooWidget *child,
								  AlooWidget *after);
/**
 * @brief Set Box Spacing
 */
AlooWidget *__setBoxSpacing(AlooWidget *box, int spacing);
/**
 * @brief Gets box spacing
 */
int __getBoxSpacing(AlooWidget *box);
/**
 * @brief Gets box homogeneous
 */
gboolean __getBoxHomogeneous(AlooWidget *box);
/**
 * @brief Sets box homogeneous
 */
AlooWidget *__setBoxHomogeneous(AlooWidget *box, gboolean homogeneous);

/**
 * @brief Gets Box baseline position
 */
GtkBaselinePosition __getBoxBaselinePosition(AlooWidget *box);
/**
 * @brief Sets Box baseline position
 */
AlooWidget *__setBoxBaselinePosition(AlooWidget *box,
									 GtkBaselinePosition position);
/**
 * @brief Returns Gtk Box
 */
GtkBox *__toGtk(AlooWidget *widget);

/******************** Private Types ********************/

/**
 * @brief An Structure that contains all the AlooBox related functions
 */
struct _alooBox {
	/// @brief Creates new Aloo Box
	AlooWidget *(*new)(GtkOrientation orientation, int spacing);
	AlooWidget *(*setOrientation)(AlooWidget *box, GtkOrientation orientation);
	/// @brief Gets Box Orientation
	GtkOrientation (*getOrientation)(AlooWidget *box);
	/// @brief Appends `GtkWidget` child to box
	AlooWidget *(*appendGtk)(AlooWidget *box, GtkWidget *widget);
	/// @brief Prepends `GtkWidget` child to box
	AlooWidget *(*prependGtk)(AlooWidget *box, GtkWidget *widget);
	/// @brief Removes `GtkWidget` child from box
	AlooWidget *(*removeGtk)(AlooWidget *box, GtkWidget *widget);
	/// @brief Appends `AlooWidget` child to box
	AlooWidget *(*append)(AlooWidget *box, AlooWidget *widget);
	/// @brief Prepends `AlooWidget` child to box
	AlooWidget *(*prepend)(AlooWidget *box, AlooWidget *widget);
	/// @brief Removes `AlooWidget` child from box
	AlooWidget *(*remove)(AlooWidget *box, AlooWidget *widget);
	/**
	 * @brief Adds child after a certain widget of box
	 * @return returns box
	 */
	AlooWidget *(*insertChildAfter)(AlooWidget *box, AlooWidget *child,
									AlooWidget *after);
	/// @brief Sets Box Spacing
	AlooWidget *(*setSpacing)(AlooWidget *box, int spacing);
	/// @brief Gets Box Spacing
	int (*getSpacing)(AlooWidget *box);
	/// @brief Gets box homogeneous
	gboolean (*getHomogeneous)(AlooWidget *box);
	/// @brief Sets box homogeneous
	AlooWidget *(*setHomogeneous)(AlooWidget *box, gboolean homogeneous);
	/// @brief Gets Box baseline position
	GtkBaselinePosition (*getBaselinePosition)(AlooWidget *box);
	/// @brief Sets Box baseline position
	AlooWidget *(*setBaselinePosition)(AlooWidget *box,
									   GtkBaselinePosition position);
	/// @brief Returns Gtk Box
	GtkBox *(*toGtk)(AlooWidget *widget);
};

/******************** Public ********************/

extern struct _alooBox Box;

#endif // ALOO_BOX_H