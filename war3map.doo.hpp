#ifndef WAR3MAP_DOO_HPP
#define WAR3MAP_DOO_HPP
class war3map_doo{
public:
    static constexpr char Id[4u]={'W','3','d','o'};
    static constexpr int RoC_Version=7;
    static constexpr char RoC_SubVersion[4u]={7,0,0,0};
    static constexpr int TFT_Version=8;
    static constexpr char TFT_SubVersion[4u]={0x0B,0,0,0};
    static constexpr int DoodadFormat=0;
    // Variables.
    bool FrozenThrone;
    vector<Destructable> Destructables;
    vector<Doodad> Doodads;
    // Constructor.
    war3map_doo(bool FrozenThrone=true);
    war3map_doo(istream& File);
    // Destructor.
    ~war3map_doo();
    // Functions.
    void Save(ostream& File)const;
};
#endif // WAR3MAP_DOO_HPP
