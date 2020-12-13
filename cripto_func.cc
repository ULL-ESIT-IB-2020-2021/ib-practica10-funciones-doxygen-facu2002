#include <iostream>
#include <fstream>
#include <string>
#include "cripto_func.h"


void Ejecucion(int argc, char *argv[]){
    if (argc != 6){
        std::cout<< argv[0] << ": Falta un número como parámetro." << std::endl;
        std::cout<< "Pruebe "<< argv[0] <<" --help para más información." << std::endl;
        exit(EXIT_SUCCESS);
    }
    std::string parametro{argv[1]};
    if (parametro == "--help"){
        std::cout<< "\n./cripto -- Cifrado de ficheros \nModo de uso: ./cripto fichero_entrada fichero_salida método password operación\n \nfichero_entrada: Fichero a codificar\nfichero_salida:  Fichero codificado\nmétodo:          Indica el método de encriptado                   \n1: Cifrado xor                    \n2: Cifrado de César\npassword:        Palabra secreta en el caso de método 1, Valor de K en el método 2\noperación:       Operación a realizar en el fichero                   \n+: encriptar el fichero                   \n-: desencriptar el fichero\n" << std::endl;
        exit(EXIT_SUCCESS);
    }
}

std::string EncriptarCesar(std::string frase, int longitud, int k){
  std::string enc;
  for (int i=0; i<=longitud; i++){
    int n = frase[i];
    char letra(n+k);
    enc += letra;
  }
  return enc;
}

std::string DesencriptarCesar(std::string frase, int longitud, int k){
  std::string enc;
  for (int i=0; i<=longitud; i++){
    int n = frase[i];
    char letra(n-k);
    enc += letra;
  }
  return enc;
}

std::string EncriptarXor(std::string frase,int longitud, std::string clave){
  std::string enc;
  for(int i=0; i<=longitud+1;i++){
    int a = clave[i];
    int b = frase[i];
    char c=a^b;
    enc += c;
  }
return enc;
}
