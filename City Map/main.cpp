#include "Map.h"

int main() {
    try {
        Map myGameMap = initializeMapFromUserInput();
        myGameMap.setCentralAxes();//设立中轴：向Map对象发送指令
        // std::cout << "\n--- 设立中轴后 ---\n";
        // myGameMap.print();
        myGameMap.fillRegions();//填充内容：向Map对象发送指令
        std::cout << "\n--- 最终地图 ---\n";
        myGameMap.print();

    } catch (const std::exception& err) {
        // 捕获可能发生的任何异常
        std::cerr << "程序发生严重错误: " << err.what() << std::endl;
        return 1;
    }

    return 0;
}
