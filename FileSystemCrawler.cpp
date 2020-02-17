#include <iostream>
#include <set>
#include <unordered_map>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void print_map(unordered_map<string, set<string>>& map) {
	unordered_map<string, set<string>>::iterator iterator = map.begin();
	while (iterator != map.end()) {
		auto pair_e = make_pair(iterator->first, iterator->second);
		cout << "{" << pair_e.first << ": ";
		set<string>::iterator pos;
		int counter = 0;
		for (pos = pair_e.second.begin(); pos != pair_e.second.end(); pos++) {
			if (counter != pair_e.second.size() - 1) {
				cout << *pos << ", ";
				counter++;
			}
			else {
				cout << *pos << "}" << endl;
			}
		}
		iterator++;
	}
}

void navigate_curr_dir(string path_name, unordered_map<string, set<string>> &map) {
	for (auto& entry : fs::directory_iterator(path_name)) {
		string dir_file_name = entry.path().string();
		string parent = path_name.substr(path_name.find_last_of("/") + 1, path_name.length());
		dir_file_name = dir_file_name.substr(dir_file_name.find_last_of("/\\") + 1, dir_file_name.length());
		if (map.find(dir_file_name) == map.end()) {
			set<string> parents_list;
			parents_list.insert(parent);
			map.insert(make_pair(dir_file_name, parents_list));
		}
		else {
			map[dir_file_name].insert(parent);
		}
		if (fs::is_directory(path_name + "/" + dir_file_name)) {
			navigate_curr_dir(path_name + "/" + dir_file_name, map);
		}
	}
}

int main() {
	unordered_map<string, set<string>> file_system_index;
	navigate_curr_dir("D:/temporary/root", file_system_index);
	print_map(file_system_index);
}
