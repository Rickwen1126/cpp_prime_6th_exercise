#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>

void serializeInt(std::ostream &stream, uint32_t value, bool littleEndian)
{
    if (littleEndian)
    {
        for (int i = 0; i < 4; ++i)
            stream.put((value >> (i * 8)) & 0xFF);
    }
    else
    {
        for (int i = 3; i >= 0; --i)
            stream.put((value >> (i * 8)) & 0xFF);
    }
}

uint32_t deserializeInt(std::istream &stream, bool littleEndian)
{
    uint32_t result = 0;
    if (littleEndian)
    {
        for (int i = 0; i < 4; ++i)
            result |= static_cast<uint32_t>(stream.get()) << (i * 8);
    }
    else
    {
        for (int i = 3; i >= 0; --i)
            result |= static_cast<uint32_t>(stream.get()) << (i * 8);
    }
    return result;
}

void getNextP0323(int *next, const std::string &s)
{
    int j = 0;
    next[0] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = next[j - 1];
        }

        if (s[i] == s[j])
        {
            j++;
        }

        next[i] = j;
    }
}

int main()
{
    using namespace std;

    string s = "abcabc";
    int next[6];
    getNextP0323(next, s);

    for (int i = 0 ; i < 6; i++) {
        cout << next[i] << " ";
    }
    // std::ofstream outFile("data.bin", std::ios::binary);

    // // Serialize a 32-bit integer (0x12345678) in little-endian format
    // serializeInt(outFile, 0x12345678, true);

    // outFile.close();

    // std::ifstream inFile("data.bin", std::ios::binary);

    // // Deserialize the 32-bit integer from the file (assuming little-endian)
    // uint32_t value = deserializeInt(inFile, false);

    // std::cout << std::showbase << std::uppercase;
    // std::cout << "Deserialized Value: " << std::hex << value << std::endl;

    return 0;
}
