#include "Main.hpp"
ItemTable::ItemTable(){}
ItemTable::ItemTable(istream& File){
    unsigned int Number=0u;
    File.read((char*)&Number,4u);
    Items.reserve(Number);
    while(Number--)Items.emplace_back(File);
}
// Destructor.
ItemTable::~ItemTable(){}
// Functions.
void ItemTable::Save(ostream& File)const{
    int Size=Items.size();
    File.write((char*)&Size,4u);
    for(const RandomDrop& Drop:Items)Drop.Save(File);
}
