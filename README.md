# C-Socket

Sockets bezeroaren eta zerbitzariaren kodigoa C hizkuntzan.

## Compilación

Para compilar el proyecto, ejecuta:

```bash
make
```

Esto generará los binarios `client` y `server` en el directorio `bin/`.

## Ejecución

### Servidor

Inicia el servidor:

```bash
./bin/server
```

### Cliente

Envía un mensaje al servidor:

```bash
./bin/client localhost "Hola Mundo"
```

El servidor recibirá el mensaje, lo convertirá a mayúsculas y lo enviará de vuelta al cliente.

## Limpieza

Para eliminar los archivos compilados:

```bash
make clean
```
