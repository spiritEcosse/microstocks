microstocks_sources = [
  'main.c',
  'microstocks-app.c',
  'tree-node.c',
  'microstocks-window.c',
]

json_glib = dependency('json-glib-1.0', version : '>= 1.1.1')

microstocks_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
  dependency('libdazzle-1.0', version: '>= 3.22'),
]

gnome = import('gnome')

microstocks_sources += gnome.compile_resources('microstocks-resources',
  'microstocks.gresource.xml',
  c_name: 'microstocks'
)

executable('microstocks', microstocks_sources,

  dependencies: microstocks_deps,
  install: true,
)
