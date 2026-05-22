#pragma once

#include "../Chunk.h"
#include "../ChunkMap/ChunkMap.h"
#include <thread>
#include <vector>
#include <queue>
#include <mutex>

class ChunkUpdater {
public:
    ChunkUpdater(int threadCount);
    ~ChunkUpdater();
    static void UpdateChunk(Chunk* chunk);
    inline static std::queue<Chunk*>& GetChunkQueue(){return m_UpdateChunks;};
private:
    mutable std::mutex m_Mutex;
    static std::queue<Chunk *> m_UpdateChunks;
    std::vector<std::thread*> m_Threads;
};
