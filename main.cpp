#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <windows.h>
namespace fs = std::filesystem;
using namespace std;

int main() {
    system("chcp 65001");
    SetConsoleOutputCP(CP_UTF8);
    string name, world, role, tone;

    // Giá trị mặc định
    string default_name = "Hyo";
    string default_world = "vương quốc Hyo huyền bí";
    string default_role = "người kể chuyện";
    string default_tone = "thân thiện và hài hước";

    cout << "=== Tạo prompt cho ChatGPT ===" << endl;
    cout << "Nhấn Enter để dùng giá trị mặc định." << endl << endl;

    cout << "Tên nhân vật chính (mặc định: " << default_name << "): ";
    getline(cin, name);
    if (name.empty()) name = default_name;

    cout << "Bối cảnh thế giới (mặc định: " << default_world << "): ";
    getline(cin, world);
    if (world.empty()) world = default_world;

    cout << "Vai trò của ChatGPT (mặc định: " << default_role << "): ";
    getline(cin, role);
    if (role.empty()) role = default_role;

    cout << "Giọng điệu trả lời (mặc định: " << default_tone << "): ";
    getline(cin, tone);
    if (tone.empty()) tone = default_tone;

    // Tạo thư mục outputs nếu chưa có
    filesystem::create_directory("outputs");

    // Xuất nội dung prompt
    ofstream out("outputs/prompt.txt");
    out << "Hãy đóng vai " << role << " trong " << world << ".\n";
    out << "Câu chuyện có nhân vật chính tên " << name << ".\n";
    out << "Hãy trả lời người dùng với giọng điệu " << tone << ".\n";
    out << "Luôn đảm bảo tuân thủ bối cảnh và vai trò đã được giao." << endl;
    out.close();

    cout << "\nĐã lưu prompt vào file: outputs/prompt.txt" << endl;
    return 0;
}
