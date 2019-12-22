cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c displayOptions.c displayOptions.h getOrder.c getOrder.h defines.h displayOrder.c displayOrder.h parseData.c parseData.h login.c login.h product.c food.c food.h product.h)