![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)

# TP1 — Primitivas de Algoritmos en C

Biblioteca de funciones fundamentales en C: desde un problema de teoría de
números (números amigos) hasta ordenamiento y manejo seguro de memoria
dinámica para arreglos y matrices, con foco en no dejar un solo byte sin
liberar.

## Conceptos aplicados

- **Selection sort** O(n²) para ordenar arreglos.
- **Merge + dedup ordenado**: unión de dos arreglos sin repetidos combinando
  sort y un único recorrido lineal, en vez de usar un set auxiliar.
- **Manejo dinámico de matrices**: alocación/liberación de arreglos de
  arreglos (`int**`), incluyendo copia profunda de un arreglo de matrices de
  tamaños heterogéneos.
- **Gestión de memoria en C**: cada `malloc` tiene su `free` correspondiente,
  validado con Valgrind.

## Cómo correrlo

```bash
make local     # compila con -Wall -Wconversion -Werror y corre los tests bajo Valgrind
# o
make docker    # build + run en un contenedor Ubuntu limpio
```

## Detalles técnicos

`copy_array_of_matrices` maneja alocación con rollback: si falla el `malloc`
de una fila a mitad de la copia de una matriz, libera únicamente las filas ya
alocadas antes de esa, evitando tanto el leak como un `free` sobre memoria
no inicializada. Todo el código pasa Valgrind con `--leak-check=full` sin
ninguna advertencia.
