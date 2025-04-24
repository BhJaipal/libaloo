#include "common/grid.h"
#include "common/widget.h"
#include "utils/error.h"

AlooWidget __gridAttach(AlooWidget grid, AlooWidget child, int column,
						 int row, int width, int height) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_attach(__toGridGtk(grid), Widget.to_gtk(child), column, row, width,
					height);
	return grid;
}
AlooWidget __gridAttachGtk(AlooWidget grid, GtkWidget *child, int column,
							int row, int width, int height) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_attach(__toGridGtk(grid), child, column, row, width, height);
	return grid;
}

AlooWidget __gridRemove(AlooWidget grid, AlooWidget child) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_remove(__toGridGtk(grid), Widget.to_gtk(child));
	return grid;
}
AlooWidget __gridRemoveGtk(AlooWidget grid, GtkWidget *child) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_remove(__toGridGtk(grid), child);
	return grid;
}

AlooWidget __alooGridNew() { return Widget.new(ALOO_GRID, gtk_grid_new()); }

AlooWidget __setGridColumnSpacing(AlooWidget grid, int space) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_set_column_spacing(__toGridGtk(grid), space);
	return grid;
}

AlooWidget __setGridRowSpacing(AlooWidget grid, int space) {
	if (!Widget.check.isGrid(grid)) {
		throw_error("Invalid grid");
		return grid;
	}
	gtk_grid_set_row_spacing(__toGridGtk(grid), space);
	return grid;
}

GtkGrid *__toGridGtk(AlooWidget wid) {
	if (!Widget.check.isGrid(wid)) {
		throw_error("Invalid grid");
		return GTK_GRID(Grid.new()->child);
	}
	return GTK_GRID(wid->child);
}

struct _alooGrid Grid = {
	__gridAttach,  __gridAttachGtk,		   __gridRemove,		__gridRemoveGtk,
	__alooGridNew, __setGridColumnSpacing, __setGridRowSpacing, __toGridGtk,
};