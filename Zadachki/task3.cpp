#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdint>

const std::string NO_DATA = "no data";

int main() {
  int n;
  std::cin >> n;

  std::map<std::string, std::map<uint64_t, std::string>> objects;
  std::map<std::string, std::map<uint64_t, std::set<std::string>>> locations;

  for (int i = 0; i < n; ++i) {
    std::string object, location;
    uint64_t timestamp;
    std::cin >> object >> location >> timestamp;

    objects[object][timestamp] = location;
    locations[location][timestamp].insert(object);
  }

  int m;
  std::cin >> m;

  for (int i = 0; i < m; ++i) {
    std::string type;
    std::cin >> type;

    if (type == "object") {
      std::string object;
      uint64_t timestamp;
      std::cin >> object >> timestamp;

      auto it = objects[object].upper_bound(timestamp);
      if (it != objects[object].begin()) {
        --it;
        std::cout << it->second << std::endl;
      } else {
        std::cout << NO_DATA << std::endl;
      }
    } else if (type == "location") {
      std::string location;
      uint64_t timestamp;
      std::cin >> location >> timestamp;

      auto it = locations[location].upper_bound(timestamp);
      if (it != locations[location].begin()) {
        --it;
        for (const auto& object : it->second) {
          std::cout << object << ' ';
        }
        std::cout << std::endl;
      } else {
        std::cout << NO_DATA << std::endl;
      }
    }
  }

  return 0;
}