//nfscheck 
// busca conexiones activas en el puerto 2049 para ver que dispositivos nfs
// estan montados en el sistema.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  // Estructura para almacenar información de una conexión
  struct sockaddr_in connection;
  socklen_t connection_len = sizeof(connection);

  // Abrir el archivo /proc/net/tcp
  FILE *fp = fopen("/proc/net/tcp", "r");
  if (fp == NULL) {
    perror("Error al abrir el archivo /proc/net/tcp");
    return 1;
  }

  // Leer el archivo línea por línea
  char line[256];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Dividir la línea en campos separados por espacios
    char *fields[32];
    char *field = strtok(line, " ");
    int i = 0;
    while (field != NULL) {
      fields[i++] = field;
      field = strtok(NULL, " ");
    }

    // Si el campo Local Address es "0A:20:49", significa que la conexión está en el puerto 2049
    if (strcmp(fields[1], "0A:20:49") == 0) {
      // Convertir la dirección IP y el número de puerto en formato humano legible
      inet_ntop(AF_INET, &connection.sin_addr, connection.sin_addr, INET_ADDRSTRLEN);
      unsigned int port = ntohs(connection.sin_port);

      // Mostrar la información de la conexión
      printf("Conexión desde %s:%u\n", connection.sin_addr, port);
    }
  }

  // Cerrar el archivo
  fclose(fp);

  return 0;
}
