gtest = dependency('gtest', main:true)
all_files = ['array_mask_test', 
             'array_test', 
             'guard_test', 
             'message_test', 
             'my_stream_test',
             'my_thread_test'
             'parallel_sort_test', 
             'sort_test', 
             'trait_test',
            ]
foreach name : all_files
    src_file = name + '.cc'
    test(name ,executable(name,
                    sources: src_file,
                    include_directories: src,
                dependencies: [gtest]
        )
    )
endforeach




