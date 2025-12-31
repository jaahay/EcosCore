# src/ecoscore/language/CMakeLists.txt
cmake_minimum_required(VERSION 3.28)

add_library(ecoscore.language STATIC)

target_sources(ecoscore.language PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES
    FILES
        Lang.ixx
        TextRepresentation.ixx
        TextRepresentations.ixx
        Encodings.ixx
        Charsets.ixx
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

target_include_directories(ecoscore.language PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_compile_features(ecoscore.language PUBLIC cxx_std_20)

target_compile_options(ecoscore.language PRIVATE
    /W4 /WX
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++20 /experimental:module /permissive->
)

target_link_libraries(ecoscore.language ecoscore.state)