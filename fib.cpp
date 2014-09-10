#include <cstdint>
#include <iostream>

std::int64_t fib( int64_t nth_num_in_series )
  {
    if ( nth_num_in_series < 2 ) return 1;
    std::int64_t current_val = 2, prev = 1, prev_prev = 1;
    std::uint32_t current_n = 2;
    while ( current_n <= nth_num_in_series ) 
    {
      current_val = prev + prev_prev;
      prev_prev = prev;
      prev = current_val;
      ++current_n;
    }
    return current_val;
  }


  int main(int argc, char const *argv[])
  {
    /* code */
    for (auto i = 0; i < 10; i++) {
      std::cout << i << "th num:" <<fib( static_cast<std::int64_t>( i ) ) << std::endl;
    }
    
    return 0;
  }