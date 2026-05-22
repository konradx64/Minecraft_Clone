#pragma once
#include "../Chunk.h"
#include <unordered_map>
#include <mutex>
#include "../../Coordinate.h"
class ChunkMap{
public:
    ChunkMap(){};
    void AddChunk(Chunk* chunk,const ChunkPosition& chunkPosition);
    void RemoveChunk(const ChunkPosition& chunkPosition);
    Chunk* GetChunk(const ChunkPosition& chunkPosition, bool lock = false);
    void UnlockChunk(Chunk* chunk);
    bool ChunkExist(const ChunkPosition& chunkPosition);
    std::vector<Chunk*> GetChunks();
    inline std::unordered_map<ChunkPosition,Chunk*,ChunkPositionHash>& GetChunkMap(){return m_Chunks;}
private:
    std::unordered_map<ChunkPosition,Chunk*,ChunkPositionHash> m_Chunks{};
    mutable std::mutex m_Mutex{};
};
