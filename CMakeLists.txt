cmake_minimum_required(VERSION 3.22)
project(EmpresaVentaMas)

set(CMAKE_CXX_STANDARD 14)

add_executable(EmpresaVentaMas main.cpp Model/Cliente.cpp Model/Vendedores/Vendedor.cpp  Model/Producto.cpp Model/Ventas/Venta.cpp Model/Ventas/Venta.h Controller/Login/Login.cpp Controller/ProductoController.cpp Controller/ProductoController.h Controller/VendedorController.cpp Controller/ClienteController.cpp)
