/* microstocks-app.c
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

#include "microstocks-app.h"

struct _MicrostocksApp
{
	GtkApplication parent;
};


G_DEFINE_TYPE (MicrostocksApp, microstocks_app, GTK_TYPE_APPLICATION)

MicrostocksApp *
microstocks_app_new (void)
{
	return g_object_new (MICROSTOCKS_TYPE_APP,
			     "application-id", "org.gnome.Microstocks",
			     "flags", G_APPLICATION_HANDLES_OPEN,
			     NULL);
}

static void
microstocks_app_finalize (GObject *object)
{
	G_OBJECT_CLASS (microstocks_app_parent_class)->finalize (object);
}

static void
microstocks_app_class_init (MicrostocksAppClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = microstocks_app_finalize;
}

static void
microstocks_app_init (MicrostocksApp *self)
{
}
