cmake_minimum_required(VERSION 3.27)
project(tik_tak_toe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(widgets
        widgets/mainWindow.cpp
        widgets/mainWindow.h
        widgets/winnerWindow.cpp
        widgets/winnerWindow.h
)
set(source
        source/Abstract.cpp
        source/Abstract.h
)

add_executable(${PROJECT_NAME} main.cpp ${widgets} ${source})
target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
