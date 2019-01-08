src_merge = files(['main_task3.cc'])
thread_dep = dependency('threads')
executable('message',
    include_directories: src,
    sources: src_task3,
    dependencies: [],
    install: true
)

src_numeration = files(['main_task8.cc'])
executable('parallel_sort_merge',
    include_directories: src,
    sources: src_task8,
    dependencies: [thread_dep],
    install: true
)


