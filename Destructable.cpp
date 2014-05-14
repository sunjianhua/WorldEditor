#include "Main.hpp"
int Destructable::Ids=0;
Destructable::Destructable(bool FrozenThrone):FrozenThrone(FrozenThrone),ObjectId{0,0,0,0},Variation(0),X(0),Y(0),Z(0),Angle(0),ScaleX(1),ScaleY(1),ScaleZ(1),Flags(0),Life(100),ItemTablePtr(-1),Id(0){}
Destructable::Destructable(bool FrozenThrone,istream& File):FrozenThrone(FrozenThrone),Id(Ids++){
    File.read(ObjectId,4u);
    File.read((char*)&Variation,4u);
    File.read((char*)&X,4u);
    File.read((char*)&Y,4u);
    File.read((char*)&Z,4u);
    File.read((char*)&Angle,4u);
    File.read((char*)&ScaleX,4u);
    File.read((char*)&ScaleY,4u);
    File.read((char*)&ScaleZ,4u);
    File.read(&Flags,1u);
    File.read(&Life,1u);
    File.read((char*)&ItemTablePtr,4u);
    unsigned int Sets=0;
    File.read((char*)&Sets,4u);
    ItemTables.reserve(Sets);
    while(Sets--)ItemTables.emplace_back(File);
    File.Skip(4);
}

Destructable::~Destructable(){}

void Destructable::Save(ostream& File)const{
    File.write(ObjectId,4u);
    File.write((char*)&Variation,4u);
    File.write((char*)&X,4u);
    File.write((char*)&Y,4u);
    File.write((char*)&Z,4u);
    File.write((char*)&Angle,4u);
    File.write((char*)&ScaleX,4u);
    File.write((char*)&ScaleY,4u);
    File.write((char*)&ScaleZ,4u);
    File.write(&Flags,1u);
    File.write(&Life,1u);
    File.write((char*)&ItemTablePtr,4u);
    int Size=ItemTables.size();
    File.write((char*)&Size,4u);
    for(const ItemTable& Table:ItemTables)Table.Save(File);
    File.write((char*)&Id,4u);
}
