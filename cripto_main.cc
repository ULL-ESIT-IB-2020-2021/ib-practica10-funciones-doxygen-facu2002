#include <iostream>
#include <fstream>
#include <string>
#include "cripto_func.cc"



int main(int argc, char* argv[]){
  std::ifstream ficheroEntrada;
  std::string frase;
  std::string clave;
  int longitud, k, numero;

  ficheroEntrada.open("fichero_entrada.txt");
  getline(ficheroEntrada, frase);
  ficheroEntrada.close();
  longitud=frase.length();
  std::cout << "Para encriptar por xor: 1" << std::endl;
  std::cout << "Para encriptar por cesar: 2" << std::endl;
  std::cin >> numero;

  if(numero==1){
    int n=0;
    std::cout << "Para encriptar: 1" << std::endl;
    std::cout << "Para desencriptar: 2" << std::endl;
    std::cin >> n;
    std::cout << "Introduzca la clave: " << std::endl;
    std::cin >> k;
    if (n==1){
      std::cout << EncriptarXor(frase, longitud, clave) << std::endl;
    }if(n==2){
      std::cout << "pepe" << std::endl;
    }if(numero!=1 && numero!=2){
      std::cout << "El número introducido no es válido." << std::endl;
    }

  }
  if(numero==2){
    int n=0;
    std::cout << "Para encriptar: 1" << std::endl;
    std::cout << "Para desencriptar: 2" << std::endl;
    std::cin >> n;
    std::cout << "Introduzca la clave: " << std::endl;
    std::cin >> k;
    if (n==1){
      std::cout << EncriptarCesar(frase, longitud,k) << std::endl;
    }if(n==2){
      std::cout << DesencriptarCesar(frase, longitud, k) << std::endl;
    }if(numero!=1 && numero!=2){
      std::cout << "El número introducido no es válido." << std::endl;
    }
  }if(numero!=1 && numero!=2){
    std::cout << "El número no es válido." << std::endl;
  }
}
