/**
 * @file grid.h
 * @author Jaipal001
 * @brief Aloo Grid related functions
 */
#ifndef ALOO_GRID_H
#define ALOO_GRID_H

#include "types.h"
#include <gtk/gtk.h>

/******************** Private Funcs ********************/

/**
 * @brief Adds widget to aloo grid
 * @param grid grid in which child should be added
 * @param child child to be added
 * @param column column in which it should be added
 * @param row row in which it should be added
 * @param width column span of widget or how many column it takes
 * @param height row span of widget or how many row it takes
 * @return returns grid back
 */
AlooWidget *__gridAttach(AlooWidget *grid, AlooWidget *child, int column,
						 int row, int width, int height);

/**
 * @brief Adds widget to aloo grid
 * @param grid grid in which child should be added
 * @param child child to be added
 * @param column column in which it should be added
 * @param row row in which it should be added
 * @param width column span of widget or how many column it takes
 * @param height row span of widget or how many row it takes
 * @return returns grid back
 */
AlooWidget *__gridAttachGtk(AlooWidget *grid, GtkWidget *child, int column,
							int row, int width, int height);
/// @brief Removes child from grid
/// @return returns grid back
AlooWidget *__gridRemove(AlooWidget *grid, AlooWidget *child);

/// @brief Removes child from grid
/// @return returns grid back
AlooWidget *__gridRemoveGtk(AlooWidget *grid, GtkWidget *child);

/// @brief Creates new Aloo Grid Widget
/// @return returns grid
AlooWidget *__alooGridNew();

/** @brief Set the Grid Column Spacing */
AlooWidget *__setGridColumnSpacing(AlooWidget *grid, int space);
/** @brief Set the Grid Row Spacing */
AlooWidget *__setGridRowSpacing(AlooWidget *grid, int space);

/******************** Private Types ********************/

struct _alooGrid {
	/**
	 * @brief Adds widget to aloo grid
	 * @param grid grid in which child should be added
	 * @param child child to be added
	 * @param column column in which it should be added
	 * @param row row in which it should be added
	 * @param width column span of widget or how many column it takes
	 * @param height row span of widget or how many row it takes
	 * @return returns grid back
	 */
	AlooWidget *(*attach)(AlooWidget *grid, AlooWidget *child, int column,
						  int row, int width, int height);
	/**
	 * @brief Adds widget to aloo grid
	 * @param grid grid in which child should be added
	 * @param child child to be added
	 * @param column column in which it should be added
	 * @param row row in which it should be added
	 * @param width column span of widget or how many column it takes
	 * @param height row span of widget or how many row it takes
	 * @return returns grid back
	 */
	AlooWidget *(*attachGtk)(AlooWidget *grid, GtkWidget *child, int column,
							 int row, int width, int height);
	/// @brief Removes child from grid
	/// @return returns grid back
	AlooWidget *(*remove)(AlooWidget *grid, AlooWidget *child);
	/// @brief Removes child from grid
	/// @return returns grid back
	AlooWidget *(*removeGtk)(AlooWidget *grid, GtkWidget *child);
	/// @brief Creates new Aloo Grid Widget
	/// @return returns grid
	AlooWidget *(*new)();
	/** @brief Set the Grid Column Spacing */
	AlooWidget *(*column_spacing)(AlooWidget *grid, int space);
	/** @brief Set the Grid Row Spacing */
	AlooWidget *(*row_spacing)(AlooWidget *grid, int space);
	/// @brief Returns Gtk Grid
	GtkGrid *(*toGtk)(AlooWidget *widget);
};

/******************** Public ********************/

extern struct _alooGrid Grid;

#endif // ALOO_GRID_H