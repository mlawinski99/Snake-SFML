#include "Object.h"
Object::Object(string filename, string nazwa, int x, int y) {
    this->nazwa = nazwa;
    
    try 
    {
        regex r("[a-zA-Z0-9_]+");
        if (regex_match(filename.begin(), filename.end(), r))
            throw invalid_argument("Niepoprawna nazwa pliku!");
        if (!t.loadFromFile(filename))
            throw invalid_argument("Plik nie istnieje!");
        s.setTexture(t);
        s.setPosition(x, y);
        this->x = x;
        this->y = y;
    }
    catch (const exception & e)
    {
        cout << "Error! " << e.what() << endl;
    }
}
