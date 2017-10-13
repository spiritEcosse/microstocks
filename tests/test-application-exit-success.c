/* test-application.c
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


#include <glib.h>
#include <locale.h>
#include "microstocks-config.h"


static void
test_application_exist_success (void)
{
	g_autoptr(GtkApplication) app = NULL;
	int ret;

	app = gtk_application_new("org.gnome.Microstocks", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
}

int
main (int  argc,
      char **argv)
{
	setlocale (LC_ALL, "");

	g_test_init (&argc, &argv, NULL);
	g_test_add_func ("/Microstocks/ApplicationExitSuccess",
			 test_application_exist_success
	);

	return g_test_run ();
}
