#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>

class Global
{
public:
    Global();
    //获取CPUID
    static void getCPUID(QString & cpuid);
};

#endif // GLOBAL_H
