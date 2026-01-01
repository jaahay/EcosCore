# src/ecoscore/language/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

add_library(ecoscore.language STATIC)

# Define module interface files once
set(MODULE_FILES
    Lang.ixx
    TextRepresentation.ixx
    TextRepresentations.ixx
    Encodings.ixx
    Charsets.ixx
    Language.ixx
    Languages.ixx
    Locale.ixx
    NameSet.ixx
    Translation.ixx
    Translations.ixx

    # Charsets
    charset/Cyrillic.ixx
    charset/Emoji.ixx
    charset/Latin1.ixx

    # Encodings
    encoding/MacRoman.ixx
    encoding/UTF32.ixx
    encoding/Windows1252.ixx

    # Language identities
    lang/ar.ixx
    lang/de.ixx
    lang/en.ixx
    lang/es.ixx
    lang/fr.ixx
    lang/ja.ixx
    lang/ko.ixx
    lang/zh_hans.ixx
    lang/zh_hant.ixx

    # Language translations
    lang/translations/en.ixx
    # lang/translations/fr.ixx
    # lang/translations/de.ixx
    # ...
)

target_sources(ecoscore.language PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES ${MODULE_FILES}
)

target_include_directories(ecoscore.language PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.language PUBLIC cxx_std_23)

target_compile_options(ecoscore.language PRIVATE
    /W4 /WX
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++latest /permissive->
)

set_target_properties(ecoscore.language PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_MODULE_STD 1
)

target_link_libraries(ecoscore.language PRIVATE ecoscore.category)

source_group(
    TREE ${CMAKE_SOURCE_DIR}/src/ecoscore
    PREFIX "Source Files"
    FILES ${MODULE_FILES}
)
