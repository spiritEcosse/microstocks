exec = executable('test-application-exit-success',
	'test-application-exit-success.c',
	dependencies: microstocks_deps,
)
test('Application exit success', exec)

install_data(['/home/igor/projects/microstocks/org.gnome.Microstocks.json'],
	install_dir: meson.source_root()
)

exec = executable('test-validate-org-gnome-microstocks-json',
	'parser.c',
	install: true,
	install_dir: installed_test_bindir,
	dependencies: [json_glib],
)
test('Test validate org gnome microstocks json', exec)

# exec = executable('test-settings-window',
#     'test-settings-window.c',
#     dependencies: lib_dep,
# )
# test('test-settings-window', exec)
