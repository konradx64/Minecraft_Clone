#pragma once
#include "../../OpenGL/Buffer.h"
#include "../Coordinate.h"
#include <atomic>
#include <array>
#include <mutex>



class Chunk {
public:
    explicit Chunk(const ChunkPosition& chunkPosition) : Position(chunkPosition){std::fill(std::begin(m_Blocks), std::end(m_Blocks), 0);};
    void Create();
    void Destroy();
    void Generate();
    void Update();
    void Upload();
    void Render();
    uint8_t GetBlock(uint8_t x, uint8_t y, uint8_t z);
    void SetBlock(uint8_t x, uint8_t y, uint8_t z, uint8_t block);
    bool NeighboursGenerated();
    ChunkPosition Position;
    std::atomic_bool Created = false;
    std::atomic_bool Generating = false;
    std::atomic_bool Generated = false;
    std::atomic_bool Updating = false;
    std::atomic_int UpdateCount = 0;
    std::atomic_bool Uploaded = true;
    std::atomic_bool Accessed = false;
    bool FirstUpdate = false;
    inline std::vector<int>& GetBlockBuffer() {return m_BlockData;}
private:
    void CreateFaceData(std::vector<int>& data, uint8_t blockX, uint8_t blockY, uint8_t blockZ, uint8_t faceType, uint8_t lightLevel, uint16_t textureIndex,  int8_t offsetX, int8_t offsetY, int8_t offsetZ,uint8_t width, uint8_t height);
    VertexArray* m_VertexArray = nullptr;
    ShaderBuffer* m_ShaderBuffer = nullptr;
    ShaderBuffer* m_NonCullFaceBuffer = nullptr;
    mutable std::mutex m_Mutex;
    std::vector<int> m_BlockData;
    std::vector<int> m_NonCulledFaceBlockData;
    std::vector<int> m_BlockDataBuffer;
    std::vector<int> m_NonCulledFaceBlockDataBuffer;
    std::array<uint8_t,CHUNK_AREA> m_Blocks = {0};
};
