#include <iostream>
#include <unordered_map>
#include <string>

int main(){
    std::unordered_map<std::string, int> dic;

    dic["小力"] = 10001;
    dic["小特"] = 10002;
    dic["小扣"] = 10003;

    //may modify unordered_map
    std::cout << dic["小力"] << std::endl; // -> 10001
    std::cout << dic["小特"] << std::endl; // -> 10002
    std::cout << dic["小扣"] << std::endl; // -> 10003

    //won't modify unordered_map
    std::cout << "小力: " << dic.find("小力")->second << std::endl; // -> 10001
    std::cout << "小特: " << dic.find("小特")->second << std::endl; // -> 10002
    std::cout << "小扣: " << dic.find("小扣")->second << std::endl; // -> 10003

    return 0;

}
