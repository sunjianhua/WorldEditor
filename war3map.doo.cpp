#include "Main.hpp"
constexpr char war3map_doo::Id[4u];
constexpr int war3map_doo::RoC_Version;
constexpr char war3map_doo::RoC_SubVersion[4u];
constexpr int war3map_doo::TFT_Version;
constexpr char war3map_doo::TFT_SubVersion[4u];
constexpr int war3map_doo::DoodadFormat;
war3map_doo::war3map_doo(bool FrozenThrone):FrozenThrone(FrozenThrone){}

war3map_doo::war3map_doo(istream& File){
    File.Skip(4);
    int Version;
    File.read((char*)&Version,4u);
    FrozenThrone=Version!=7;
    File.Skip(4);
    unsigned int Number=0;
    File.read((char*)&Number,4u);
    Destructables.reserve(Number);
    while(Number--)Destructables.emplace_back(FrozenThrone,File);
    File.Skip(4);
    File.read((char*)&Number,4u);
    Doodads.reserve(Number);
    while(Number--)Doodads.emplace_back(File);
}

war3map_doo::~war3map_doo(){}

void war3map_doo::Save(ostream& File)const{
    File.write(Id,4u);
    if(FrozenThrone){
        File.write((char*)&TFT_Version,4u);
        File.write((char*)&TFT_SubVersion,4u);
    }else{
        File.write((char*)&RoC_Version,4u);
        File.write((char*)&RoC_SubVersion,4u);
    }
    int Size=Destructables.size();
    File.write((char*)&Size,4u);
    for(const Destructable& Dest:Destructables)Dest.Save(File);
    File.write((char*)&DoodadFormat,4u);
    Size=Doodads.size();
    File.write((char*)&Size,4u);
    for(const Doodad& Dood:Doodads)Dood.Save(File);
}
