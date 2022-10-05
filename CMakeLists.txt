cmake_minimum_required(VERSION 3.22)
project(EmpresaVentaMas)

set(CMAKE_CXX_STANDARD 14)

add_executable(EmpresaVentaMas main.cpp Model/Clientes/Cliente.cpp Model/Clientes/Cliente.h Model/Vendedores/Vendedor.cpp Model/Vendedores/Vendedor.h Model/Productos/Producto.cpp Model/Productos/Producto.h)
