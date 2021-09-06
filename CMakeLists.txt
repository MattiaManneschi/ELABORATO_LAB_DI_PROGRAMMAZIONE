cmake_minimum_required(VERSION 3.20)
project(ELABORATO_LAB_DI_PROGRAMMAZIONE)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

#add_executable(ELABORATO_LAB_DI_PROGRAMMAZIONE main.cpp User.cpp User.h ShoppingList.cpp ShoppingList.h Subject.cpp Subject.h Observer.cpp Observer.h View.cpp View.h Controller.cpp Controller.h)

set(SOURCE_FILES User.cpp User.h ShoppingList.cpp ShoppingList.h Subject.cpp Subject.h Observer.cpp Observer.h View.cpp View.h Controller.cpp Controller.h)
add_executable(my_executable main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(my_executable core)
