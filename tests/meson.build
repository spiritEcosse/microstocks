exec = executable('test-application-exit-success',
	'test-application-exit-success.c',
	dependencies: microstocks_deps,
)
test('Application exit success', exec)

exec = executable('test-validate-org-gnome-microstocks-json',
	'test-validate-org-gnome-microstocks-json.c',
	dependencies: microstocks_deps,
	link_args: ['org.gnome.Microstocks.json']
)
test('Test validate org gnome microstocks json', exec)

# exec = executable('test-settings-window',
#     'test-settings-window.c',
#     dependencies: lib_dep,
# )
# test('test-settings-window', exec)
