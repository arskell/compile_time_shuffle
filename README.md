# compile_time_shuffle
constexpr c++17 random shuffle for std::array 

Example array:
```C++
{1,2,3,4,5,6,7,8}
```

We can see the product of the algorithm by using disassemble:
```asm
	.long	7
	.long	8
	.long	6
	.long	4
	.long	2
	.long	5
	.long	1
	.long	3
```

Data order changes after each compile
