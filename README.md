# GRUPO 3: Sistema de Inventario de Productos

## Enunciado
Implementar un sistema que gestione un inventario básico de productos para una tienda.

## Temas principales
- Estructuras y Uniones
- Enumeraciones
- Memoria dinámica
- Archivos

## Requisitos funcionales
Definir una `struct Producto` que incluya:
- Código
- Nombre
- Precio
- Tipo de producto (enum: `ALIMENTO`, `ELECTRONICO`, `ROPA`)
- Detalle adicional usando `union` (por ejemplo: fecha de vencimiento o voltaje)

El sistema debe permitir:
- Agregar productos
- Listar productos
- Guardar inventario en archivo
- Cargar inventario desde archivo
- Usar memoria dinámica para almacenar los productos

## Requisitos técnicos
- Uso correcto de `union` según el tipo de producto
- Uso de `enum` para clasificar productos
- Persistencia de datos en archivo
