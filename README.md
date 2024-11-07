# P03-Turing-Machine

**Autor**: Diego Rodríguez Martín  
**Correo**: alu0101464992@ull.edu.es  

Este proyecto implementa una **Máquina de Turing determinista** con las siguientes características:

- **Escritura y movimientos simultáneos**: en cada paso, la máquina puede escribir y moverse a la vez.
- Movimientos en tres direcciones: **izquierda (L)**, **derecha (R)** y **mantener posición (S)**.
- **Cinta infinita en ambas direcciones**, permitiendo un procesamiento sin restricciones de espacio.

## Compilación

Para compilar el proyecto, asegúrate de tener `g++` y ejecuta el siguiente comando en el directorio principal del proyecto:

```bash
g++ -o turing Alphabet/alphabet.cc State/state.cc Symbol/symbol.cc Transition/transition.cc main.cc Tape/tape.cc TuringMachine/turing_machine.cc
```

## Ejercicios Implementados

- **Ejercicio1_MT.txt**
- **Ejercicio2_MT.txt**

## Ejecución

```bash
./turing examples/{fichero.txt} [cadenas a reconocer]
```
Ejemplos de ejecución:
```bash
./turing examples/Ejercicio2_MT.txt abbabaabb
./turing examples/Ejercicio1_MT.txt ab a aabb abbab
./turing examples/Ejemplo_MT\ .txt 0 000 1000 100 0000
./turing examples/Ejemplo2_MT.txt 11 1111
```