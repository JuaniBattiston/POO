#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> idioms;

    idioms.push_back("pan comido");
    idioms.push_back("mas vale tarde que nunca");
    idioms.push_back("esta lloviendo de abajo para arriba");
    idioms.push_back("cada loco con su tema");
    idioms.push_back("mejor prevenir que curar");

    sort(idioms.begin(), idioms.end());

    cout << "Expresiones idiomaticas ordenadas alfabaticamente" << endl;
    for (const auto& expresion : idioms) {
        cout << expresion << endl;
    }

    return 0;
}
