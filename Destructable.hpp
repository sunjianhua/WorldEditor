#ifndef TREE_HPP
#define TREE_HPP
class Destructable{
    static int Ids;
public:
    // Variables.
    bool FrozenThrone;
    char ObjectId[4u];
    int Variation;
    float X;
    float Y;
    float Z;
    float Angle;
    float ScaleX;
    float ScaleY;
    float ScaleZ;
    char Flags;
    char Life;
    int ItemTablePtr;
    vector<ItemTable> ItemTables;
    int Id;
    // Constructor.
    Destructable(bool FrozenThrone=true);
    Destructable(bool FrozenThrone,istream& File);
    // Destructor.
    ~Destructable();
    // Functions.
    void Save(ostream& File)const;
};
#endif // TREE_HPP

