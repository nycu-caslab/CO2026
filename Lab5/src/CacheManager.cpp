#include "CacheManager.h"
#include <math.h>

// This is an example of direct-mapped cache manager implementation with block size 4 bytes.
// Note: This is ONLY a template. You MUST modify it to 2-way set associative, 
// block size 16 bytes, and LRU policy to pass the lab.

CacheManager::CacheManager(Memory *memory, Cache *cache){
    this->memory = memory;
    this->cache = cache;
    size = cache->get_size();

    // [Example] Set block size to 4. You MUST change this to 16.
    cache->set_block_size(4); 
    
    // [Example] Tag bits for direct-mapped. Needs recalculation for 2-way.
    tag_bits = 32 - (int)log2(cache->get_len()) - 2;
};

CacheManager::~CacheManager(){

};

std::pair<unsigned, unsigned> CacheManager::directed_map(unsigned int addr){
    // [Example] Logic for block size = 4
    unsigned int index_bit = int(log2(cache->get_len()));
    unsigned int index = (addr >> 2) % cache->get_len(); 
    unsigned int tag = addr >> index_bit >> 2;
    return {index, tag};
}

unsigned int* CacheManager::find(unsigned int addr){
    // Check if addr is in cache, return pointer to the data if hit, else nullptr.
    auto [index, tag] = directed_map(addr);
    if((*cache)[index].tag == tag)
        return &((*cache)[index][0]);
    else
        return nullptr;
}

unsigned int CacheManager::read(unsigned int addr){
    // Read data from cache, if miss, load data from memory to cache
    unsigned int* value_ptr = find(addr);
    if(value_ptr != nullptr) {
        return *value_ptr; // Cache Hit
    } else {
        // Cache Miss
        auto [index, tag] = directed_map(addr);
        
        // Update Metadata
        (*cache)[index].tag = tag;
        
        // Fetch from memory and store in cache
        unsigned int data = memory->read(addr);
        (*cache)[index][0] = data;
        
        return data;
    }
};

void CacheManager::write(unsigned int addr, unsigned value){
    // Write data to cache, if miss, load data from memory to cache
    unsigned int* value_ptr = find(addr);
    
    if(value_ptr != nullptr) {
        // Write Hit: update both cache and memory (Write-through example)
        *value_ptr = value;
    } 
    else {
        // Write Miss: Write-allocate policy
        // You should treat this as a MISS and load the block into cache
        auto [index, tag] = directed_map(addr);
        
        (*cache)[index].tag = tag;
        (*cache)[index][0] = value; // In reality, you should load the whole block first
    }
    
    // Always sync with memory for simplicity in this example
    memory->write(addr, value);
};
