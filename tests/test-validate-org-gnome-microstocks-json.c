/* test-validate-org-gnome-microstocks-json.c
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

#include "stdlib.h"
#include "glib-object.h"
#include "json-glib/json-glib.h"

#include <glib.h>

gint
main (gint   argc,
      gchar *argv[])
{
	JsonParser *parser;
	JsonNode *root;
	GError *error;

	g_print(argv[1]);

	if (argv[1])
		{
			g_print ("Usage: test <filename.json>\n");
			return EXIT_FAILURE;
		}

	g_print("==========================================================");
	g_print(argv);
	return EXIT_FAILURE;

	parser = json_parser_new ();
	error = NULL;
	json_parser_load_from_file (parser, argv[1], &error);

	if (error)
		{
			g_print ("Unable to parse `%s': %s\n", argv[1],
				 error->message);
			g_error_free (error);
			g_object_unref (parser);
			return EXIT_FAILURE;
		}

	root = json_parser_get_root (parser);

	/* manipulate the object tree and then exit */

	g_object_unref (parser);
	return EXIT_SUCCESS;
}
