class Rabbit{
  public:
    Rabbit();
    void print(ostream &out);
    void readFromUser();
    void readFromFile(ifstream &inFile);
    void makeInvalid();
  private:
    enum {MAX_CHAR_LEN=100};
    char name[MAX_CHAR_LEN];
    double maxWeight;
    int yearRecognized;
    bool isRare;
    bool isValid;
};