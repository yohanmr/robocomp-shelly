cmake_minimum_required(VERSION 2.6)
PROJECT( baseursuscomp )
IF(NOT EXISTS $ENV{ROBOCOMP}/cmake)
MESSAGE(FATAL_ERROR "
 ROBOCOMP variable not set, check your bashrc profile!
")
ENDIF(NOT EXISTS $ENV{ROBOCOMP}/cmake)
INCLUDE( $ENV{ROBOCOMP}/cmake/robocomp.cmake )
INCLUDE ( CMakeListsSpecific.txt)

# Sources set
SET ( SOURCES
  ${SOURCES}
  baseursuscomp.cpp
  omnirobotI.cpp
  differentialrobotI.cpp
  genericbaseI.cpp
  genericmonitor.cpp
  commonbehaviorI.cpp
  genericworker.cpp
  $ENV{ROBOCOMP}/classes/rapplication/rapplication.cpp
  $ENV{ROBOCOMP}/classes/qlog/qlog.cpp
)

#ROBOCOMP
ROBOCOMP_INITIALIZE( $ENV{ROBOCOMP}/ )
ROBOCOMP_WRAP_ICE( CommonBehavior  OmniRobot DifferentialRobot  JointMotor GenericBase)
SET (EXECUTABLE_OUTPUT_PATH ../bin)

# Qt4
ADD_DEFINITIONS( -Wall -DQT_DLL -DQT_GUI_LIB -DQT_CORE_LIB )
FIND_PACKAGE( Qt4 REQUIRED )
SET( QT_USE_QTGUI TRUE )
SET( QT_USE_QTOPENGL TRUE )
SET( QT_USE_QTXML TRUE )
SET( QT_USE_QTSTATE TRUE )
SET( QT_USE_QTSTATEMACHINE TRUE )
INCLUDE( ${QT_USE_FILE} )
SET( CMAKE_AUTOMOC TRUE )

# Specify construction and link process
ADD_EXECUTABLE( baseursuscomp ${SOURCES} ${MOC_SOURCES} ${RC_SOURCES} ${UI_HEADERS} )
TARGET_LINK_LIBRARIES( baseursuscomp ${QT_LIBRARIES} ${LIBS} ${STATIC_LIBS} ${SPECIFIC_LIBS})
INSTALL(FILES ${EXECUTABLE_OUTPUT_PATH}/baseursuscomp DESTINATION /opt/robocomp/bin/ PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE )
