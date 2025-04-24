/**
 * @file style.h
 * @author Jaipal001
 * @brief Aloo CSS related functions
 *
 * @version 0.1
 * @date 2024-09-06
 * @copyright Copyright (c) 2024
 */
#ifndef ALOO_STYLE_H
#define ALOO_STYLE_H
#include "types.h"

/******************** Private Funcs ********************/

/// @brief Import CSS file from path
/// @param name path of css file
void __importCssFromPath(const char *name);
/// @brief Import CSS file from content
/// @param content css content
/// @param length content length
void __importCssFromData(const char *content, gssize length);
/// @brief Import CSS file from content
/// @param file CSS GFile
void __importCssFromFile(GFile *file);

/** @brief Set the Width of widget */
AlooWidget __setWidth(AlooWidget wid, int width);
/** @brief Set the Height of widget */
AlooWidget __setHeight(AlooWidget wid, int height);
/** @brief Set the Width and Height of widget */
AlooWidget __setSize(AlooWidget wid, int width, int height);

/** @brief Adds class to widget */
AlooWidget __widgetAddClass(AlooWidget widget, char *class);
/** @brief Removes class from widget */
AlooWidget __widgetRemoveClass(AlooWidget widget, char *class);
/** @brief Gets classes of widget */
char **__getWidgetClasses(AlooWidget widget);
/** @brief Sets classes of widget */
AlooWidget __setWidgetClasses(AlooWidget widget, char **classes);

/******************** Private Types ********************/

struct _alooCSS {
	/// @brief Import CSS file from path
	/// @param name path of css file
	void (*importPath)(const char *name);
	/// @brief Import CSS file from content
	/// @param content css content
	/// @param length content length
	void (*importData)(const char *content, gssize length);
	/// @brief Import CSS file from content
	/// @param file CSS GFile
	void (*importFile)(GFile *file);
	/** @brief Set the Width of widget */
	AlooWidget (*setWidth)(AlooWidget wid, int width);
	/** @brief Set the Height of widget */
	AlooWidget (*setHeight)(AlooWidget wid, int height);
	/** @brief Set the Width and Height of widget */
	AlooWidget (*setSize)(AlooWidget wid, int width, int height);
	/** @brief Adds class to widget */
	AlooWidget (*addClass)(AlooWidget widget, char *class);
	/** @brief Removes class from widget */
	AlooWidget (*removeClass)(AlooWidget widget, char *class);
	/** @brief Gets classes of widget */
	char **(*getClasses)(AlooWidget widget);
	/** @brief Sets classes of widget */
	AlooWidget (*setClasses)(AlooWidget widget, char **classes);
};

/******************** Public ********************/

extern struct _alooCSS CSS;

#endif // ALOO_STYLE_H