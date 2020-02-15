#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void navigate_curr_dir(string path_name) {

	for (auto& entry : fs::directory_iterator(path_name)) {
		string p = entry.path().string();
		p = p.substr(p.find_last_of("/\\")+1, p.length());
		cout << path_name + "/" + p << endl;
		if(fs::is_directory(path_name + "/" + p))
			navigate_curr_dir(path_name + "/" + p);
	}
}

int main() {
	navigate_curr_dir("D:/temporary/root");
}
