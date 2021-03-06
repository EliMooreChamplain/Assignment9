//
//  test.cpp
//
//  Tests to prove your code works.
//  You SHOULD modify the end of this file, adding your own test case.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include "WeightedGraph.h"
#include "catch.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;
using namespace csi281;

template<typename T>
void printPath(list<T> &l) {
    for (auto &x : l) {
        if (x != l.back()) {
            cout << x << " -> ";
        } else {
            cout << x;
        }
    }
    cout << endl;
}

// DO NOT MODIFY THIS TEST CASE
TEST_CASE( "dijkstra() cityGraph1 Test", "[dijksta]" ) {
    WeightedGraph<string, int> cityGraph1 = WeightedGraph<string, int>();
    cityGraph1.addEdge("Seattle", "Chicago", 2097);
    cityGraph1.addEdge("Seattle", "Denver", 1331);
    cityGraph1.addEdge("Seattle", "San Francisco", 807);
    cityGraph1.addEdge("San Francisco", "Denver", 1267);
    cityGraph1.addEdge("San Francisco", "Los Angeles", 381);
    cityGraph1.addEdge("Los Angeles", "Denver", 1015);
    cityGraph1.addEdge("Los Angeles", "Kansas City", 1663);
    cityGraph1.addEdge("Los Angeles", "Dallas", 1435);
    cityGraph1.addEdge("Denver", "Chicago", 1003);
    cityGraph1.addEdge("Denver", "Kansas City", 599);
    cityGraph1.addEdge("Kansas City", "Chicago", 533);
    cityGraph1.addEdge("Kansas City", "New York", 1260);
    cityGraph1.addEdge("Kansas City", "Atlanta", 864);
    cityGraph1.addEdge("Kansas City", "Dallas", 496);
    cityGraph1.addEdge("Chicago", "Boston", 983);
    cityGraph1.addEdge("Chicago", "New York", 787);
    cityGraph1.addEdge("Boston", "New York", 214);
    cityGraph1.addEdge("Atlanta", "New York", 888);
    cityGraph1.addEdge("Atlanta", "Dallas", 781);
    cityGraph1.addEdge("Atlanta", "Houston", 810);
    cityGraph1.addEdge("Atlanta", "Miami", 661);
    cityGraph1.addEdge("Houston", "Miami", 1187);
    cityGraph1.addEdge("Houston", "Dallas", 239);
    cout << "------cityGraph1------" << endl;
    cityGraph1.debugPrint();
    auto resultPair = cityGraph1.dijkstra("New York");
    auto parentResults = resultPair.first;
    auto weightResults = resultPair.second;
    // are the distances from New York correct?
    CHECK( weightResults["San Francisco"] == 3057 );
    CHECK( weightResults["Los Angeles"] == 2805 );
    CHECK( weightResults["Seattle"] == 2884 );
    CHECK( weightResults["Denver"] == 1790 );
    CHECK( weightResults["Kansas City"] == 1260 );
    CHECK( weightResults["Chicago"] == 787 );
    CHECK( weightResults["Boston"] == 214 );
    CHECK( weightResults["Atlanta"] == 888 );
    CHECK( weightResults["Miami"] == 1549 );
    CHECK( weightResults["Dallas"] == 1669 );
    CHECK( weightResults["Houston"] == 1698 );
    CHECK( weightResults["San Francisco"] == 3057 );
    auto path = cityGraph1.pathMapToPath(parentResults, "San Francisco");
    cout << "------cityGraph1 path------" << endl;
    printPath(path);
    // Shortest path should be
    // New York -> Chicago -> Denver -> San Francisco
    CHECK( path.size() == 4 );
    CHECK( path.front() == "New York" );
    CHECK( path.back() == "San Francisco" );
    auto it = path.begin();
    auto last = path.front();
    for (unsigned long i = 1; i < path.size(); i++) {
        it++;
        auto current = *it;
        CHECK (cityGraph1.edgeExists(last, current));
        last = current;
    }
}

// DO NOT MODIFY THIS TEST CASE
TEST_CASE( "dijkstra() cityGraph2 Test", "[dijksta]" ) {
    WeightedGraph<string, int> cityGraph2 = WeightedGraph<string, int>();
    cityGraph2.addEdge("Seattle", "Chicago", 1737);
    cityGraph2.addEdge("Seattle", "San Francisco", 678);
    cityGraph2.addEdge("San Francisco", "Riverside", 386);
    cityGraph2.addEdge("San Francisco", "Los Angeles", 348);
    cityGraph2.addEdge("Los Angeles", "Riverside", 50);
    cityGraph2.addEdge("Los Angeles", "Phoenix", 357);
    cityGraph2.addEdge("Riverside", "Phoenix", 307);
    cityGraph2.addEdge("Riverside", "Chicago", 1704);
    cityGraph2.addEdge("Phoenix", "Dallas", 887);
    cityGraph2.addEdge("Phoenix", "Houston", 1015);
    cityGraph2.addEdge("Dallas", "Chicago", 805);
    cityGraph2.addEdge("Dallas", "Atlanta", 721);
    cityGraph2.addEdge("Dallas", "Houston", 225);
    cityGraph2.addEdge("Houston", "Atlanta", 702);
    cityGraph2.addEdge("Houston", "Miami", 968);
    cityGraph2.addEdge("Atlanta", "Chicago", 588);
    cityGraph2.addEdge("Atlanta", "Washington", 543);
    cityGraph2.addEdge("Atlanta", "Miami", 604);
    cityGraph2.addEdge("Miami", "Washington", 923);
    cityGraph2.addEdge("Chicago", "Detroit", 238);
    cityGraph2.addEdge("Detroit", "Boston", 613);
    cityGraph2.addEdge("Detroit", "Washington", 396);
    cityGraph2.addEdge("Detroit", "New York", 482);
    cityGraph2.addEdge("Boston", "New York", 190);
    cityGraph2.addEdge("New York", "Philadelphia", 81);
    cityGraph2.addEdge("Philadelphia", "Washington", 123);
    cout << "------cityGraph2------" << endl;
    cityGraph2.debugPrint();
    auto resultPair = cityGraph2.dijkstra("Miami");
    auto parentResults = resultPair.first;
    auto weightResults = resultPair.second;
    // are the distances from Miami correct?
    CHECK( weightResults["Seattle"] == 2929 );
    CHECK( weightResults["Chicago"] == 1192 );
    CHECK( weightResults["Atlanta"] == 604 );
    CHECK( weightResults["New York"] == 1127 );
    auto path = cityGraph2.pathMapToPath(parentResults, "San Francisco");
    cout << "------cityGraph2 path------" << endl;
    printPath(path);
    // Shortest path should be
    // Miami -> Houston -> Phoenix -> Riverside -> San Francisco
    CHECK( path.size() == 5 );
    CHECK( path.front() == "Miami" );
    CHECK( path.back() == "San Francisco" );
    auto it = path.begin();
    auto last = path.front();
    for (unsigned long i = 1; i < path.size(); i++) {
        it++;
        auto current = *it;
        CHECK (cityGraph2.edgeExists(last, current));
        last = current;
    }
}

TEST_CASE("dijkstra() cityGraph3 Test", "[dijksta]") {
    WeightedGraph<int, int> test3 = WeightedGraph<int, int>();
    test3.addEdge(1, 2, 29);
    test3.addEdge(1, 5, 34);
    test3.addEdge(1, 3, 48);
    test3.addEdge(2, 5, 10);
    test3.addEdge(3, 4, 14);
    test3.addEdge(4, 5, 12);
    test3.addEdge(5, 6, 15);
    test3.addEdge(6, 7, 10);
    test3.addEdge(7, 8, 25);
    test3.addEdge(5, 9, 52);
    test3.addEdge(9, 8, 5);
    test3.addEdge(8, 11, 9);
    test3.addEdge(10, 11, 20);
    test3.addEdge(4, 10, 18);
    test3.addEdge(10, 13, 10);
    test3.addEdge(3, 12, 20);
    test3.addEdge(12, 13, 15);
    test3.addEdge(10, 14, 13);
    test3.addEdge(5, 10, 10);
    test3.addEdge(14, 9, 9);

    auto resultPair = test3.dijkstra(3);

    auto parentResults = resultPair.first;
    auto weightResults = resultPair.second;

    CHECK(weightResults[8] == 59);
    CHECK(weightResults[11] == 52);
    CHECK(weightResults[6] == 41);
    CHECK(weightResults[14] == 45);

    auto path = test3.pathMapToPath(parentResults, 8);

    printPath(path);
    CHECK(path.size() == 6);
    CHECK(path.front() == 3);
    CHECK(path.back() == 8);

}
// ADD YOUR OWN TEST CASE
// Prove that dijkstra() works correctly in your own test case,
// using the methods of WeightedGraph.
// You should make up your own graph and test it. Do not
// reuse cityGraph or cityGraph2. Cite any sources.
// Make sure that your assertions are fairly comprehensive.
// Look at the prior two tests as examples.
