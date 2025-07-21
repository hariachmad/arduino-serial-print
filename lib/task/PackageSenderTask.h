#include "Package.h"

class PackageSenderTask{
    public:
        static void sendPackage(StaticJsonDocument<200> package);
};