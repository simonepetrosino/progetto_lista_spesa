cmake_minimum_required(VERSION 3.23)
project(progetto_lista_spesa)

set(CMAKE_CXX_STANDARD 14)

add_executable(progetto_lista_spesa main.cpp ShoppingList.cpp ShoppingList.h Item.cpp Item.h User.cpp User.h Subject.h Observer.h)
