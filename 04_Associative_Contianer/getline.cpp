#include "getline.h"

string GetLine() {
    string response;
    std::getline(cin, response);
    return response;
}