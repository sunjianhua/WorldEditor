#include "Main.hpp"
RandomDrop::RandomDrop():Id{0,0,0,0},Chance(0){}
RandomDrop::RandomDrop(istream& File){
    File.read(Id,4u);
    File.read((char*)&Chance,4u);
}

RandomDrop::~RandomDrop(){}

void RandomDrop::Save(ostream& File)const{
    File.write(Id,4u);
    File.write((char*)&Chance,4u);
}
