# src/ecoscore/language/CMakeLists.txt
add_library(ecoscore.language STATIC)

target_sources(ecoscore.language PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        Language.ixx
        TextRepresentations.ixx
        CharsetTags.ixx
        EncodingTags.ixx
        LanguageTags.ixx
        NameSet.ixx
        LocalizedName.ixx
)

target_include_directories(ecoscore.language PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.language PUBLIC cxx_std_20)
