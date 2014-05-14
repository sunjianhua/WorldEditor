#ifndef RANDOM_DROP_HPP
#define RANDOM_DROP_HPP
class RandomDrop{
public:
    // Variables.
    char Id[4u];
    int Chance;
    // Constructor.
    RandomDrop();
    RandomDrop(istream& File);
    // Destructor.
    ~RandomDrop();
    // Functions.
    void Save(ostream& File)const;
};
#endif // RANDOM_DROP_HPP
