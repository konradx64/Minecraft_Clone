#pragma once

#include "../Chunk.h"
#include "../ChunkMap/ChunkMap.h"
#include <thread>
#include <vector>
#include <queue>
#include <mutex>

class ChunkGenerator {
public:
    explicit ChunkGenerator(int threadCount);
    ~ChunkGenerator();
    static void GenerateChunk(Chunk* chunk);
    inline static std::queue<Chunk*>& GetChunkQueue(){return m_GenerateChunks;};
private:
    mutable std::mutex m_Mutex;
    static std::queue<Chunk *> m_GenerateChunks;
    std::vector<std::thread*> m_Threads;
};
