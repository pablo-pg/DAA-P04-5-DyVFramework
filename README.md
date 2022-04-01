# Páctica 4 y 5. Framework para Algoritmos DyV

## Introducción

Este programa sirve para implementar diversos algoritmos divide y vencerás, utilizando el patrón plantilla, de forma genérica y polimórfica gracias al framework *Divide*.  

Actualmente solo está implementado MergeSort y QuickSort.

## Compilación y ejecución

Compilación:  

```bash
make
```  

Después de compilar, puede ejecutar manualmente con ```$ ./bin/framework```   

Se le abrirá una terminal con la elección de un modo normal o un modo debug:  
 - Modo normal: Genera 5 vectores de tamaño aleatorio y calcula el tiempo de ejecución, así como el número de llamdas recursivas y niveles del árbol de recursión, para los algoritmos implementados. Finalmente, se muestra una tabla comparativa.  
 - Modo debug: Se solicita tanto el tamaño del problema como el algoritmo a utilizar y se muestra la solución por pantalla.

## Detalles de implementación

Código desarrollado en C++ usando los paradigmas de OOP, herencia, polimorfismo, plantillas y lambdas.

## Referencias

[Algoritmo Divide y Vencerás - Wikipedia](https://es.wikipedia.org/wiki/Algoritmo_divide_y_vencer%C3%A1s)  
