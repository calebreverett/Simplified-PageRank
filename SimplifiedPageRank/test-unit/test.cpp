#include<map>
#include "/Users/calebeverett/CLionProjects/SimplifiedPageRank/src/AdjacencyList.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Few Edges, one power iterator", "[unit]")
{
	AdjacencyList g;

	g.insertEdge("google.com", "gmail.com");
	g.insertEdge("google.com", "apple.com");
	g.insertEdge("ufl.edu", "gmail.com");
    g.insertEdge("apple.com", "apple.com");
    g.insertEdge("clubpenguin.com", "disney.com");
    g.insertEdge("disney.com", "clubpenguin.com");
    g.insertEdge("google.com", "clubpenguin.com");
    g.insertEdge("google.com", "disney.com");
    g.findOutdegrees();

	std::map<string, double> expected_map;
    expected_map["google.com"] = 0.17;
    expected_map["gmail.com"] = 0.17;
    expected_map["apple.com"] = 0.17;
    expected_map["ufl.edu"] = 0.17;
    expected_map["clubpenguin.com"] = 0.17;
    expected_map["disney.com"] = 0.17;
    std::map<string, double> actual_map = g.pageRank(1);

    REQUIRE(expected_map == actual_map);
    REQUIRE(1 == 1);
}

TEST_CASE("Many Edges, Few power iterators", "[unit]")
{
    AdjacencyList g;

    g.insertEdge("google.com", "gmail.com");
    g.insertEdge("google.com", "apple.com");
    g.insertEdge("ufl.edu", "gmail.com");
    g.insertEdge("apple.com", "apple.com");
    g.insertEdge("clubpenguin.com", "disney.com");
    g.insertEdge("disney.com", "clubpenguin.com");
    g.insertEdge("google.com", "clubpenguin.com");
    g.insertEdge("google.com", "disney.com");
    g.insertEdge("google.com", "youtube.com");
    g.insertEdge("twitch.tv", "amazon.com");
    g.insertEdge("amazon.com", "twitch.tv");
    g.insertEdge("google.com", "twitch.tv");
    g.insertEdge("disney.com", "disneyplus.com");
    g.insertEdge("disney.com", "hulu.com");
    g.insertEdge("google.com", "hulu.com");
    g.insertEdge("bing.com", "tmobile.com");
    g.insertEdge("google.com", "netflix.com");
    g.insertEdge("google.com", "hbomax.com");
    g.insertEdge("warnerbros.com", "hbomax.com");
    g.findOutdegrees();

    std::map<string, double> expected_map;
    expected_map["google.com"] = 0.00;//1
    expected_map["gmail.com"] = 0.00;//2
    expected_map["apple.com"] = 0.07;//3
    expected_map["ufl.edu"] = 0.00;//4
    expected_map["clubpenguin.com"] = 0.02;//5
    expected_map["disney.com"] = 0.03;//6
    expected_map["youtube.com"] = 0.00;//7
    expected_map["twitch.tv"] = 0.06;//8
    expected_map["amazon.com"] = 0.07;//9
    expected_map["disneyplus.com"] = 0.02;//10
    expected_map["hulu.com"] = 0.02;//11
    expected_map["bing.com"] = 0.00;//12
    expected_map["tmobile.com"] = 0.00;//13
    expected_map["netflix.com"] = 0.00;//14
    expected_map["warnerbros.com"] = 0.00;//15
    expected_map["hbomax.com"] = 0.00;//16
    std::map<string, double> actual_map = g.pageRank(3);

    REQUIRE(expected_map == actual_map);
    REQUIRE(1 == 1);
}

TEST_CASE("Many Edges, Many power iterators", "[unit]")
{
    AdjacencyList g;

    g.insertEdge("google.com", "gmail.com");
    g.insertEdge("google.com", "apple.com");
    g.insertEdge("ufl.edu", "gmail.com");
    g.insertEdge("apple.com", "apple.com");
    g.insertEdge("clubpenguin.com", "disney.com");
    g.insertEdge("disney.com", "clubpenguin.com");
    g.insertEdge("google.com", "clubpenguin.com");
    g.insertEdge("google.com", "disney.com");
    g.insertEdge("google.com", "youtube.com");
    g.insertEdge("twitch.tv", "amazon.com");
    g.insertEdge("amazon.com", "twitch.tv");
    g.insertEdge("google.com", "twitch.tv");
    g.insertEdge("disney.com", "disneyplus.com");
    g.insertEdge("disney.com", "hulu.com");
    g.insertEdge("google.com", "hulu.com");
    g.insertEdge("bing.com", "tmobile.com");
    g.insertEdge("google.com", "netflix.com");
    g.insertEdge("google.com", "hbomax.com");
    g.insertEdge("warnerbros.com", "hbomax.com");
    g.findOutdegrees();

    std::map<string, double> expected_map;
    expected_map["google.com"] = 0.00;//1
    expected_map["gmail.com"] = 0.00;//2
    expected_map["apple.com"] = 0.07;//3
    expected_map["ufl.edu"] = 0.00;//4
    expected_map["clubpenguin.com"] = 0.00;//5
    expected_map["disney.com"] = 0.00;//6
    expected_map["youtube.com"] = 0.00;//7
    expected_map["twitch.tv"] = 0.07;//8
    expected_map["amazon.com"] = 0.06;//9
    expected_map["disneyplus.com"] = 0.00;//10
    expected_map["hulu.com"] = 0.00;//11
    expected_map["bing.com"] = 0.00;//12
    expected_map["tmobile.com"] = 0.00;//13
    expected_map["netflix.com"] = 0.00;//14
    expected_map["warnerbros.com"] = 0.00;//15
    expected_map["hbomax.com"] = 0.00;//16
    std::map<string, double> actual_map = g.pageRank(50);

    REQUIRE(expected_map == actual_map);
    REQUIRE(1 == 1);
}

TEST_CASE("Many disconnected graphs", "[edge]")
{
    AdjacencyList g;

    g.insertEdge("google.com", "AOL.com");
    g.insertEdge("bing.com", "yahoo.com");
    g.insertEdge("duckduckgo.com", "youtube.com");
    g.insertEdge("vimeo.com", "facebook.com");
    g.insertEdge("stanford.edu", "yale.edu");
    g.insertEdge("wikipedia.com", "jstor.com");

    g.findOutdegrees();

    std::map<string, double> expected_map;
    expected_map["google.com"] = 0.00;//1
    expected_map["AOL.com"] = 0.00;//2
    expected_map["bing.com"] = 0.00;//3
    expected_map["stanford.edu"] = 0.00;//4
    expected_map["yahoo.com"] = 0.00;//5
    expected_map["yale.edu"] = 0.00;//6
    expected_map["wikipedia.com"] = 0.00;//7
    expected_map["jstor.com"] = 0.00;//8
    expected_map["vimeo.com"] = 0.00;//9
    expected_map["facebook.com"] = 0.00;//10
    expected_map["duckduckgo.com"] = 0.00;//11
    expected_map["youtube.com"] = 0.00;//12
    std::map<string, double> actual_map = g.pageRank(20);

    REQUIRE(expected_map == actual_map);
    REQUIRE(1 == 1);
}

TEST_CASE("Edge case: one website pointing to many, and itself", "[edge]")
{
    AdjacencyList g;

    g.insertEdge("google.com", "google.com");
    g.insertEdge("google.com", "gmail.com");
    g.insertEdge("google.com", "apple.com");
    g.insertEdge("google.com", "ufl.edu");
    g.insertEdge("google.com", "netflix.com");
    g.insertEdge("google.com", "maps.com");
    g.insertEdge("google.com", "amazon.com");
    g.insertEdge("google.com", "canvas.com");
    g.insertEdge("google.com", "gradescope.com");

    g.findOutdegrees();

    std::map<string, double> expected_map;
    expected_map["google.com"] = 0.00;//1
    expected_map["gmail.com"] = 0.00;//2
    expected_map["apple.com"] = 0.00;//3
    expected_map["ufl.edu"] = 0.00;//4
    expected_map["maps.com"] = 0.00;//5
    expected_map["canvas.com"] = 0.00;//6
    expected_map["gradescope.com"] = 0.00;//7
    expected_map["amazon.com"] = 0.00;//8
    expected_map["netflix.com"] = 0.00;//9
    std::map<string, double> actual_map = g.pageRank(20);

    REQUIRE(expected_map == actual_map);
    REQUIRE(1 == 1);
}