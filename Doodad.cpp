#include "Main.hpp"
Doodad::Doodad(){}
Doodad::Doodad(istream& File){
    File.read(Id,4u);
    File.read((char*)&Z,4u);
    File.read((char*)&X,4u);
    File.read((char*)&Y,4u);
}

Doodad::~Doodad(){}

void Doodad::Save(ostream& File)const{
    File.write(Id,4u);
    File.write((char*)&Z,4u);
    File.write((char*)&X,4u);
    File.write((char*)&Y,4u);
}
