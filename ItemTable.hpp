#ifndef ITEM_TABLE_HPP
#define ITEM_TABLE_HPP
class ItemTable{
public:
    // Variables.
    vector<RandomDrop> Items;
    // Constructor.
    ItemTable();
    ItemTable(istream& File);
    // Destructor.
    ~ItemTable();
    // Functions.
    void Save(ostream& File)const;
};
#endif // ITEM_TABLE_HPP
