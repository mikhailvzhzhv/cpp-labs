#include "commander.h"

using namespace converter;
using namespace commander;

int main(int argc, char** argv) {

    Commander r(argc, argv);
    r.run();

    return 0;
}