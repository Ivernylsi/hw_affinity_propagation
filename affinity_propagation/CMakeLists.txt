add_library(aff_prop
            src/AffinityPropagation.cpp
            src/Graph.cpp
            )

target_include_directories(aff_prop PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

target_link_libraries(aff_prop Eigen3::Eigen)
