#include "Log.h"

void Log::LogToFile(Single_Player*& single, Multiplayer*& multi)
{
    ofstream file;
    /*file.open("log.txt");
    file.close();*/
    file.open("log.txt", ios_base::app);
    if (!file)
        cout << "Nie uda³o siê otworzyæ pliku!" << endl;
    if (single != nullptr)
    {
        file << "single";
        file << " ";
        file << single->get_snake()->get_counter();
        file << "\n";
    }
    else if (multi != nullptr)
    {
        file << "multi";
        file << " ";
        file << multi->get_snake1()->get_counter();
        file << " ";
        file << multi->get_snake2()->get_counter();
        file << "\n";
    }
    file.close();
}