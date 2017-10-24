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
#include <glib.h>
#include "json-glib/json-glib.h"

static void
test_org_gnome_sync(void) {
	JsonParser *parser;
	GFile *file;
	GFileInputStream *stream;
	JsonNode *root;
	GError *error = NULL;
	char *path;
	JsonArray *array;

	parser = json_parser_new ();

	path = g_test_build_filename (G_TEST_DIST, "org.gnome.Microstocks.json", NULL);
	file = g_file_new_for_path (path);
	stream = g_file_read (file, NULL, &error);
	g_assert_no_error (error);
	g_assert (stream != NULL);

	json_parser_load_from_stream (parser, G_INPUT_STREAM (stream), NULL, &error);
	g_assert_no_error (error);

	root = json_parser_get_root (parser);
	g_assert (root != NULL);

	array = json_node_get_array (root);
	g_assert_cmpint (json_array_get_length (array), ==, 1);
	g_assert (JSON_NODE_HOLDS_OBJECT (json_array_get_element (array, 0)));
	g_assert (json_array_equal (array, {
					  "app-id": "org.gnome.Microstocks",
					  "runtime": "org.gnome.Platform",
					  "runtime-version": "3.26",
					  "sdk": "org.gnome.Sdk",
					  "command": "microstocks",
					  "finish-args": [
					    "--share=network",
					    "--share=ipc",
					    "--socket=x11",
					    "--socket=wayland",
					    "--filesystem=xdg-run/dconf",
					    "--filesystem=~/.config/dconf:ro",
					    "--talk-name=ca.desrt.dconf",
					    "--env=DCONF_USER_CONFIG_DIR=.config/dconf"
					  ],
					  "build-options": {
					    "cflags": "-O2 -g",
					    "cxxflags": "-O2 -g",
					    "env": {
					      "V": "1"
					    }
					  },
					  "cleanup": [
					    "/include",
					    "/lib/pkgconfig",
					    "/man",
					    "/share/doc",
					    "/share/gtk-doc",
					    "/share/man",
					    "/share/pkgconfig",

					    "*.la",
					    "*.a"
					  ],
					  "modules": [
					    {
					      "name": "microstocks",
					      "buildsystem": "meson",
					      "config-opts": [
						"--libdir=lib"
					      ],
					      "builddir": true,
					      "sources": [
						{
						  "type": "git",
						  "url": "file:///home/igor/projects/microstocks"
						}
					      ]
					    }
					  ]
					}
				     ));

	g_free (path);
}

gint
main (gint   argc,
      gchar *argv[])
{
	g_test_init(&argc, &argv, NULL);
	g_test_add_func("/parser/org-gnome-sync", test_org_gnome_sync);
	return g_test_run();
}
