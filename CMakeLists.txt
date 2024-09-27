cmake_minimum_required(VERSION 3.23)
project(Laundromat)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laundromat main.cpp ObjPool.h ObjPool_impl.h Washer.cpp Washer.h Dryer.cpp Dryer.h Laundromat.h Laundromat.cpp Kiosk.cpp Kiosk.h Customer.cpp Customer.h)
