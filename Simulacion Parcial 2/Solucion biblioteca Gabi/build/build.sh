#!/bin/bash

# Directorios
SRC_DIR="../src"
INCLUDE_DIR="../include"
TEST_DIR="../Test"

# Archivos de salida
EXECUTABLE="pedidos"
TEST_EXECUTABLE="test_pedidos"

# Limpiar la compilación previa
echo "Limpiando compilaciones previas..."
rm -f $EXECUTABLE $TEST_EXECUTABLE

# Compilar el archivo principal del sistema de pedidos
echo "Compilando el sistema de pedidos..."
g++ -o $EXECUTABLE $SRC_DIR/Pedidos.cpp $SRC_DIR/main.cpp -I$INCLUDE_DIR

# Compilar las pruebas unitarias
echo "Compilando las pruebas unitarias..."
g++ -o $TEST_EXECUTABLE $TEST_DIR/UniTestPedidos.cpp $SRC_DIR/Pedidos.cpp -I$INCLUDE_DIR

# Verificar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación exitosa."
else
    echo "Error en la compilación."
    exit 1
fi

# Ejecutar el ejecutable del sistema de pedidos
echo "Ejecutando el sistema de pedidos..."
./$EXECUTABLE

# Ejecutar las pruebas unitarias
echo "Ejecutando las pruebas unitarias..."
./$TEST_EXECUTABLE

# Pausar la consola al final
echo "Presiona Enter para continuar..."
read -p ""
