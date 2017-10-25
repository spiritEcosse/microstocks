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
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkHeaderBar        *header_bar;
  GtkLabel            *label;
};

G_DEFINE_TYPE (MicrostocksWindow, microstocks_window, GTK_TYPE_APPLICATION_WINDOW)

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
  return g_object_new (MICROSTOCKS_TYPE_WINDOW, "application", app, NULL);
}

void
microstocks_window_open (MicrostocksWindow *win,
                         GFile            *file)
{
	  ExampleAppWindowPrivate *priv;
	  gchar *basename;
	  GtkWidget *scrolled, *view;
	  gchar *contents;
	  gsize length;
	  GtkTextBuffer *buffer;
	  GtkTextTag *tag;
	  GtkTextIter start_iter, end_iter;

	  priv = example_app_window_get_instance_private (win);
	  basename = g_file_get_basename (file);

	  scrolled = gtk_scrolled_window_new (NULL, NULL);
	  gtk_widget_show (scrolled);
	  gtk_widget_set_hexpand (scrolled, TRUE);
	  gtk_widget_set_vexpand (scrolled, TRUE);
	  view = gtk_text_view_new ();
	  gtk_text_view_set_editable (GTK_TEXT_VIEW (view), FALSE);
	  gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (view), FALSE);
	  gtk_widget_show (view);
	  gtk_container_add (GTK_CONTAINER (scrolled), view);
	  gtk_stack_add_titled (GTK_STACK (priv->stack), scrolled, basename, basename);

	  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));

	  if (g_file_load_contents (file, NULL, &contents, &length, NULL, NULL))
	    {
	      gtk_text_buffer_set_text (buffer, contents, length);
	      g_free (contents);
	    }

	  tag = gtk_text_buffer_create_tag (buffer, NULL, NULL);
	  g_settings_bind (priv->settings, "font",
		           tag, "font",
		           G_SETTINGS_BIND_DEFAULT);

	  gtk_text_buffer_get_start_iter (buffer, &start_iter);
	  gtk_text_buffer_get_end_iter (buffer, &end_iter);
	  gtk_text_buffer_apply_tag (buffer, tag, &start_iter, &end_iter);

	  g_free (basename);

	  gtk_widget_set_sensitive (priv->search, TRUE);

	  update_words (win);
	  update_lines (win);
}

