set(CPACK_PACKAGE_DESCRIPTION "Incendio")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Incendio")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Taipa Xu <taipaxu@gmail.com>")

    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt6core6 (>= 6.0), libqt6widgets6(>= 6.0), libqt6quick6 (>= 6.0), libqt6quickcontrols2-6 (>= 6.0)")

    set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

    install(TARGETS incendio
        RUNTIME DESTINATION bin
    )

    install(DIRECTORY ${PROJECT_BINARY_DIR}/src/qml/
        DESTINATION share/incendio/qml
    )

    install(FILES ./debian/incendio.desktop DESTINATION share/applications)
endif()


include(CPack)
