#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ticket.h"
#include <sstream>

// Helper: captureOutput
// buyTicket(...) returns a std::string. Tests below expect the printed
// output (line with trailing newline). captureOutput wraps the return
// value and appends a '\n' so tests can compare against expected lines.
static std::string captureOutput(int money, int tickets) {
    std::string res = buyTicket(money, tickets);
    return res + "\n";
}

// Test cases
TEST_CASE("Test buyTicket function", "[buyTicket]") {
    
    SECTION("Invalid money - too low") {
        REQUIRE(buyTicket(500, 2) == "Số tiền không hợp lệ");
    }
    
    SECTION("Invalid money - too high") {
        REQUIRE(buyTicket(150000, 1) == "Số tiền không hợp lệ");
    }
    
    SECTION("Invalid tickets - too few") {
        REQUIRE(buyTicket(50000, 0) == "Số lượng vé không hợp lệ");
    }
    
    SECTION("Invalid tickets - too many") {
        REQUIRE(buyTicket(20000, 6) == "Số lượng vé không hợp lệ");
    }
    
    SECTION("Not enough money") {
        REQUIRE(buyTicket(10000, 1) == "Không đủ tiền");
        REQUIRE(buyTicket(30000, 2) == "Không đủ tiền");
    }
    
    SECTION("Exact money") {
        REQUIRE(buyTicket(100000, 3).find("trả lại") != std::string::npos);
    }

    SECTION("Enough money") {
        REQUIRE(buyTicket(60000, 3).find("trả lại") == std::string::npos);
    }
}


TEST_CASE("buyTicket - all-uses detailed (15 DU-pair tests)") {

    // ---- money ----
    SECTION("DU money (0,1(T)) money < 1000 (p-use at node 1 True)") {
        // def-clear: 0 -> 1(T)
        REQUIRE(captureOutput(500, 2) == "Số tiền không hợp lệ\n");
    }

    SECTION("DU money (0,1(F)) money valid (p-use at node 1 False)") {
        // def-clear: 0 -> 1(F)
        // use input that proceeds: choose money valid and go to in-vé path (example)
        REQUIRE(captureOutput(40000, 2) == "In 2 vé thành công\n");
    }

    SECTION("DU money (0,6(T)) money < totalCost (p-use at node 6 True)") {
        // def-clear: 0 -> 1(F) -> 3(F) -> 5 -> 6(T)
        REQUIRE(captureOutput(30000, 2) == "Không đủ tiền\n");
    }

    SECTION("DU money (0,6(F)) money >= totalCost (p-use at node 6 False)") {
        // def-clear: 0 -> 1(F) -> 3(F) -> 5 -> 6(F)
        REQUIRE(captureOutput(40000, 2) == "In 2 vé thành công\n");
    }

    SECTION("DU money (0,9(T)) money used in change calculation (c-use at node 9)") {
        // def-clear: 0 -> 1(F) -> 3(F) -> 5 -> 6(F) -> 8 -> 9
        REQUIRE(captureOutput(50000, 2) == "In 2 vé thành công, trả lại 10000 VND\n");
    }

    // ---- tickets ----
    SECTION("DU tickets (0,3(T)) tickets < 1 (p-use at node 3 True)") {
        // def-clear: 0 -> 1(F) -> 3(T)
        REQUIRE(captureOutput(20000, 0) == "Số lượng vé không hợp lệ\n");
    }

    SECTION("DU tickets (0,3(F)) tickets valid (p-use at node 3 False)") {
        // def-clear: 0 -> 1(F) -> 3(F)
        REQUIRE(captureOutput(30000, 2) == "Không đủ tiền\n");
    }

    SECTION("DU tickets (0,5) tickets used to compute totalCost (c-use at node 5)") {
        // def-clear: 0 -> 1(F) -> 3(F) -> 5
        REQUIRE(captureOutput(30000, 2) == "Không đủ tiền\n");
    }

    SECTION("DU tickets (0,8) tickets used when printing (c-use at node 8)") {
        // def-clear: 0 -> 1(F) -> 3(F) -> 5 -> 6(F) -> 8
        REQUIRE(captureOutput(40000, 2) == "In 2 vé thành công\n");
    }

    // ---- totalCost ----
    SECTION("DU totalCost (5,6(T)) totalCost used at condition and money < totalCost") {
        // def-clear: 0 -> 1(F) -> 3(F) -> 5 -> 6(T)
        REQUIRE(captureOutput(30000, 2) == "Không đủ tiền\n");
    }

    SECTION("DU totalCost (5,6(F)) totalCost used at condition and money >= totalCost") {
        // def-clear: 0 -> 1(F) -> 3(F) -> 5 -> 6(F)
        REQUIRE(captureOutput(40000, 2) == "In 2 vé thành công\n");
    }

    SECTION("DU totalCost (5,9) totalCost used to compute change (c-use at node 9)") {
        // def-clear: 0 -> 1(F) -> 3(F) -> 5 -> 6(F) -> 8 -> 9
        REQUIRE(captureOutput(50000, 2) == "In 2 vé thành công, trả lại 10000 VND\n");
    }

    // ---- change ----
    SECTION("DU change (9,10(T)) change>0 predicate True") {
        // def-clear: 0 -> ... -> 9 -> 10(T)
        REQUIRE(captureOutput(50000, 2) == "In 2 vé thành công, trả lại 10000 VND\n");
    }

    SECTION("DU change (9,10(F)) change>0 predicate False (change == 0)") {
        // def-clear: 0 -> ... -> 9 -> 10(F)
        REQUIRE(captureOutput(40000, 2) == "In 2 vé thành công\n");
    }

    SECTION("DU change (9,11) change used when printing returned money (c-use at node 11)") {
        // def-clear: 0 -> ... -> 9 -> 10(T) -> 11
        REQUIRE(captureOutput(50000, 2) == "In 2 vé thành công, trả lại 10000 VND\n");
    }
}

