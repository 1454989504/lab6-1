#include "dwgobject.h"

DwgObject::DwgObject(QObject *parent)
    : QObject{parent}
{

}
// dwgobject.cpp
DwgObject::~DwgObject() {
    // 实现可以为空，但必须有这个函数体
}
