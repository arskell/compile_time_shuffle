#include "compile_time_shuffle.hpp"


//example
int main(){

    constexpr std::array<int, 8> ar = {1,2,3,4,5,6,7,8};
    constexpr auto v = shuffle(ar);

}