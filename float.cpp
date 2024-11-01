
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>

std::bitset<32>bits;
void forbytes(float x){
    int sign;
    if(x< 0){
        sign = 1;
    }
    else{sign = 0;}
    int exponenta = 0;
    float fol = x;
    while(fol >= 2.0f){
        exponenta++;
        fol /=2;
    }
    while(fol < 1.0f){
        exponenta--;
        fol *=2;
    }
    exponenta += 127;
    /*отнормолизовали до [1;2]*/
    std::bitset<23>mantisa;
    fol -=1;/*дробную будем искать*/
    for(int i = 0; i <23; i++){
        fol *=2;
        if(fol >= 1.0f){
            mantisa.set(22-i);
            fol -=1.0;
        }
    }
    /*нашли знак, экспоненту и мантису*/
    bits.set(31,sign);
    bits |= std::bitset<32>(exponenta<<23);
    for(int i = 0; i <= 22; i++){
        bits.set(i, mantisa[i]);
    }
    std::cout<<"Binary form"<<std::endl;
    std::cout<<std::endl<<bits;
    std::cout<<std::endl<<"Exponent";
    for( int i = 1; i< 9; i++){
        std::cout<<bits[i];
    }
    std::cout<<std::endl<<"Mantisa"<<std::endl;
        std::cout<<mantisa;
    
}
void forfloat(){
    int sign = bits[31];
    if(sign == 1){
        sign = -1;
    }
    else{
        sign  = 1;
    }
    int expo = bits.to_ullong()>>23;
   expo -= 127;
   float mantisa = 1.0;
   for(int i = 0; i < 23; i++){
       mantisa += pow(2, -i - 1 )*bits[22-i];
   }
   float x = sign * mantisa * pow(2, expo);
   std::cout<<x<<std::endl;
    
}
void aboutmodul(){
    std::string a = "01001011100000000000000000000001";
    std::string b ="01001011100000000000000000000010";
   bits = std::bitset<32>(a);
    std::cout<<"a  ";
    forfloat();
    std::cout<<std::endl;
    bits = std::bitset<32>(b);
    std::cout<<"b  ";
    forfloat();
    std::cout<<std::endl;
    
}

void noassociative(){
    /*(a + b) + c != a + (b + c) */
    float a = 1.0;
    float b;
    while(1){
        b = a +1.0;
        if(b == a){
            break;
        }
        a*=2.0;
    }
    /*a станет настолько большим что достигнет предела float и ему булет все равно 
    
    на +1*/
    std::cout<<"(a + 1) + 3:"<< (a + 1.0) + 3.0<<std::endl<<"a + (1 + 3):"<<a + (1.0 +3.0)<<std::endl;
    
}
void ryad(){
    int number = 1;
    float sun = 0;
    float sum_1 = 0;
    bool f = 1;
    float k = 1;
    while(f){
        sun += (1/k);
        k +=1;
        if(sun == sum_1){
            std::cout<<"k  "<<number;
            f = 0;
        }
        sum_1 = sun;
        number +=1;
    }
}
 
void summarize(){
    float k = 1;
    float sun = 0;
/*прямая сумма*/
for(int i = 0; i <pow(2,21) + 100;i++){
    sun+= 1/k;
    k +=1;
}
std::cout<<"prymaya: "<<sun<<std::endl;
/*обратная*/
float sunobr = 0;
float k1 = pow(2, 21) + 100;
for(int i = 1; i < pow(2,21) + 100; i++){
    sunobr += 1/k1;
    k1 -=1;
}
std::cout<<"obratnaya: "<<sunobr<<std::endl;
}
int main(){
    /*задание 1*/
    std::cout<<"input float numer"<<std::endl;
    float x;
   std::cin>>x;
   forbytes(x);
   std::cout<<"now we go into float again"<<std::endl;
   forfloat();
   std::cout<<"задание 2"<<std::endl;
   aboutmodul();
  std::cout<<"задание 3"<<std::endl;
   noassociative();
   std::cout<<"задание 4"<<std::endl;
   ryad();
   std::cout<<"задание 5"<<std::endl;
   summarize();
    return 0;
    
}