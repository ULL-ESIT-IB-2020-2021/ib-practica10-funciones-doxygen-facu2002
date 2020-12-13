#include <iostream>
#include <fstream>
#include <string>

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


int main(){
  //Ejecucion(argc,argv);
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
