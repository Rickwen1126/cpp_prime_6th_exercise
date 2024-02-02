#include <iostream>
#include <fstream>
#include <cstdint>

void serializeInt(std::ostream& stream, uint32_t value, bool littleEndian) {
    if (littleEndian) {
        for (int i = 0; i < 4; ++i)
            stream.put((value >> (i * 8)) & 0xFF);
    } else {
        for (int i = 3; i >= 0; --i)
            stream.put((value >> (i * 8)) & 0xFF);
    }
}

uint32_t deserializeInt(std::istream& stream, bool littleEndian) {
    uint32_t result = 0;
    if (littleEndian) {
        for (int i = 0; i < 4; ++i)
            result |= static_cast<uint32_t>(stream.get()) << (i * 8);
    } else {
        for (int i = 3; i >= 0; --i)
            result |= static_cast<uint32_t>(stream.get()) << (i * 8);
    }
    return result;
}

int main() {
    std::ofstream outFile("data.bin", std::ios::binary);

    // 以小端序格式序列化一个32位整数（0x12345678）
    serializeInt(outFile, 0x12345678, false);

    outFile.close();

    std::ifstream inFile("data.bin", std::ios::binary);

    // 从文件中反序列化32位整数（假设是小端序）
    uint32_t value = deserializeInt(inFile, false);

    std::cout << "out: " << std::hex << value << std::endl;

    return 0;
}

