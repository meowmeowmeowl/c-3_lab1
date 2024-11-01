#include <iostream>
#include <cmath>
#include <climits>
void forbite(){
    typedef union {
        int a;
        unsigned int b;
    } number;
    number x;
    std::cout<<"enter int"<<std::endl;
    std::cin>>x.a;
    /*положительный int*/
    if (x.a >0){
        for(int i = floor(log(x.a)/log(2)); i>=0; i--){
            int byte = (x.a>>i)&1;
            std::cout<<byte;
            /*floor(log2(x.a)) - макс индекс бита со значением 1
            x.a >> i - сдвигаем побитовов вправо на i позиций
            &i - побитовое пересечение с 1 для получения значения бита
            */
        }
    }
    /*отрицательный инт*/
    if(x.a <0){
        x.a = ~(-x.a)+ 1;
        /* в дополнительном коде*/
        for(int i = floor(log(-x.a)/log(2)); i>=0; i--){
            int byte = (x.a>>i)&1;
            std::cout<<byte;
        }
    }
    std::cout<<std::endl<<"enter unsigned int"<<std::endl;
    std::cin>>x.b;
     for(int i = floor(log(x.b)/log(2)); i>=0; i--){
            int byte = (x.b>>i)&1;
            std::cout<<byte;
        }
    std::cout<<std::endl;
}

void maxfunc(){
    std::cout<<"with max_int"<<std::endl<<INT_MAX + 1<<std::endl;
    unsigned int zer = 0;
    std::cout<<"0-1"<<std::endl<< zer - 1<<std::endl;
}

int main(){
    forbite();
    maxfunc();
    
    return 0;
    
}