# LIBRARY_FOLDER
if(NOT LIBRARY_FOLDER)
  set(LIBRARY_FOLDER ${LIBRARY_NAME})
endif()

# INSTALL_LIB_DIR
set(INSTALL_LIB_DIR lib
    CACHE PATH "Relative instalation path for libraries")

# INSTALL_BIN_DIR
set(INSTALL_BIN_DIR bin
    CACHE PATH "Relative instalation path for executables")

# INSTALL_INCLUDE_DIR
set(INSTALL_INCLUDE_DIR include
    CACHE PATH "Relative instalation path for header files")

option(BUILD_SHARED_LIBS "Build ${_PN} as a shared library." ON)
if(BUILD_SHARED_LIBS)
  set(LIBRARY_TYPE SHARED)
  message(STATUS "Building as shared library.")
else()
  set(LIBRARY_TYPE STATIC)
  message(STATUS "Building as static library.")
endif()

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release'.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)

  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Set HEADERS variable
file(GLOB_RECURSE HEADERS
	"${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/*.inl"
)

# Set SOURCES variable
file(GLOB_RECURSE SOURCES
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Target
add_library(${LIBRARY_NAME} ${LIBRARY_TYPE} ${SOURCES} ${HEADERS})
target_compile_options(${LIBRARY_NAME} PUBLIC "-DGLEW_STATIC")

if (APPLE)
	set(LIBS "-lglfw3" "-framework Cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreVideo")
	target_link_libraries(${LIBRARY_NAME} ${LIBS})
elseif()
	# Check for required packages
	find_package(OpenGL REQUIRED)
	find_package(GLUT REQUIRED)
	find_package(X11 REQUIRED)
	find_package(glfw3 REQUIRED)
	# Libraries
	set(LIBS ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${X11_LIBRARIES} ${GLUT_LIBRARY} glfw Xrandr Xxf86vm)
endif()

# Install library
install(TARGETS ${LIBRARY_NAME} EXPORT ${PROJECT_EXPORT}
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}"
  ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
)

# Install Headers
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}" DESTINATION ${INSTALL_INCLUDE_DIR}
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp" PATTERN "*.inl"
)