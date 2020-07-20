//#include <vector>
//#include <list>
//#include <map>
//#include <set>
#include <iostream>
//#include "Logger.hpp"

int main() {
    //using std::runtime_error;
    //using Level = Logger::Level;
    //Logger logger("..\\log.txt");
    //logger.log(Level::INFO, "Rumspielen mit STL");
    //
    //using std::vector;
    //using std::list;
    //using std::set;
    //using std::map;
    //
    //// ---- Declaration ----------------------------------------------------------------
    //vector<int> vec1 {1, 2, 3};
    //list<int> list1 {4, 5, 6};
    //set<int> set1 {7, 8, 9};
    //map<const int, int> map1;
    //
    //// ---- Initializing ---------------------------------------------------------------
    //vec1.assign({10, 20, 30}); // initialize; overrides everything that was previously stored in vec1
    //list1.assign(5, 10); // initialize; put 5x 10.
    //std::map<const int, int>::iterator it;
    //for (int i = 1; i <= 30; i++) {
    //    if (i == 1) {
    //        map1.emplace(std::pair<const int, int>(i, i));
    //        it = map1.end();
    //    } else {
    //        it = map1.emplace_hint(it, std::pair<const int, int>(i, i));
    //    }
    //}
    //
    //// ---- Output ---------------------------------------------------------------------
    //std::cout << "Vektor:\n";
    //for (int& num : vec1) {
    //    std::cout << num << std::endl;
    //}
    //std::cout << std::endl;
    //
    //std::cout << "Liste:\n";
    //for (int& num : list1) {
    //    std::cout << num << std::endl;
    //}
    //std::cout << std::endl;
    //
    //std::cout << "Set (reverse):\n";
    //std::set<int>::reverse_iterator set_it;
    //for (set_it = set1.rbegin(); set_it != set1.rend(); set_it++) {
    //    std::cout << *set_it << std::endl;
    //}
    //std::cout << std::endl;
    ////for (const int& num : set1) {
    ////    std::cout << num << std::endl;
    ////}
    //
    //std::cout << "Map:\n";
    //map<const int, int>::iterator map_it;
    //for (map_it = map1.begin(); map_it != map1.end(); map_it++) {
    //    std::cout << "Key: " << map_it->first << ", Value: " << map_it->second << std::endl;
    //}
    //std::cout << std::endl;
    ////for (const std::pair<const int, int>& num : map1) {
    ////    std::cout << "Key: " << num.first << ", Value: " << num.second << std::endl;
    ////}
    
    // ---- Exception ------------------------------------------------------------------
    try {
        throw std::runtime_error("Fehlertext");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl; // Ausgabe: Fehlertext
    }
}