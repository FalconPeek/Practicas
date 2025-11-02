# Practicas

Repositorio de ejercicios en C para practicar modularización y Tipos de Datos Abstractos (TDA).

## Cómo compilar y ejecutar

El proyecto incluye un `makefile` pensado para trabajar con muchos directorios y distintos
archivos `main.c`. Podés compilar y ejecutar cualquiera de ellos con:

```bash
make ruta/al/archivo.c
```

Al ejecutar ese comando, `make` va a:

1. Compilar el archivo indicado y dejar los objetos en `build/obj/`.
2. Compilar también todos los módulos (archivos `.c` sin función `main`) para que puedan ser
   reutilizados.
3. Generar el ejecutable correspondiente dentro de `build/bin/` siguiendo la misma estructura
   de directorios.
4. Ejecutar el programa resultante.

Ejemplo para el `main.c` de la raíz del repositorio:

```bash
make main.c
```

Si necesitás preparar todos los módulos antes de correr algún `main`, podés hacerlo con:

```bash
make modules
```

Para limpiar los binarios y objetos generados:

```bash
make clean
```

## Notas

- Todos los directorios del proyecto (excepto `build/`) se agregan automáticamente al
  `include` path, por lo que podés organizar tus cabeceras y fuentes en subdirectorios como
  `TDA/` u otros.
- Las dependencias entre archivos se generan en forma automática utilizando `-MMD -MP`, lo
  que permite recompilar únicamente lo necesario.
