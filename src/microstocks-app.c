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

typedef struct
{

} MicrostocksAppPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (MicrostocksApp, microstocks_app, G_TYPE_APPLICATION)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

MicrostocksApp *
microstocks_app_new (void)
{
	return g_object_new (MICROSTOCKS_TYPE_APP, NULL);
}

static void
microstocks_app_finalize (GObject *object)
{
	MicrostocksApp *self = (MicrostocksApp *)object;
	MicrostocksAppPrivate *priv = microstocks_app_get_instance_private (self);

	G_OBJECT_CLASS (microstocks_app_parent_class)->finalize (object);
}

static void
microstocks_app_get_property (GObject    *object,
                              guint       prop_id,
                              GValue     *value,
                              GParamSpec *pspec)
{
	MicrostocksApp *self = MICROSTOCKS_APP (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
microstocks_app_set_property (GObject      *object,
                              guint         prop_id,
                              const GValue *value,
                              GParamSpec   *pspec)
{
	MicrostocksApp *self = MICROSTOCKS_APP (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
microstocks_app_class_init (MicrostocksAppClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = microstocks_app_finalize;
	object_class->get_property = microstocks_app_get_property;
	object_class->set_property = microstocks_app_set_property;
}

static void
microstocks_app_init (MicrostocksApp *self)
{
}
