/* microstocks-window.c
 *
 * Copyright (C) 2017 igor
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

#include "microstocks-window.h"

struct _MicrostocksWindow
{
  GtkApplicationWindow  parent;

  /* Template widgets */
  GtkHeaderBar        *header_bar;
  GtkLabel            *label;
};

typedef struct _MicrostocksWindowPrivate MicrostocksWindowPrivate;

struct _MicrostocksWindowPrivate
{
};

G_DEFINE_TYPE_WITH_PRIVATE (MicrostocksWindow,
			    microstocks_window,
			    GTK_TYPE_APPLICATION_WINDOW)

static void
microstocks_window_class_init (MicrostocksWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/org/gnome/Microstocks/microstocks-window.ui");
  gtk_widget_class_bind_template_child (widget_class, MicrostocksWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, MicrostocksWindow, label);
}

static void
microstocks_window_init (MicrostocksWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

MicrostocksWindow *
microstocks_window_new (MicrostocksApp *app)
{
  return g_object_new (MICROSTOCKS_WINDOW_TYPE, "application", app, NULL);
}

void
microstocks_window_open (MicrostocksWindow *win,
			 GFile            *file)
{
}

