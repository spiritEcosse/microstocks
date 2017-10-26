/* microstocks-app.h
 *
 * Copyright (C) 2017 igor <shevchenkcoigor@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MICROSTOCKS_APP_H
#define MICROSTOCKS_APP_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MICROSTOCKS_APP_TYPE (microstocks_app_get_type())

G_DECLARE_FINAL_TYPE (MicrostocksApp, microstocks_app, MICROSTOCKS, APP, GtkApplication)

MicrostocksApp *microstocks_app_new (void);

G_END_DECLS

#endif /* MICROSTOCKS_APP_H */

