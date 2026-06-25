#include "Map.h"

void Map::setCentralAxes() {    // 在地图中心设立中轴坐标
        int centerX = width_ / 2;
        int centerY = height_ / 2;
        grid_[centerY][centerX] = '+'; // 标记中心点。注意数组和坐标的关系，所以是[y][x]
        // 绘制八个方向的中轴线
        // 使用循环来绘制，而不是硬编码
        int maxLength = std::max(centerX, centerY); // 确保轴线不会超出边界
        for (int i = 1; i <= maxLength; ++i) {
            if(isInsideBounds(centerX, centerY - i)) grid_[centerY - i][centerX] = '|'; // 上
            if(isInsideBounds(centerX, centerY + i)) grid_[centerY + i][centerX] = '|'; // 下
            if(isInsideBounds(centerX - i, centerY)) grid_[centerY][centerX - i] = '-'; // 左
            if(isInsideBounds(centerX + i, centerY)) grid_[centerY][centerX + i] = '-'; // 右
            if(isInsideBounds(centerX + i, centerY - i)) grid_[centerY - i][centerX + i] = '/';// 右上
            if(isInsideBounds(centerX - i, centerY + i)) grid_[centerY + i][centerX - i] = '/';// 左下
            if(isInsideBounds(centerX - i, centerY - i)) grid_[centerY - i][centerX - i] = '\\'; // 左上
            if(isInsideBounds(centerX + i, centerY + i)) grid_[centerY + i][centerX + i] = '\\'; // 右下
        }
    }

    // 在不同方向的区域填充内容
    void Map::fillRegions() {
        int centerX = width_ / 2;
        int centerY = height_ / 2;

        // 遍历所有非边界的内部点
        for (int y = 1; y < height_; ++y) {
            for (int x = 1; x < width_; ++x) {
                // 如果当前点是空白，则进行填充
                if (grid_[y][x] == ' ') {
                         if (y < centerY && x > centerX && x - centerX < centerY - y)
                        grid_[y][x] = 'A'; // A区域
                    else if (y < centerY && x > centerX && x - centerX > centerY - y)
                        grid_[y][x] = 'B'; // B区域
                    else if (y > centerY && x > centerX && x - centerX > y - centerY)
                        grid_[y][x] = 'C'; // C区域
                    else if (y > centerY && x > centerX && x - centerX < y - centerY)
                        grid_[y][x] = 'D'; // D区域
                    else if (y > centerY && x < centerX && x - centerX > centerY - y)
                        grid_[y][x] = 'E'; // E区域
                    else if (y > centerY && x < centerX && x - centerX < centerY - y)
                        grid_[y][x] = 'F'; // F区域
                    else if (y < centerY && x < centerX && x - centerX < y - centerY)
                        grid_[y][x] = 'G'; // G区域
                    else if (y < centerY && x < centerX && x - centerX > y - centerY)
                        grid_[y][x] = 'H'; // H区域
                }
            }
        }
    }

    // 打印地图 (const成员函数，因为它不修改对象的状态)
    void Map::print() const {
        for (int y = 0; y < height_; ++y) {
            for (int x = 0; x < width_; ++x) {
                std::cout << grid_[y][x];
            }
            std::cout << std::endl;
        }
    }


Map initializeMapFromUserInput() {//Map的应用，这里就没有用到Map里的变量了。此前全是造Map
    int width = 0, height = 0;
    while (true) {
        std::cout << "请输入地图宽度 (6-10000): ";
        std::cin >> width;
        std::cout << "请输入地图高度 (6-10000): ";
        std::cin >> height;

        try {   //异常处理措施，这是教科书级别模板
            Map newMap(width, height);// 尝试创建Map对象，如果尺寸不合法，初始化的构造函数会抛出异常
            return newMap; // 成功则返回
        } catch (const std::invalid_argument& err) {
//捕获异常，它只对 std::invalid_argument 类型的异常感兴趣，const保证不被修改，&为表引用，而没有拷贝的必要
            std::cerr << "错误: " << err.what() << std::endl;
            std::cout << "请重新输入:" << std::endl << std::endl;
/*当用户输入了非数字（例如 "abc"）来尝试满足一个数字输入（std::cin >> width）时，
输入流 std::cin 会进入一个“失败”状态（fail state）。
在这个状态下，所有后续的输入操作都会立即失败。
std::cin.clear() 的作用就是重置这个失败标志，让输入流恢复到可以正常工作的状态。
即使错误标志被清除了，导致错误的那些字符（例如 "abc\n"）仍然残留在输入缓冲区中。
如果不清除它们，下一次循环时 std::cin 会再次尝试读取这些相同的垃圾字符，从而导致无限循环。
std::cin.ignore(...) 的作用就是清空这个缓冲区：
- 第一个参数: std::numeric_limits<std::streamsize>::max() 表示要忽略的字符数是“无限多”。
- 第二个参数: '\n' 表示忽略操作在遇到并丢弃一个换行符后就停止。
组合起来，这行代码的含义是：“丢弃缓冲区里的所有东西，直到行尾”。*/
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}