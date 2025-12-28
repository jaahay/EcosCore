# tests/CMakeLists.txt

enable_testing()

add_executable(test_type_concepts tests/ecoscore/type/TestConcepts.cpp)
target_link_libraries(test_type_concepts PRIVATE ecoscore.type Catch2::Catch2)
add_test(NAME test_type_concepts COMMAND test_type_concepts)

add_executable(test_type_struct tests/ecoscore/type/TestStructType.cpp)
target_link_libraries(test_type_struct PRIVATE ecoscore.type Catch2::Catch2)
add_test(NAME test_type_struct COMMAND test_type_struct)
# tests/CMakeLists.txt additions for meta domain tests

add_executable(test_meta_cyclecheck tests/ecoscore/meta/TestCycleCheck.cpp)
target_link_libraries(test_meta_cyclecheck PRIVATE ecoscore.meta Catch2::Catch2)
add_test(NAME test_meta_cyclecheck COMMAND test_meta_cyclecheck)

add_executable(test_meta_tuple_concat tests/ecoscore/meta/TestTupleConcat.cpp)
target_link_libraries(test_meta_tuple_concat PRIVATE ecoscore.meta Catch2::Catch2)
add_test(NAME test_meta_tuple_concat COMMAND test_meta_tuple_concat)

add_executable(test_meta_typelist tests/ecoscore/meta/TestTypeList.cpp)
target_link_libraries(test_meta_typelist PRIVATE ecoscore.meta Catch2::Catch2)
add_test(NAME test_meta_typelist COMMAND test_meta_typelist)

add_executable(test_meta_variant tests/ecoscore/meta/TestVariant.cpp)
target_link_libraries(test_meta_variant PRIVATE ecoscore.meta Catch2::Catch2)
add_test(NAME test_meta_variant COMMAND test_meta_variant)
