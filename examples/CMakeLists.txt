# examples/CMakeLists.txt

add_executable(example_template_type examples/ecoscore/type/ExampleTemplateType.cpp)
target_link_libraries(example_template_type PRIVATE ecoscore.type)

add_executable(example_singleton_tag examples/ecoscore/type/ExampleSingletonTag.cpp)
target_link_libraries(example_singleton_tag PRIVATE ecoscore.type)
# examples/CMakeLists.txt additions for meta domain examples

add_executable(example_meta_cyclecheck examples/ecoscore/meta/ExampleCycleCheck.cpp)
target_link_libraries(example_meta_cyclecheck PRIVATE ecoscore.meta)

add_executable(example_meta_tuple_concat examples/ecoscore/meta/ExampleTupleConcat.cpp)
target_link_libraries(example_meta_tuple_concat PRIVATE ecoscore.meta)
