add_executable (scg3_example
    main.cpp)

get_property(type GLOBAL PROPERTY library_type)

if(type STREQUAL "static")
	include_directories(${CMAKE_SOURCE_DIR}/libscg3)
	target_compile_definitions(scg3_example PUBLIC USE_SCG3_STATIC)
endif()

target_link_libraries(scg3_example ${LIBRARY_NAME} ${LIBS})

install(TARGETS scg3_example
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
