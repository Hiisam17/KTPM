#include <iostream>
#include <string>
#include "ticket.h"
using namespace std;

string buyTicket(int money, int tickets) {
    if (money < 1000 || money > 100000) { 
        return "Số tiền không hợp lệ";
    }
    if (tickets < 1 || tickets > 5) {
        return "Số lượng vé không hợp lệ";
    }

    int totalCost = tickets * 20000;

    if (money < totalCost) {
        return "Không đủ tiền";
    } else {
        string result = "In " + to_string(tickets) + " vé thành công";
        int change = money - totalCost;
        if (change > 0)
            result += ", trả lại " + to_string(change) + " VND";
        return result;
    }
}
