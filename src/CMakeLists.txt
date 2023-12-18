cmake_minimum_required(VERSION 3.27)
project(Lollo)

set(CMAKE_CXX_STANDARD 17)

set( CMAKE_BUILD_TYPE Debug )
# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add executable target
add_executable(Lollo main.cpp
        Model/ToDoItem.cpp
        Model/ToDoItem.h
        Model/ToDoList.cpp
        Model/ToDoList.h
        Control/Control.cpp
        Control/Control.h
        View/View.cpp
        View/View.h
        View/ToDoApp.cpp
        View/ToDoApp.h
        View/Frame.cpp
        View/Frame.h
        Model/Model.cpp
        Model/Model.h
)

# Include wxWidgets headers
target_include_directories(Lollo PRIVATE ${wxWidgets_INCLUDE_DIRS})

# Link against wxWidgets libraries
target_link_libraries(Lollo PRIVATE ${wxWidgets_LIBRARIES})


