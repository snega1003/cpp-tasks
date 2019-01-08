myproject_src = files(['main.cc'])
thread_dep = dependency('threads')
executable('project',
    include_directories: src,
    sources: myproject_src,
    dependencies: [thread_dep],
    install: true
)
