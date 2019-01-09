gtest = dependency('gtest', main:true)
thread_dep = dependency('my_thread')
test('my_thread',executable('my_thread_test',
                sources: ['my_thread_test.cc', '../project/main.cc'],
                include_directories: src,
                dependencies: [gtest, thread_dep]
    )
    
)


