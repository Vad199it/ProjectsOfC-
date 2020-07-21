#include <iostream>
#include <cstdint>
#include <array>

class RGBA {
private:
    std::array<std::uint8_t, 4> m_arrColor;
public:
    RGBA(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255) :
        m_arrColor{red, green, blue, alpha}
    {

    }
    void print() {
        for (uint8_t elem : m_arrColor)
            std::cout << static_cast<int>(elem) << " ";
    }
};

int main()
{
    RGBA color(0, 135, 135);
	color.print();
 
	return 0;
}

