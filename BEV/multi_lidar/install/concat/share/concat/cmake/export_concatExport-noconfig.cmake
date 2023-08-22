#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "concat::pointcloud_preprocessor_filter_base" for configuration ""
set_property(TARGET concat::pointcloud_preprocessor_filter_base APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(concat::pointcloud_preprocessor_filter_base PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpointcloud_preprocessor_filter_base.so"
  IMPORTED_SONAME_NOCONFIG "libpointcloud_preprocessor_filter_base.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS concat::pointcloud_preprocessor_filter_base )
list(APPEND _IMPORT_CHECK_FILES_FOR_concat::pointcloud_preprocessor_filter_base "${_IMPORT_PREFIX}/lib/libpointcloud_preprocessor_filter_base.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
