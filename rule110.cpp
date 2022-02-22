#include <iostream>
#include <array>

//veces: number of iterations
//regla: rule used
//random: random input, if false then single input at the center of grid
void dibujar(int veces,int regla, bool random){
    const int tamano_grid = 10000;
    const int tamano_consola = 208;
    std::array<bool,8>regla_bits;
    std::array<bool,tamano_grid+2>grid_front;
    std::array<bool,tamano_grid+2>grid_back;

    for(int i=0;i<8;i++){regla_bits[i] = (regla & ( 1 << i )) >> i;}
    for(int i=0;i<tamano_grid;i++){grid_front[i] = grid_back[i] = 0;}
    if(not random){grid_front[tamano_grid/2] = 1;}
    else{for(int i=1;i<tamano_grid-1;i++){grid_front[i] = grid_back[i] = rand() % 2;}}
    //Primer print
    for(int i=0;i<tamano_consola;i++){
        if(grid_front[i+ (tamano_grid-tamano_consola)/2]){std::cout << (char)176u;}
        else{std::cout << " ";}
    }
    std::cout << std::endl;
    for(int j=0;j<veces;j++){
        for(int i=1;i<tamano_grid-1;i++){
            int cuadro_anterior  = grid_front[i-1];
            int cuadro_actual    = grid_front[i];
            int cuadro_siguiente = grid_front[i+1];
            //int test = (cuadro_anterior << 2)|(cuadro_actual<<1)|(cuadro_siguiente);
            //std::cout << test << " ";
            bool resultado = regla_bits[(cuadro_anterior)|(cuadro_actual<<1)|(cuadro_siguiente<<2)];
            grid_back[i] = resultado;
        }
        for(int k=0;k<tamano_consola;k++){
                if(grid_back[(k)+ (tamano_grid-tamano_consola)/2]){std::cout << (char)176u;}
                else{std::cout << " ";}
            }
        std::swap(grid_front,grid_back);
        std::cout << std::endl;
    }
}


int main(){

    /*
    std::cout << std::endl;
    std::array<int,10>reglas_single = {30,60,110,99,89,193,167,121,225};
    std::array<int,4>reglas_rand    = {22,90,154,57};

    for(int i=0;i<10;i++){
        dibujar(64,reglas_single[i],false);}
    for(int i=0;i<4;i++){
        dibujar(64,reglas_rand[i],true);}
    */
    
    int input1,input2;
    bool input3;
    while(true){
        std::cout << "Iterations: ";
        std::cin  >> input1;
        std::cout << "Rule: ";
        std::cin  >> input2;
        std::cout << "Random: ";
        std::cin  >> input3;
        dibujar(input1,input2,input3);
    }
    
    return 0;
}
