INCLUDE_DIRECTORIES(${EIGEN_INCLUDE_DIR} ${QGLVIEWER_INCLUDE_DIR} ${QT_INCLUDES})

ADD_LIBRARY(pwn_tracker2_library  
  pwn_cloud_cache.cpp pwn_cloud_cache.h
  pwn_matcher_base.cpp pwn_matcher_base.h
  pwn_tracker.cpp pwn_tracker.h
  pwn_closer.cpp pwn_closer.h
  pwn_tracker_viewer.cpp pwn_tracker_viewer.h
  manifold_voronoi_extractor.cpp manifold_voronoi_extractor.h
)

TARGET_LINK_LIBRARIES(pwn_tracker2_library 
  pwn_boss
  pwn_core
  boss_map_building 
  boss_map 
  boss
  ${G2O_OPENGL_HELPER_LIBRARY}
  ${G2O_SOLVER_CSPARSE_EXTENSION}
  ${G2O_TYPES_SLAM3D} 
  ${G2O_CORE_LIBRARY} 
  ${G2O_STUFF_LIBRARY} 
  ${CSPARSE_LIBRARY}
  ${QGLVIEWER_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} 
  ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} 
  )


ADD_executable(pwn_slam_app pwn_slam_app.cpp)

TARGET_LINK_LIBRARIES(pwn_slam_app
  pwn_tracker2_library
  pwn_boss
  pwn_core
  boss_map_building 
  boss_map 
  boss
  ${G2O_OPENGL_HELPER_LIBRARY}
  ${G2O_SOLVER_CSPARSE_EXTENSION}
  ${G2O_TYPES_SLAM3D} 
  ${G2O_CORE_LIBRARY} 
  ${G2O_STUFF_LIBRARY} 
  ${CSPARSE_LIBRARY}
  ${QGLVIEWER_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} 
  ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} 
)

ADD_executable(pwn_slam_map_viewer pwn_slam_map_viewer.cpp)

TARGET_LINK_LIBRARIES(pwn_slam_map_viewer 
  pwn_tracker2_library
  pwn_boss
  pwn_core
  boss_map_building 
  boss_map 
  boss
  ${G2O_OPENGL_HELPER_LIBRARY}
  ${G2O_SOLVER_CSPARSE_EXTENSION}
  ${G2O_TYPES_SLAM3D} 
  ${G2O_CORE_LIBRARY} 
  ${G2O_STUFF_LIBRARY} 
  ${CSPARSE_LIBRARY}
  ${QGLVIEWER_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} 
  ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} 
)


ADD_executable(pwn_slam_calibrate_sensor pwn_slam_calibrate_sensor.cpp)

TARGET_LINK_LIBRARIES(pwn_slam_calibrate_sensor
  pwn_tracker2_library
  pwn_boss
  pwn_core
  boss_map_building 
  boss_map 
  boss
  ${G2O_OPENGL_HELPER_LIBRARY}
  ${G2O_SOLVER_CSPARSE_EXTENSION}
  ${G2O_TYPES_SLAM3D} 
  ${G2O_CORE_LIBRARY} 
  ${G2O_STUFF_LIBRARY} 
  ${CSPARSE_LIBRARY}
  ${QGLVIEWER_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} 
  ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} 
)