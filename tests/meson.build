exec = executable('test-application-exit-success',
	'test-application-exit-success.c',
	dependencies: microstocks_deps,
)
test('Application exit success', exec)

org_gnome_microstocks_json = custom_target("org-gnome-microstocks-json",
	input='org.gnome.Microstocks.json'
)

exec = executable('test-validate-org-gnome-microstocks-json',
	'test-validate-org-gnome-microstocks-json.c',
	dependencies: microstocks_deps,
	args: [org_gnome_microstocks_json.full_path()]
)
test('Test validate org gnome microstocks json', exec)

# exec = executable('test-settings-window',
#     'test-settings-window.c',
#     dependencies: lib_dep,
# )
# test('test-settings-window', exec)
