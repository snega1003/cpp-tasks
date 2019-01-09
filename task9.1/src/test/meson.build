gtest = dependency('gtest', main:true)
all_files = ['array_mask_test', 
             'array_test', 
             'guard_test', 
             'message_test', 
             'my_stream_test',
             'rotate_test'
             'parallel_sort_test', 
             'sort_test', 
             'trait_test',
            ]
foreach file : all_files
    src_file = file + '.cc'
    test(file ,executable(file,
                    sources: src_file,
                    include_directories: src,
                dependencies: [gtest]
        )
    )
endforeach




