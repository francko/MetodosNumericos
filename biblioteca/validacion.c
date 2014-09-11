#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
 
int main() {
  regex_t retmp;
  regmatch_t mtmp;
  int res;
  char subcad[20],cad[] = "hola 34 mundo";
  printf("Patron: [0-9]+\n");
  res = regcomp(&retmp,"[0-9]+",REG_EXTENDED);
  if (res!=0)
    printf("Error al compilar la RegExp (Resultado: %d)\n",res);
  printf("Cadena de prueba: %s\n",cad);
  res = regexec(&retmp, cad, (size_t) 1, &mtmp, 0);
  if (res==0) {
    printf("El patron esta en la cadena\n",res);
    strncpy(subcad,cad+mtmp.rm_so,mtmp.rm_eo-mtmp.rm_so);
    printf("Subcadena: %s\n",subcad);
  }
  printf("Cadena de prueba: hola mundo\n",cad);
  res = regexec(&retmp,"hola mundo", (size_t) 0, NULL, 0);
  if (res!=0) 
    printf("El patron NO esta en la cadena\n",res);
}
