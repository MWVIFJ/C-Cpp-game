#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm> // For std::max
#include <limits>
using namespace std;
#endif //MAP_H

class Map
{
private:
    // --- 私有成员变量：封装地图的内部状态，保护其一致性 ---
    int width_;
    int height_;
    std::vector<std::vector<char>> grid_; // 使用char更高效，因为它只需要存储单个字符

    // --- 私有辅助函数：内部实现细节，不对外暴露 ---
    // 检查坐标是否在地图范围内（不含边界）
    bool isInsideBounds(int x, int y) const {
        return x > 0 && x < width_ && y > 0 && y < height_;
    }

public:
    // --- 公共构造函数：负责对象的正确创建和初始化 ---
    Map(int width, int height) : width_(width), height_(height) {
        // 输入验证：构造函数是保证对象初始状态合法性的第一道防线
        if (width < 6 || height < 6 || width > 10000 || height > 10000) {
            throw std::invalid_argument("地图宽高只能在6-10000以内.");
        }
        // 初始化网格，并填充为空白
        grid_.resize(height_,vector<char>(width_,' '));
    }
    void setCentralAxes();
    void fillRegions();
    void print() const;
};

Map initializeMapFromUserInput();