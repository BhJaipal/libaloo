/**
 * @file macros.h
 * @author Jaipal001
 * @brief It contains Macros of Aloo Project
 *
 * @version 0.1
 * @date 2024-09-06
 * @copyright Copyright (c) 2024
 */
#ifndef ALOO_MACROS_H
#define ALOO_MACROS_H
#include "types.h"

/**
 * @brief Returns `GTK_GRID` of Aloo Widget
 * @param widget AlooWidget with `ALOO_GRID` type
 */
#define ALOO_GRID_TO_GTK(widget) GTK_GRID(widget->child)

/**
 * @brief generates app options with APP_FLAGS_NONE
 */
#define NONE_FLAGS_OPTIONS(argc, argv)                                         \
	{ APP_FLAGS_NONE, argc, argv }
/**
 * @brief generates app options with APP_FLAGS_IS_LAUNCHER
 */
#define LAUNCHER_FLAGS_OPTIONS(argc, argv)                                     \
	{ APP_FLAGS_IS_LAUNCHER, argc, argv }
/**
 * @brief generates app options with APP_FLAGS_IS_SERVICE
 */
#define SERVICE_FLAGS_OPTIONS(argc, argv)                                      \
	{ APP_FLAGS_IS_SERVICE, argc, argv }

#endif // ALOO_MACROS_H