# Ejercicios en C - Concurrencia y Procesos

Este repositorio contiene una colección de ejercicios en C enfocados en temas de concurrencia, manejo de procesos, comunicación entre procesos y manipulación básica de datos. Cada archivo representa un ejercicio independiente con su descripción y objetivo.

## Estructura del Repositorio

Los ejercicios están organizados en la raíz del repositorio. Cada archivo tiene un nombre descriptivo que refleja su propósito. A continuación se muestra una lista de los archivos incluidos:

### Lista de Ejercicios

1. **`numero_mayor_menor.c`**
   - **Descripción:** Compara si un número ingresado por el usuario es mayor, menor o igual a 5.
   - **Uso:** Ejercicio introductorio para manejo de condicionales.

2. **`procesos_salida_fork.c`**
   - **Descripción:** Crea procesos hijo usando `fork()` y redirige la salida del comando `ls` a un archivo.

3. **`calculadora_basica.c`**
   - **Descripción:** Implementa una calculadora básica con operaciones de suma, resta, multiplicación y división usando funciones.

4. **`proceso_padre_hijo_nieto.c`**
   - **Descripción:** Simula un árbol de procesos con un padre, un hijo y un nieto, demostrando el uso de `fork()`.

5. **`arbol_procesos.c`**
   - **Descripción:** Genera un árbol de procesos con varios niveles usando `fork()`.

6. **`multiplicacion_matrices.c`**
   - **Descripción:** Genera dos matrices aleatorias y calcula su producto.

7. **`pipe_comunicacion.c`**
   - **Descripción:** Implementa comunicación entre procesos mediante tuberías (pipes).

8. **`fifo_comunicacion.c`**
   - **Descripción:** Utiliza un FIFO (archivo de tubería) para la comunicación entre procesos.

9. **`ping_pong_senales.c`**
   - **Descripción:** Simula un intercambio "ping-pong" entre dos procesos usando señales.

## Requisitos

- **Sistema operativo:** Linux (necesario para ejercicios que usan `fork`, `pipe`, o `mknod`).
- **Compilador:** GCC (GNU Compiler Collection).
- **Comandos adicionales:** Algunos ejercicios utilizan comandos de sistema como `ls`, `grep`, y `mknod`.

## Instrucciones de Compilación y Ejecución

Cada archivo puede compilarse y ejecutarse de manera independiente usando los siguientes comandos:

1. **Compilación:**
   ```bash
   gcc -o <nombre_ejecutable> <archivo_fuente>.c
   ```

2. **Ejecución:**
   ```bash
   ./<nombre_ejecutable>
   ```

Por ejemplo, para compilar y ejecutar el archivo `arbol_procesos.c`:
```bash
gcc -o arbol_procesos arbol_procesos.c
./arbol_procesos
```

## Notas Adicionales

- Algunos ejercicios generan varios procesos que podrían quedar ejecutándose si no se cierran correctamente. Usa el comando `ps` para verificar procesos activos y `kill` para finalizarlos si es necesario.

- Si encuentras errores en los ejercicios (como problemas de sintaxis o lógica), revisa las notas en la sección de comentarios dentro del código fuente.

## Contribución

Si deseas contribuir a este repositorio o reportar un error, puedes abrir un issue o enviar un pull request.

---

### Autor
Repositorio creado como parte de ejercicios de aprendizaje en C y concurrencia.

