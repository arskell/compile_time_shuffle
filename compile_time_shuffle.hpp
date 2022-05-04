#include<array>


//linear congruential generator
template<typename T> 
constexpr T get_random_number(T x){
    auto a = 1103515245ull;
    auto c = 12345ull;
    return (a*x + c) % (1<<30ull);
}


 

template<typename T, size_t N>
constexpr std::array<T,N> shuffle(std::array<T, N> input_array){
    std::array<T, N> output_array = input_array;
    const unsigned long long mod = (unsigned long long)(N)*N*N;
    T x0 = 0;
    
    for(size_t i = 0; i < 8; ++i){
        x0+=__TIME__[i];
    }

    std::array<T, N> lookup_indices{};

    lookup_indices[0] = get_random_number(x0) % mod;

    for(size_t i = 1; i < N; ++i){
        lookup_indices[i] = get_random_number(lookup_indices[i-1]) % mod;
    }

    //simple bubble sort 
    bool swapped = false;
    size_t sw_n = N;
    
    #if 1
    do{
        swapped = false;
        for(size_t i = 0; i < (sw_n - 1); ++i){
            
            if(lookup_indices[i] > lookup_indices[i+1]){
                
                //swapping
                auto tmp = lookup_indices[i+1];
                lookup_indices[i+1] = lookup_indices[i];
                lookup_indices[i] = tmp;
                
                tmp = output_array[i+1];
                output_array[i+1] = output_array[i];
                output_array[i] = tmp;

                swapped = true;
            }

        }
        sw_n -=1;
    }while(swapped);
    #endif
    return output_array;
}

