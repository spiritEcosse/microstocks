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
#include "microstocks-window.h"

struct _MicrostocksApp
{
	GtkApplication parent;
};

G_DEFINE_TYPE (MicrostocksApp, microstocks_app, GTK_TYPE_APPLICATION)

MicrostocksApp *
microstocks_app_new (void)
{
	return g_object_new (MICROSTOCKS_APP_TYPE,
			     "application-id", "org.gnome.Microstocks",
			     "flags", G_APPLICATION_HANDLES_OPEN,
			     NULL);
}

static void
quit_activated (GSimpleAction *action,
                GVariant      *parameter,
                gpointer       app)
{
	g_application_quit (G_APPLICATION (app));
}


static GActionEntry app_entries[] =
{
	{ "quit", quit_activated, NULL, NULL, NULL }
};


static void
microstocks_app_startup (GApplication *app)
{
	GtkBuilder *builder;
	GMenuModel *app_menu;
	const gchar *quit_accels[2] = { "<Ctrl>Q", NULL };

	G_APPLICATION_CLASS (microstocks_app_parent_class)->startup (app);

	g_action_map_add_action_entries (G_ACTION_MAP (app),
					 app_entries, G_N_ELEMENTS (app_entries),
					 app);
	gtk_application_set_accels_for_action (GTK_APPLICATION (app),
					       "app.quit",
					       quit_accels);

	builder = gtk_builder_new_from_resource ("/org/gnome/Microstocks/app-menu.ui");
	app_menu = G_MENU_MODEL (gtk_builder_get_object (builder, "appmenu"));
	gtk_application_set_app_menu (GTK_APPLICATION (app), app_menu);
	g_object_unref (builder);
}

static void
microstocks_app_activate (GApplication *app)
{
	MicrostocksWindow *window;

	window = microstocks_window_new (MICROSTOCKS_APP (app));
	gtk_window_present (GTK_WINDOW (window));
}

static void
microstocks_app_open (GApplication  *app,
		      GFile        **files,
		      gint           n_files,
		      const gchar   *hint)
{
	  GList *windows;
	  MicrostocksWindow *window;
	  int i;

	  windows = gtk_application_get_windows (GTK_APPLICATION (app));
	  if (windows)
		window = MICROSTOCKS_WINDOW (windows->data);
	  else
		window = microstocks_window_new (MICROSTOCKS_APP (app));

	  for (i = 0; i < n_files; i++)
		microstocks_window_open (window, files[i]);

	  gtk_window_present (GTK_WINDOW (window));
}

static void
microstocks_app_class_init (MicrostocksAppClass *class)
{
	G_APPLICATION_CLASS (class)->startup = microstocks_app_startup;
	G_APPLICATION_CLASS (class)->activate = microstocks_app_activate;
	G_APPLICATION_CLASS (class)->open = microstocks_app_open;
}

static void
microstocks_app_init (MicrostocksApp *self)
{
}
