#include<bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
namespace fs = std::filesystem;
using namespace std;
char ctrl[99] = "0";
int main(int argc, char** argv) {
	cout << "/SPSAS:create/read/write/E" << endl;
	while (strcmp(ctrl, "E")) {
		cout << ">>";
		cin >> ctrl;
		if (strcmp(ctrl, "E") == 0) {
			return 0;
		} else if ((strcmp(ctrl, "create") == 0) || strcmp(ctrl, "C") == 0) {
	
		} else if ((strcmp(ctrl, "read") == 0) || strcmp(ctrl, "R") == 0) {
			system("cls");
			cout << "list:" << endl;
			string dirPath = "save";   // 相对于当前工作目录的 save 文件夹
			if (!fs::exists(dirPath) || !fs::is_directory(dirPath)) {
				std::cerr << "ERROR" << dirPath << std::endl;
				return 1;
			}
			for (const auto& entry : fs::directory_iterator(dirPath)) {
				if (!entry.is_regular_file()) continue;          // 只看普通文件
				if (entry.path().extension() == ".txt") {        // 扩展名是 .txt
					std::cout << entry.path().filename().string() << std::endl;
				}
			}
			char name[99] = "0";
			while (strcmp(name, "N")) {
				cout << ">>";
				cin >> name;
				if (strcmp(name, "N") == 0) {
					system("cls");
					cout << "/SPSAS:create/read/write/E" << endl;
					break;
				} else {
					ifstream fin(name);
					if (!fin.is_open()) {
						cerr << "ERROR" << endl;
						continue;
					}
					string line;
					if (!getline(fin, line)) {
						cerr << "ERROR" << std::endl;
						continue;
					}
					if (!line.empty() && line.back() == '\r') {
						line.pop_back();
					}
					int nuber = 0;
					istringstream iss(line);
					iss >> nuber;
					for (int i = 0; i < nuber; ++i) {
						if (!getline(fin, line)) {
							cerr << "ERROR" <<endl;
							break;
						}
						if (!line.empty() && line.back() == '\r') {
							line.pop_back();
						};
						for (size_t j = 0; j < line.size(); ++j) {
							char ch = line[j];
							//读
						}
					}
					fin.close();
				}
			}
		} else if ((strcmp(ctrl, "write") == 0) || strcmp(ctrl, "W") == 0) {
	
		}
	}
	return 0;
}
