# Implement Cache Manager
[Spec PPT](https://docs.google.com/presentation/d/10FDVFUdgOdK4NzAGzUv1uCi76soQDMOWIRjeeBR0W1Y/edit?usp=sharing)
## Introduction
In this lab, you will design a **Cache Manager** to handle cache table lookups and data synchronization between the Cache and Main Memory.

There are some architectural constraints. You must implement a 2-way Set Associative Cache with a specific block size and replacement policy to ensure your results match the expected performance metrics.

## Constraints
1. Cache Type: 2-way Set Associative Cache
2. Block Size: 16 bytes (4 words)
3. Replacement Policy: Least Recently Used (LRU)
4. Write Policy: Write Allocate (write miss will load the block into cache, then write the data)
5. Cache Size: 1024 bytes

## Explain the code
```cpp
class Cache
{
private:
    std::vector<Block> blocks;
    const unsigned int size;
    unsigned int len;
public:
    Cache(unsigned int size);   
    
    unsigned int get_size();
    unsigned int get_len();
    unsigned int set_block_size(unsigned int block_size);
    unsigned int get_machine_address_bit();
    
    Block& operator[](unsigned int index);
};
```
This is the Class of **Cache** we provide, you can use the
```get_size()```  get size of cache.
```get_len()```  get number of block.
```set_block_size(unsigned int block_size)```  set block size by yourself, This configuration will be related to the number of cache lines.
```get_machine_address_bit()``` get machine address base.

-----

```cpp
class Block{
private:
    std::vector<unsigned int> values;
public:
    unsigned int len;
    unsigned int tag;
    
    Block(unsigned int block_size);

    unsigned int& operator[](unsigned int index);
};
```
this is the Class of **Block** we provide, you must record the **Tag** in ```Block.tag``` when the data in cache, and you also can use the ```Block.len``` get how many word(4 bytes) in a block

-----

```cpp
class CacheManager
{
private:
    Memory *memory;
    Cache *cache;
    unsigned int size;       // bytes
    unsigned int tag_bits;
public:

    CacheManager(Memory *memory, Cache *cache);
    ~CacheManager();
    unsigned int* find(unsigned int addr); // return the address of data in cache, if not found, return nullptr
    unsigned int read(unsigned int addr); // read data from cache, if miss, load data from memory to cache
    void write(unsigned int addr, unsigned value); // write data to cache, if miss, load data from memory to cache
};
```
This is Class of **CacheManager**, you need to config your metadata in Constructor (ex: block size, cache way...), and design your cache manager read/write/find in cpp file.
Test pattern will call the CacheManger read/write/find to communicate with your cache, so this part you must manage your data in cache and memory properly.


:bulb: block size need to call Class Cache api ```set_block_size(unsigned int block_size)```


#### simple test case
```
w bf880c18 83831c0a
w bf880c08 4a0c2c0e
w bf880c04 7446feef
r bf880c04
r bf880c08
w 80c9578 e79be23
r bf880c18
r 80c9578
```

:bulb: You can use Python to program the pattern generator to generate the test case to verify your Cache Manager

## Requirement
You can only modify CacheManager.cpp and CacheManager.h. The final grade is determined only by the consistency of the total miss count.

Grading:

1. testcase x 1 : 20%
2. hidden testcase x 4 : 80%

Submit zip file with the following format.
```
<stduent_id>.zip
   |- <student_id>/
      |- CacheManager.cpp
      |- CacheManager.h
      |- (don't zip other files)
```
