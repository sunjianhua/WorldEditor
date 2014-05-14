#ifndef DOODAD_HPP
#define DOODAD_HPP
class Doodad{
public:
    // Variables.
    char Id[4u];
    int Z;
    int X;
    int Y;
    // Constructor.
    Doodad();
    Doodad(istream& File);
    // Destructor.
    ~Doodad();
    // Functions.
    void Save(ostream& File)const;
};
#endif // DOODAD_HPP

